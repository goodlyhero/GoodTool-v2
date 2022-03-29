export module JassCommonConsts;

typedef unsigned int DWORD;

export DWORD            PLAYER_NEUTRAL_PASSIVE = 15;
export DWORD            PLAYER_NEUTRAL_AGGRESSIVE = 12;

export DWORD        PLAYER_COLOR_RED = 0;
export DWORD        PLAYER_COLOR_BLUE = 1;
export DWORD        PLAYER_COLOR_CYAN = 2;
export DWORD        PLAYER_COLOR_PURPLE = 3;
export DWORD        PLAYER_COLOR_YELLOW = 4;
export DWORD        PLAYER_COLOR_ORANGE = 5;
export DWORD        PLAYER_COLOR_GREEN = 6;
export DWORD        PLAYER_COLOR_PINK = 7;
export DWORD        PLAYER_COLOR_LIGHT_GRAY = 8;
export DWORD        PLAYER_COLOR_LIGHT_BLUE = 9;
export DWORD        PLAYER_COLOR_AQUA = 10;
export DWORD        PLAYER_COLOR_BROWN = 11;

export DWORD               RACE_HUMAN = 1;
export DWORD               RACE_ORC = 2;
export DWORD               RACE_UNDEAD = 3;
export DWORD               RACE_NIGHTELF = 4;
export DWORD               RACE_DEMON = 5;
export DWORD               RACE_OTHER = 7;

export DWORD   PLAYER_GAME_RESULT_VICTORY = 0;
export DWORD   PLAYER_GAME_RESULT_DEFEAT = 1;
export DWORD   PLAYER_GAME_RESULT_TIE = 2;
export DWORD   PLAYER_GAME_RESULT_NEUTRAL = 3;

export DWORD       ALLIANCE_PASSIVE = 0;
export DWORD       ALLIANCE_HELP_REQUEST = 1;
export DWORD       ALLIANCE_HELP_RESPONSE = 2;
export DWORD       ALLIANCE_SHARED_XP = 3;
export DWORD       ALLIANCE_SHARED_SPELLS = 4;
export DWORD       ALLIANCE_SHARED_VISION = 5;
export DWORD       ALLIANCE_SHARED_CONTROL = 6;
export DWORD       ALLIANCE_SHARED_ADVANCED_CONTROL = 7;
export DWORD       ALLIANCE_RESCUABLE = 8;
export DWORD       ALLIANCE_SHARED_VISION_FORCED = 9;

export DWORD            VERSION_REIGN_OF_CHAOS = 0;
export DWORD            VERSION_FROZEN_THRONE = 1;

//===================================================
// Map Setup export DWORD    
//===================================================

export DWORD     RACE_PREF_HUMAN = 1;
export DWORD     RACE_PREF_ORC = 2;
export DWORD     RACE_PREF_NIGHTELF = 4;
export DWORD     RACE_PREF_UNDEAD = 8;
export DWORD     RACE_PREF_DEMON = 16;
export DWORD     RACE_PREF_RANDOM = 32;
export DWORD     RACE_PREF_USER_SELECTABLE = 64;

export DWORD         MAP_CONTROL_USER = 0;
export DWORD         MAP_CONTROL_COMPUTER = 1;
export DWORD         MAP_CONTROL_RESCUABLE = 2;
export DWORD         MAP_CONTROL_NEUTRAL = 3;
export DWORD         MAP_CONTROL_CREEP = 4;
export DWORD         MAP_CONTROL_NONE = 5;

export DWORD           GAME_TYPE_MELEE = 1;
export DWORD           GAME_TYPE_FFA = 2;
export DWORD           GAME_TYPE_USE_MAP_SETTINGS = 4;
export DWORD           GAME_TYPE_BLIZ = 8;
export DWORD           GAME_TYPE_ONE_ON_ONE = 16;
export DWORD           GAME_TYPE_TWO_TEAM_PLAY = 32;
export DWORD           GAME_TYPE_THREE_TEAM_PLAY = 64;
export DWORD           GAME_TYPE_FOUR_TEAM_PLAY = 128;

export DWORD            MAP_FOG_HIDE_TERRAIN = 1;
export DWORD            MAP_FOG_MAP_EXPLORED = 2;
export DWORD            MAP_FOG_ALWAYS_VISIBLE = 4;

