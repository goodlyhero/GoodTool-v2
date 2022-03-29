#include <map>
#include <vector>
#include <Functions.h>
struct data_to_restore
{
    DWORD addr;
    std::vector<std::byte> orig;
    size_t len;
};

class mem_restorer
{
public:
    std::map<DWORD,data_to_restore*> torest;
    void add(DWORD addr, size_t len)
    {
        data_to_restore* base = new data_to_restore;
        base->len = len;
        base->addr = addr;
        for (size_t i = 0; i < len;i++)
        {
            base->orig.push_back(*(std::byte*)addr);
            addr++;
        }
        torest[addr] = base;
    }
    void restore(DWORD addr)
    {
        auto tree = torest.find(addr);
        if (tree != torest.end())
        {
            auto var = torest[addr];
            size_t len = var->len;
            for (size_t i = 0; i < len;i++)
            {
                ((std::byte*)(var->addr))[i] = var->orig[i];
            }
            /*static FILE* test = std::fopen("Test.txt","w");
            fprintf(test, "%x\n", (unsigned int)var->addr);
            fflush(test);*/
            delete var;
            torest.erase(addr);
        }
    }
    ~mem_restorer()
    {
        for (auto var:torest)
        {
            size_t len = var.second->len;
            for (size_t i = 0; i < len;i++)
            {
                ((std::byte*)(var.second->addr))[i] = var.second->orig[i];
            }
            /*static FILE* test = std::fopen("Test.txt","w");
            fprintf(test, "%x\n", (unsigned int)var->addr);
            fflush(test);*/
            delete var.second;
        }
    }
};
mem_restorer restorer;

void PatchSecure(DWORD addr, const char* data, size_t len)
{
    restorer.add(addr, len);
    Patch(addr, data, len);
}

void WriteIntSave(DWORD dest, int what)
{
    DWORD dwOldProtection = NULL;
    VirtualProtect((LPVOID)dest, 4, PAGE_EXECUTE_READWRITE, &dwOldProtection);
    restorer.add(dest, 4);
    *(int*)dest = what;
    VirtualProtect((LPVOID)dest, 4, dwOldProtection, NULL);
    return;
}

void WriteDWORDSave(DWORD dest, DWORD what)
{
    DWORD dwOldProtection = NULL;
    VirtualProtect((LPVOID)dest, 4, PAGE_EXECUTE_READWRITE, &dwOldProtection);
    restorer.add(dest, 4);
    *(DWORD*)dest = what;
    VirtualProtect((LPVOID)dest, 4, dwOldProtection, NULL);
    return;
}