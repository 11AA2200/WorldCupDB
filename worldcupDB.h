
#ifndef _WORLD_CUP_DB_H_
#define _WORLD_CUP_DB_H_

#define TEAM_NAME_LENGTH_LIMIT 255
#define PLAYER_NAME_LENGTH_LIMIT 255
#define PLAYER_CLUB_LENGTH_LIMIT 255

typedef struct team {
  int code;
  char name[TEAM_NAME_LENGTH_LIMIT];
  char seeding[3];
  char primaryKit;
  struct team* next;
} team;

typedef struct player {
  int code;
  char name[PLAYER_NAME_LENGTH_LIMIT];
  int age;
  char club[PLAYER_CLUB_LENGTH_LIMIT];
  struct player* next;
} player;

team *createTeam(int code, char *name, char *seeding, char primaryKit);
void printTeam(team *team);

player *createPlayer(int code, char *name, int age, char *club);
void printPlayer(player *player);

#endif