export DWORD            MAP_USE_HANDICAPS = 8;
export DWORD            MAP_OBSERVERS = 16;
export DWORD            MAP_OBSERVERS_ON_DEATH = 32;

export DWORD            MAP_FIXED_COLORS = 128;

export DWORD            MAP_LOCK_RESOURCE_TRADING = 256;
export DWORD            MAP_RESOURCE_TRADING_ALLIES_ONLY = 512;

export DWORD            MAP_LOCK_ALLIANCE_CHANGES = 1024;
export DWORD            MAP_ALLIANCE_CHANGES_HIDDEN = 2048;

export DWORD            MAP_CHEATS = 4096;
export DWORD            MAP_CHEATS_HIDDEN = 8192;

export DWORD            MAP_LOCK_SPEED = 8192 * 2;
export DWORD            MAP_LOCK_RANDOM_SEED = 8192 * 4;
export DWORD            MAP_SHARED_ADVANCED_CONTROL = 8192 * 8;
export DWORD            MAP_RANDOM_HERO = 8192 * 16;
export DWORD            MAP_RANDOM_RACES = 8192 * 32;
export DWORD            MAP_RELOADED = 8192 * 64;

export DWORD          MAP_PLACEMENT_RANDOM = 0;   // random among all slots
export DWORD          MAP_PLACEMENT_FIXED = 1;   // player 0 in start loc 0...
export DWORD          MAP_PLACEMENT_USE_MAP_SETTINGS = 2;   // whatever was specified by the script
export DWORD          MAP_PLACEMENT_TEAMS_TOGETHER = 3;   // random with allies next to each other    

export DWORD       MAP_LOC_PRIO_LOW = 0;
export DWORD       MAP_LOC_PRIO_HIGH = 1;
export DWORD       MAP_LOC_PRIO_NOT = 2;

export DWORD         MAP_DENSITY_NONE = 0;
export DWORD         MAP_DENSITY_LIGHT = 1;
export DWORD         MAP_DENSITY_MEDIUM = 2;
export DWORD         MAP_DENSITY_HEAVY = 3;

export DWORD     MAP_DIFFICULTY_EASY = 0;
export DWORD     MAP_DIFFICULTY_NORMAL = 1;
export DWORD     MAP_DIFFICULTY_HARD = 2;
export DWORD     MAP_DIFFICULTY_INSANE = 3;

export DWORD          MAP_SPEED_SLOWEST = 0;
export DWORD          MAP_SPEED_SLOW = 1;
export DWORD          MAP_SPEED_NORMAL = 2;
export DWORD          MAP_SPEED_FAST = 3;
export DWORD          MAP_SPEED_FASTEST = 4;

export DWORD    PLAYER_SLOT_STATE_EMPTY = 0;
export DWORD    PLAYER_SLOT_STATE_PLAYING = 1;
export DWORD    PLAYER_SLOT_STATE_LEFT = 2;

//===================================================
// Sound export DWORD
//===================================================
export DWORD        SOUND_VOLUMEGROUP_UNITMOVEMENT = 0;
export DWORD        SOUND_VOLUMEGROUP_UNITSOUNDS = 1;
export DWORD        SOUND_VOLUMEGROUP_COMBAT = 2;
export DWORD        SOUND_VOLUMEGROUP_SPELLS = 3;
export DWORD        SOUND_VOLUMEGROUP_UI = 4;
export DWORD        SOUND_VOLUMEGROUP_MUSIC = 5;
export DWORD        SOUND_VOLUMEGROUP_AMBIENTSOUNDS = 6;
export DWORD        SOUND_VOLUMEGROUP_FIRE = 7;


//===================================================
// Game, Player, and Unit States
//
// For use with TriggerRegister<X>StateEvent
//
//===================================================

export DWORD GAME_STATE_DIVINE_INTERVENTION = 0;
export DWORD GAME_STATE_DISCONNECTED = 1;
export DWORD GAME_STATE_TIME_OF_DAY = 2;

export DWORD PLAYER_STATE_GAME_RESULT = 0;

// current resource levels
//
export DWORD PLAYER_STATE_RESOURCE_GOLD = 1;
export DWORD PLAYER_STATE_RESOURCE_LUMBER = 2;
export DWORD PLAYER_STATE_RESOURCE_HERO_TOKENS = 3;
export DWORD PLAYER_STATE_RESOURCE_FOOD_CAP = 4;
export DWORD PLAYER_STATE_RESOURCE_FOOD_USED = 5;
export DWORD PLAYER_STATE_FOOD_CAP_CEILING = 6;

