#include "worldCupDB.h"

void insertTeam(team** teamList, team* team);
team* findTeamByCode(team** teamList, int code);
void deleteTeamByCode(team** teamList, int code);
void printTeams(team* teamList);
void freeTeamsDb(team* teamList);
