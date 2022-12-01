#include <iostream>
#include <format>
#include <sstream>
#include "LNet.hpp"
#include <json/json.hpp>

#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <iostream>



using std::to_string;
void Post(const char*  url, const char* message) {
	boost::asio::io_service io_service;

	boost::asio::ip::tcp::resolver resolver(io_service);
	boost::asio::ip::tcp::resolver::query query(url, "https");

	boost::asio::ip::tcp::socket socket(io_service);
	boost::asio::connect(socket, resolver.resolve(query));

	boost::beast::http::request<boost::beast::http::string_body> req(
		boost::beast::http::verb::post, "", 11);
	req.set(boost::beast::http::field::host, url);
	req.set(boost::beast::http::field::user_agent, "MyAgent/1");
	req.set(boost::beast::http::field::connection, "Close");
	nlohmann::json content;
	content["content"] = message;
	req.insert("payload_json",to_string(content));
	write(socket, req);

	boost::beast::flat_buffer buffer;
	boost::beast::http::response<boost::beast::http::string_body> reply;
	boost::beast::http::read(socket, buffer, reply);
	std::cout << reply.body();
}

void Post1F(const char* url, const char* message, const char* filename1, const char* file1) {
	

}


void Post2F(const char* url, const char* message, const char* filename1, const char* file1, const char* filename2, const char* file2) {
	/*CURL* curl;
	CURLcode res;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
		struct curl_slist* headers = NULL;
		headers = curl_slist_append(headers, "Cookie: __dcfduid=7f487c466e4a11ed9da33e36ca907468; __sdcfduid=7f487c466e4a11ed9da33e36ca907468c5149a615b407e839ec8c7e12a94350d9751cd1152c5bd259ae6d6af6cf2e54c");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_mime* mime;
		curl_mimepart* part;
		mime = curl_mime_init(curl);
		part = curl_mime_addpart(mime);
		curl_mime_name(part, "payload_json");
		nlohmann::json content;
		content["content"] = message;
		curl_mime_data(part, to_string(content).c_str(), CURL_ZERO_TERMINATED);
		part = curl_mime_addpart(mime);
		curl_mime_name(part, filename1);
		curl_mime_filedata(part, file1);
		part = curl_mime_addpart(mime);
		curl_mime_name(part, filename2);
		curl_mime_filedata(part, file2);
		curl_easy_setopt(curl, CURLOPT_MIMEPOST, mime);
		res = curl_easy_perform(curl);
		curl_mime_free(mime);
	}
	curl_easy_cleanup(curl);*/

}