export DWORD PLAYER_STATE_GIVES_BOUNTY = 7;
export DWORD PLAYER_STATE_ALLIED_VICTORY = 8;
export DWORD PLAYER_STATE_PLACED = 9;
export DWORD PLAYER_STATE_OBSERVER_ON_DEATH = 10;
export DWORD PLAYER_STATE_OBSERVER = 11;
export DWORD PLAYER_STATE_UNFOLLOWABLE = 12;

// taxation rate for each resource
//
export DWORD PLAYER_STATE_GOLD_UPKEEP_RATE = 13;
export DWORD PLAYER_STATE_LUMBER_UPKEEP_RATE = 14;

// cumulative resources collected by the player during the mission
//
export DWORD PLAYER_STATE_GOLD_GATHERED = 15;
export DWORD PLAYER_STATE_LUMBER_GATHERED = 16;

export DWORD PLAYER_STATE_NO_CREEP_SLEEP = 25;

export DWORD UNIT_STATE_LIFE = 0;
export DWORD UNIT_STATE_MAX_LIFE = 1;
export DWORD UNIT_STATE_MANA = 2;
export DWORD UNIT_STATE_MAX_MANA = 3;

export DWORD AI_DIFFICULTY_NEWBIE = 0;
export DWORD AI_DIFFICULTY_NORMAL = 1;
export DWORD AI_DIFFICULTY_INSANE = 2;

//===================================================
// Game, Player and Unit Events
//
//  When an event causes a trigger to fire these
//  values allow the action code to determine which
//  event was dispatched and therefore which set of
//  native functions should be used to get information
//  about the event.
//
// Do NOT change the order or value of these export DWORD
// without insuring that the JASS_GAME_EVENTS_WAR3 enum
// is changed to match.
//
//===================================================

    //===================================================
    // For use with TriggerRegisterGameEvent    
    //===================================================    

export DWORD EVENT_GAME_VICTORY = 0;
export DWORD EVENT_GAME_END_LEVEL = 1;

export DWORD EVENT_GAME_VARIABLE_LIMIT = 2;
export DWORD EVENT_GAME_STATE_LIMIT = 3;

export DWORD EVENT_GAME_TIMER_EXPIRED = 4;

export DWORD EVENT_GAME_ENTER_REGION = 5;
export DWORD EVENT_GAME_LEAVE_REGION = 6;

export DWORD EVENT_GAME_TRACKABLE_HIT = 7;
export DWORD EVENT_GAME_TRACKABLE_TRACK = 8;

export DWORD EVENT_GAME_SHOW_SKILL = 9;
export DWORD EVENT_GAME_BUILD_SUBMENU = 10;

//===================================================
// For use with TriggerRegisterPlayerEvent
//===================================================
export DWORD EVENT_PLAYER_STATE_LIMIT = 11;
export DWORD EVENT_PLAYER_ALLIANCE_CHANGED = 12;

export DWORD EVENT_PLAYER_DEFEAT = 13;
export DWORD EVENT_PLAYER_VICTORY = 14;
export DWORD EVENT_PLAYER_LEAVE = 15;
export DWORD EVENT_PLAYER_CHAT = 16;
export DWORD EVENT_PLAYER_END_CINEMATIC = 17;

//===================================================
// For use with TriggerRegisterPlayerUnitEvent
//===================================================

export DWORD EVENT_PLAYER_UNIT_ATTACKED = 18;
export DWORD EVENT_PLAYER_UNIT_RESCUED = 19;

export DWORD EVENT_PLAYER_UNIT_DEATH = 20;
export DWORD EVENT_PLAYER_UNIT_DECAY = 21;

export DWORD EVENT_PLAYER_UNIT_DETECTED = 22;
export DWORD EVENT_PLAYER_UNIT_HIDDEN = 23;

export DWORD EVENT_PLAYER_UNIT_SELECTED = 24;
export DWORD EVENT_PLAYER_UNIT_DESELECTED = 25;

export DWORD EVENT_PLAYER_UNIT_CONSTRUCT_START = 26;
export DWORD EVENT_PLAYER_UNIT_CONSTRUCT_CANCEL = 27;
export DWORD EVENT_PLAYER_UNIT_CONSTRUCT_FINISH = 28;

