//
// Yet Another POD-Bot, based on PODBot by Markus Klinge ("CountFloyd").
// Copyright (c) YaPB Development Team.
//
// This software is licensed under the BSD-style license.
// Additional exceptions apply. For full license details, see LICENSE.txt or visit:
//     http://yapb.jeefo.net/license
//

#pragma once

extern bool g_canSayBombPlanted;
extern bool g_bombPlanted;
extern bool g_bombSayString; 
extern bool g_roundEnded;
extern bool g_radioInsteadVoice;
extern bool g_waypointOn;
extern bool g_waypointsChanged;
extern bool g_autoWaypoint;
extern bool g_botsCanPause; 
extern bool g_editNoclip;
extern bool g_isMetamod;
extern bool g_isFakeCommand;
extern bool g_sendAudioFinished;
extern bool g_isCommencing;
extern bool g_leaderChoosen[2];

extern float g_autoPathDistance;
extern float g_timeBombPlanted;
extern float g_timeNextBombUpdate;
extern float g_lastChatTime;
extern float g_timeRoundEnd;
extern float g_timeRoundMid;
extern float g_timeNextBombUpdate;
extern float g_timeRoundStart;
extern float g_timePerSecondUpdate;
extern float g_lastRadioTime[2];

extern int g_mapType;
extern int g_numWaypoints;
extern int g_gameVersion;
extern int g_fakeArgc;

extern int g_highestDamageCT;
extern int g_highestDamageT;
extern int g_highestKills;

extern int g_normalWeaponPrefs[NUM_WEAPONS];
extern int g_rusherWeaponPrefs[NUM_WEAPONS];
extern int g_carefulWeaponPrefs[NUM_WEAPONS];
extern int g_grenadeBuyPrecent[NUM_WEAPONS - 23];
extern int g_botBuyEconomyTable[NUM_WEAPONS - 15];
extern int g_radioSelect[32];
extern int g_lastRadio[2];
extern int g_storeAddbotVars[4];
extern int *g_weaponPrefs[];

extern short g_modelIndexLaser;
extern short g_modelIndexArrow;
extern char g_fakeArgv[256];

extern Array <Array <String> > g_chatFactory;
extern Array <Array <ChatterItem> > g_chatterFactory;
extern Array <BotName> g_botNames;
extern Array <KeywordFactory> g_replyFactory;
extern RandomSequenceOfUnique Random;

extern WeaponSelect g_weaponSelect[NUM_WEAPONS + 1];
extern WeaponProperty g_weaponDefs[MAX_WEAPONS + 1];

extern Client g_clients[32];
extern MenuText g_menus[21];
extern TaskItem g_taskFilters[];

extern Experience *g_experienceData;

extern edict_t *g_hostEntity; 
extern edict_t *g_worldEntity;
extern Library *g_gameLib;

extern gamefuncs_t g_functionTable;
extern EntityAPI_t g_entityAPI;
extern FuncPointers_t g_funcPointers;
extern NewEntityAPI_t g_getNewEntityAPI;
extern BlendAPI_t g_serverBlendingAPI;

static inline bool IsNullString (const char *input)
{
   if (input == NULL)
      return true;

   return *input == '\0';
}

static inline float GetWorldTime (void)
{
   return g_pGlobals->time;
}

static inline int GetMaxClients (void)
{
   return g_pGlobals->maxClients;
}

static inline edict_t *EntityOfIndex (const int index)
{
   return static_cast <edict_t *> (g_worldEntity + index);
};

static inline int IndexOfEntity(const edict_t *ent)
{
   return static_cast <int> (ent - g_worldEntity);
};

static inline int EntOffsetOfEntity(const edict_t *ent)
{
   return (char *) ent - (char *) g_worldEntity;
}

static inline bool IsEntityNull (const edict_t *ent)
{
   return !ent || !EntOffsetOfEntity (ent);
}

static inline int GetTeam (edict_t *ent)
{

   if (ent->v.team == 1)
   {
      g_clients[IndexOfEntity (ent) - 1].team = TEAM_TF;
      return TEAM_TF;
   }
   g_clients[IndexOfEntity (ent) - 1].team = TEAM_CF;
   return TEAM_CF;

}