export DWORD EVENT_PLAYER_UNIT_UPGRADE_START = 29;
export DWORD EVENT_PLAYER_UNIT_UPGRADE_CANCEL = 30;
export DWORD EVENT_PLAYER_UNIT_UPGRADE_FINISH = 31;

export DWORD EVENT_PLAYER_UNIT_TRAIN_START = 32;
export DWORD EVENT_PLAYER_UNIT_TRAIN_CANCEL = 33;
export DWORD EVENT_PLAYER_UNIT_TRAIN_FINISH = 34;

export DWORD EVENT_PLAYER_UNIT_RESEARCH_START = 35;
export DWORD EVENT_PLAYER_UNIT_RESEARCH_CANCEL = 36;
export DWORD EVENT_PLAYER_UNIT_RESEARCH_FINISH = 37;
export DWORD EVENT_PLAYER_UNIT_ISSUED_ORDER = 38;
export DWORD EVENT_PLAYER_UNIT_ISSUED_POINT_ORDER = 39;
export DWORD EVENT_PLAYER_UNIT_ISSUED_TARGET_ORDER = 40;
export DWORD EVENT_PLAYER_UNIT_ISSUED_UNIT_ORDER = 40;    // for compat

export DWORD EVENT_PLAYER_HERO_LEVEL = 41;
export DWORD EVENT_PLAYER_HERO_SKILL = 42;

export DWORD EVENT_PLAYER_HERO_REVIVABLE = 43;

export DWORD EVENT_PLAYER_HERO_REVIVE_START = 44;
export DWORD EVENT_PLAYER_HERO_REVIVE_CANCEL = 45;
export DWORD EVENT_PLAYER_HERO_REVIVE_FINISH = 46;
export DWORD EVENT_PLAYER_UNIT_SUMMON = 47;
export DWORD EVENT_PLAYER_UNIT_DROP_ITEM = 48;
export DWORD EVENT_PLAYER_UNIT_PICKUP_ITEM = 49;
export DWORD EVENT_PLAYER_UNIT_USE_ITEM = 50;

export DWORD EVENT_PLAYER_UNIT_LOADED = 51;

//===================================================
// For use with TriggerRegisterUnitEvent
//===================================================

export DWORD EVENT_UNIT_DAMAGED = 52;
export DWORD EVENT_UNIT_DEATH = 53;
export DWORD EVENT_UNIT_DECAY = 54;
export DWORD EVENT_UNIT_DETECTED = 55;
export DWORD EVENT_UNIT_HIDDEN = 56;
export DWORD EVENT_UNIT_SELECTED = 57;
export DWORD EVENT_UNIT_DESELECTED = 58;

export DWORD EVENT_UNIT_STATE_LIMIT = 59;

// Events which may have a filter for the "other unit"              
//                                                                  
export DWORD EVENT_UNIT_ACQUIRED_TARGET = 60;
export DWORD EVENT_UNIT_TARGET_IN_RANGE = 61;
export DWORD EVENT_UNIT_ATTACKED = 62;
export DWORD EVENT_UNIT_RESCUED = 63;

export DWORD EVENT_UNIT_CONSTRUCT_CANCEL = 64;
export DWORD EVENT_UNIT_CONSTRUCT_FINISH = 65;

export DWORD EVENT_UNIT_UPGRADE_START = 66;
export DWORD EVENT_UNIT_UPGRADE_CANCEL = 67;
export DWORD EVENT_UNIT_UPGRADE_FINISH = 68;

// Events which involve the specified unit performing               
// training of other units                                          
//                                                                  
export DWORD EVENT_UNIT_TRAIN_START = 69;
export DWORD EVENT_UNIT_TRAIN_CANCEL = 70;
export DWORD EVENT_UNIT_TRAIN_FINISH = 71;

export DWORD EVENT_UNIT_RESEARCH_START = 72;
export DWORD EVENT_UNIT_RESEARCH_CANCEL = 73;
export DWORD EVENT_UNIT_RESEARCH_FINISH = 74;

export DWORD EVENT_UNIT_ISSUED_ORDER = 75;
export DWORD EVENT_UNIT_ISSUED_POINT_ORDER = 76;
export DWORD EVENT_UNIT_ISSUED_TARGET_ORDER = 77;

export DWORD EVENT_UNIT_HERO_LEVEL = 78;
export DWORD EVENT_UNIT_HERO_SKILL = 79;

export DWORD EVENT_UNIT_HERO_REVIVABLE = 80;
export DWORD EVENT_UNIT_HERO_REVIVE_START = 81;
export DWORD EVENT_UNIT_HERO_REVIVE_CANCEL = 82;
export DWORD EVENT_UNIT_HERO_REVIVE_FINISH = 83;

export DWORD EVENT_UNIT_SUMMON = 84;

export DWORD EVENT_UNIT_DROP_ITEM = 85;
export DWORD EVENT_UNIT_PICKUP_ITEM = 86;
export DWORD EVENT_UNIT_USE_ITEM = 87;

export DWORD EVENT_UNIT_LOADED = 88;

export DWORD EVENT_WIDGET_DEATH = 89;

export DWORD EVENT_DIALOG_BUTTON_CLICK = 90;
export DWORD EVENT_DIALOG_CLICK = 91;

//===================================================
// Frozen Throne Expansion Events
// Need to be added here to preserve compat
//===================================================

//===================================================
// For use with TriggerRegisterGameEvent    
//===================================================    

export DWORD          EVENT_GAME_LOADED = 256;
export DWORD          EVENT_GAME_TOURNAMENT_FINISH_SOON = 257;
export DWORD          EVENT_GAME_TOURNAMENT_FINISH_NOW = 258;
export DWORD          EVENT_GAME_SAVE = 259;

//===================================================
// For use with TriggerRegisterPlayerEvent
//===================================================

export DWORD        EVENT_PLAYER_ARROW_LEFT_DOWN = 261;
export DWORD        EVENT_PLAYER_ARROW_LEFT_UP = 262;
export DWORD        EVENT_PLAYER_ARROW_RIGHT_DOWN = 263;
export DWORD        EVENT_PLAYER_ARROW_RIGHT_UP = 264;
export DWORD        EVENT_PLAYER_ARROW_DOWN_DOWN = 265;
export DWORD        EVENT_PLAYER_ARROW_DOWN_UP = 266;
export DWORD        EVENT_PLAYER_ARROW_UP_DOWN = 267;
export DWORD        EVENT_PLAYER_ARROW_UP_UP = 268;

//===================================================
// For use with TriggerRegisterPlayerUnitEvent
//===================================================

export DWORD    EVENT_PLAYER_UNIT_SELL = 269;
export DWORD    EVENT_PLAYER_UNIT_CHANGE_OWNER = 270;
export DWORD    EVENT_PLAYER_UNIT_SELL_ITEM = 271;
export DWORD    EVENT_PLAYER_UNIT_SPELL_CHANNEL = 272;
export DWORD    EVENT_PLAYER_UNIT_SPELL_CAST = 273;
export DWORD    EVENT_PLAYER_UNIT_SPELL_EFFECT = 274;
export DWORD    EVENT_PLAYER_UNIT_SPELL_FINISH = 275;
export DWORD    EVENT_PLAYER_UNIT_SPELL_ENDCAST = 276;

//===================================================
// For use with TriggerRegisterUnitEvent
//===================================================

export DWORD          EVENT_UNIT_SELL = 286;
export DWORD          EVENT_UNIT_CHANGE_OWNER = 287;
export DWORD          EVENT_UNIT_SELL_ITEM = 288;
export DWORD          EVENT_UNIT_SPELL_CHANNEL = 289;
export DWORD          EVENT_UNIT_SPELL_CAST = 290;
export DWORD          EVENT_UNIT_SPELL_EFFECT = 291;
export DWORD          EVENT_UNIT_SPELL_FINISH = 292;
export DWORD          EVENT_UNIT_SPELL_ENDCAST = 293;

//===================================================
// Limit Event API export DWORD    
// variable, player state, game state, and unit state events
// ( do NOT change the order of these... ;
//===================================================
export DWORD LESS_THAN = 0;
export DWORD LESS_THAN_OR_EQUAL = 1;
export DWORD EQUAL = 2;
export DWORD GREATER_THAN_OR_EQUAL = 3;
export DWORD GREATER_THAN = 4;
export DWORD NOT_EQUAL = 5;

//===================================================
// Unit Type export DWORD for use with IsUnitType(;
//===================================================

export DWORD UNIT_TYPE_HERO = 0;
export DWORD UNIT_TYPE_DEAD = 1;
export DWORD UNIT_TYPE_STRUCTURE = 2;

export DWORD UNIT_TYPE_FLYING = 3;
export DWORD UNIT_TYPE_GROUND = 4;

export DWORD UNIT_TYPE_ATTACKS_FLYING = 5;
export DWORD UNIT_TYPE_ATTACKS_GROUND = 6;

export DWORD UNIT_TYPE_MELEE_ATTACKER = 7;
export DWORD UNIT_TYPE_RANGED_ATTACKER = 8;

export DWORD UNIT_TYPE_GIANT = 9;
export DWORD UNIT_TYPE_SUMMONED = 10;
export DWORD UNIT_TYPE_STUNNED = 11;
export DWORD UNIT_TYPE_PLAGUED = 12;
export DWORD UNIT_TYPE_SNARED = 13;

export DWORD UNIT_TYPE_UNDEAD = 14;
export DWORD UNIT_TYPE_MECHANICAL = 15;
export DWORD UNIT_TYPE_PEON = 16;
export DWORD UNIT_TYPE_SAPPER = 17;
export DWORD UNIT_TYPE_TOWNHALL = 18;
export DWORD UNIT_TYPE_ANCIENT = 19;

//===================================================
// Unit Type export DWORD for use with ChooseRandomItemEx(;
//===================================================

export DWORD ITEM_TYPE_PERMANENT = 0;
export DWORD ITEM_TYPE_CHARGED = 1;
export DWORD ITEM_TYPE_POWERUP = 2;
export DWORD ITEM_TYPE_ARTIFACT = 3;
export DWORD ITEM_TYPE_PURCHASABLE = 4;
export DWORD ITEM_TYPE_CAMPAIGN = 5;
export DWORD ITEM_TYPE_MISCELLANEOUS = 6;
export DWORD ITEM_TYPE_UNKNOWN = 7;
export DWORD ITEM_TYPE_ANY = 8;

// Deprecated, should use ITEM_TYPE_POWERUP
export DWORD ITEM_TYPE_TOME = 2;

//===================================================
// Animatable Camera Fields
//===================================================

export DWORD CAMERA_FIELD_TARGET_DISTANCE = 0;
export DWORD CAMERA_FIELD_FARZ = 1;
export DWORD CAMERA_FIELD_ANGLE_OF_ATTACK = 2;
export DWORD CAMERA_FIELD_FIELD_OF_VIEW = 3;
export DWORD CAMERA_FIELD_ROLL = 4;
export DWORD CAMERA_FIELD_ROTATION = 5;
export DWORD CAMERA_FIELD_ZOFFSET = 6;

export DWORD   BLEND_MODE_NONE = 0;
export DWORD   BLEND_MODE_DONT_CARE = 0;
export DWORD   BLEND_MODE_KEYALPHA = 1;
export DWORD   BLEND_MODE_BLEND = 2;
export DWORD   BLEND_MODE_ADDITIVE = 3;
export DWORD   BLEND_MODE_MODULATE = 4;
export DWORD   BLEND_MODE_MODULATE_2X = 5;

export DWORD  RARITY_FREQUENT = 0;
export DWORD  RARITY_RARE = 1;

export DWORD    TEXMAP_FLAG_NONE = 0;
export DWORD    TEXMAP_FLAG_WRAP_U = 1;
export DWORD    TEXMAP_FLAG_WRAP_V = 2;
export DWORD    TEXMAP_FLAG_WRAP_UV = 3;

export DWORD       FOG_OF_WAR_MASKED = 1;
export DWORD       FOG_OF_WAR_FOGGED = 2;
export DWORD       FOG_OF_WAR_VISIBLE = 4;

//===================================================
// Camera Margin export DWORD for use with GetCameraMargin
//===================================================

export DWORD        CAMERA_MARGIN_LEFT = 0;
export DWORD        CAMERA_MARGIN_RIGHT = 1;
export DWORD        CAMERA_MARGIN_TOP = 2;
export DWORD        CAMERA_MARGIN_BOTTOM = 3;

//===================================================
// Effect API export DWORD
//===================================================

export DWORD     EFFECT_TYPE_EFFECT = 0;
export DWORD     EFFECT_TYPE_TARGET = 1;
export DWORD     EFFECT_TYPE_CASTER = 2;
export DWORD     EFFECT_TYPE_SPECIAL = 3;
