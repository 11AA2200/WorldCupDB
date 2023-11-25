
#include "worldCupDB.h"
#include "worldcup_player.h"
#include "worldcup_team.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 255

team *teams = NULL;
player *players = NULL;

team *createTeam(int code, char *name, char *seeding, char primaryKit) {
  team *newTeam = (team *)malloc(sizeof(team));
  newTeam->code = code;
  strcpy(newTeam->name, name);
  strcpy(newTeam->seeding, seeding);
  newTeam->primaryKit = primaryKit;
  newTeam->next = NULL;
  return newTeam;
}
void printTeam(team *team) {
  printf("Team code: %d\n", team->code);
  printf("Team name: %s\n", team->name);
  printf("Team seeding: %s\n", team->seeding);
  printf("Team primary kit: %c\n", team->primaryKit);
}

player *createPlayer(int code, char *name, int age, char *club) {
  player *newPlayer = (player *)malloc(sizeof(player));
  newPlayer->code = code;
  strcpy(newPlayer->name, name);
  newPlayer->age = age;
  strcpy(newPlayer->club, club);
  newPlayer->next = NULL;
  return newPlayer;
}

void printPlayer(player *player) {
  printf("Player code: %d\n", player->code);
  printf("Player name: %s\n", player->name);
  printf("Player age: %d\n", player->age);
  printf("Player club: %s\n", player->club);
}

int readMainMenuOption() {
  while (1) {
    char input[MAX_LENGTH];
    printf("Main menu\n");
    printf("h - Print Help\n");
    printf("q - Quit\n");
    printf("t - Control teams\n");
    printf("p - Control players\n");
    printf("Please, enter option: ");
    scanf("%[^\n]", input);
    getc(stdin);
    if (strcmp(input, "h") == 0) {
      return 0;
    }
    if (strcmp(input, "q") == 0) {
      return 1;
    }
    if (strcmp(input, "t") == 0) {
      return 2;
    }
    if (strcmp(input, "p") == 0) {
      return 3;
    }
    printf("Invalid input\n\n");
  }
}

int readTeamsMenuOption() {
  while (1) {
    char input[MAX_LENGTH];
    printf("Teams control menu\n");
    printf("i - Insert a new team\n");
    printf("s - Search for a team\n");
    printf("u - Update a team\n");
    printf("p - Print team list\n");
    printf("d - Delete team\n");
    printf("q - Main menu\n");
    printf("Please, enter option: ");
    scanf("%[^\n]", input);
    getc(stdin);
    if (strcmp(input, "i") == 0) {
      return 0;
    }
    if (strcmp(input, "s") == 0) {
      return 1;
    }
    if (strcmp(input, "u") == 0) {
      return 2;
    }
    if (strcmp(input, "p") == 0) {
      return 3;
    }
    if (strcmp(input, "d") == 0) {
      return 4;
    }
    if (strcmp(input, "q") == 0) {
      return 5;
    }
    printf("Invalid input\n\n");
  }
}

int readPlayersMenuOption() {
  while (1) {
    char input[MAX_LENGTH];
    printf("Players control menu\n");
    printf("i - Insert a new player\n");
    printf("s - Search for a player\n");
    printf("u - Update a player\n");
    printf("p - Print player list\n");
    printf("d - Delete player\n");
    printf("q - Main menu\n");
    printf("Please, enter option: ");
    scanf("%[^\n]", input);
    getc(stdin);
    if (strcmp(input, "i") == 0) {
      return 0;
    }
    if (strcmp(input, "s") == 0) {
      return 1;
    }
    if (strcmp(input, "u") == 0) {
      return 2;
    }
    if (strcmp(input, "p") == 0) {
      return 3;
    }
    if (strcmp(input, "d") == 0) {
      return 4;
    }
    if (strcmp(input, "q") == 0) {
      return 5;
    }
    printf("Invalid input\n\n");
  }
}

void controlTeams() {
  int isOver = 0;

  while (isOver != 1) {
    char input[MAX_LENGTH];
    int choice = readTeamsMenuOption();
    printf("\n");
    if (choice == 0) {
      printf("Insert new team:\n");
      printf("Please, enter team code: ");
      scanf("%[^\n]", input);
      getc(stdin);
      int code = atoi(input);
      char name[MAX_LENGTH];
      char groupSeeding[MAX_LENGTH];
      if (findTeamByCode(&teams, code) != NULL) {
        printf("Team with such code already exists\n\n");
        continue;
      }
      printf("Please, enter team name: ");
      scanf("%[^\n]", name);
      getc(stdin);
      printf("Please, enter group seeding (i.e. A1, B2, C3, D4): ");
      scanf("%[^\n]", groupSeeding);
      getc(stdin);
      if (strlen(groupSeeding) != 2 || groupSeeding[0] > 'H' ||
          groupSeeding[0] < 'A' || groupSeeding[1] > '4' ||
          groupSeeding[1] < '1') {
        printf("Invalid group seeding\n\n");
        continue;
      }

      printf("Please, enter primary kit color (R, O, Y, G, B, I, V): ");
      scanf("%[^\n]", input);
      getc(stdin);
      if (strlen(input) != 1 ||
          (input[0] != 'R' && input[0] != 'O' && input[0] != 'Y' &&
           input[0] != 'G' && input[0] != 'B' && input[0] != 'I' &&
           input[0] != 'V')) {
        printf("Invalid primary kit color\n\n");
        continue;
      }
      team *newTeam = createTeam(code, name, groupSeeding, input[0]);
      insertTeam(&teams, newTeam);
      printf("Team was successfully created\n\n");
    } else if (choice == 1) {
      printf("Search team by code:\n");
      printf("Please, enter team code: ");
      scanf("%[^\n]", input);
      getc(stdin);
      int code = atoi(input);
      team *found = findTeamByCode(&teams, code);
      if (found == NULL) {
        printf("No team with given code found\n\n");
      } else {
        printTeam(found);
        printf("\n");
      }
    } else if (choice == 2) {
      printf("Update team by code:\n");
      printf("Please, enter team code: ");
      scanf("%[^\n]", input);
      getc(stdin);
      int code = atoi(input);
      char name[MAX_LENGTH];
      char groupSeeding[MAX_LENGTH];
      team *found = findTeamByCode(&teams, code);
      if (found == NULL) {
        printf("No team with given code found\n\n");
        continue;
      }
      printf("Please, enter team name: ");
      scanf("%[^\n]", name);
      getc(stdin);
      printf("Please, enter group seeding (i.e. A1, B2, C3, D4): ");
      scanf("%[^\n]", groupSeeding);
      getc(stdin);
      if (strlen(groupSeeding) != 2 || groupSeeding[0] > 'H' ||
          groupSeeding[0] < 'A' || groupSeeding[1] > '4' ||
          groupSeeding[1] < '1') {
        printf("Invalid group seeding\n\n");
        continue;
      }

      printf("Please, enter primary kit color (R, O, Y, G, B, I, V): ");
      scanf("%[^\n]", input);
      getc(stdin);
      if (strlen(input) != 1 ||
          (input[0] != 'R' && input[0] != 'O' && input[0] != 'Y' &&
           input[0] != 'G' && input[0] != 'B' && input[0] != 'I' &&
           input[0] != 'V')) {
        printf("Invalid primary kit color\n\n");
        continue;
      }
      strcpy(found->name, name);
      strcpy(found->seeding, groupSeeding);
      found->primaryKit = input[0];
      printf("Team was successfully updated\n\n");
    } else if (choice == 3) {
      printTeams(teams);
    	printf("\n\n");
    } else if (choice == 4) {
      printf("Delete team by code:\n");
      printf("Please, enter team code: ");
      scanf("%[^\n]", input);
      getc(stdin);
      int code = atoi(input);
      team *found = findTeamByCode(&teams, code);
      if (found == NULL) {
        printf("No team with given code found\n\n");
      } else {
        deleteTeamByCode(&teams, code);
        printf("Team was successfully deleted\n\n");
      }
    } else if (choice == 5) {
      isOver = 1;
    }
  }
}

void controlPlayers() {
  int isOver = 0;

  while (isOver != 1) {
    char input[MAX_LENGTH];
    int choice = readPlayersMenuOption();
    printf("\n");
    if (choice == 0) {
			printf("Insert new player:\n");
      printf("Please, enter team code: ");
      scanf("%[^\n]", input);
      getc(stdin);
      int code = atoi(input), age;
      char name[MAX_LENGTH];
      char club[MAX_LENGTH];
      if (findPlayerByCode(&players, code) != NULL) {
        printf("Player with such code already exists\n\n");
        continue;
      }
      printf("Please, enter player name: ");
      scanf("%[^\n]", name);
      getc(stdin);
      printf("Please, enter player age (17-99): ");
      scanf("%[^\n]", input);
      getc(stdin);
			age = atoi(input);
      if (age < 17 || age > 99) {
        printf("Invalid player age\n\n");
        continue;
      }

      printf("Please, player club: ");
      scanf("%[^\n]", club);
      getc(stdin);
      player *newPlayer = createPlayer(code, name, age, club);
      insertPlayer(&players, newPlayer);
      printf("Player was successfully created\n\n");
    } else if (choice == 1) {
			printf("Search player by code:\n");
      printf("Please, enter player code: ");
      scanf("%[^\n]", input);
      getc(stdin);
      int code = atoi(input);
      player *found = findPlayerByCode(&players, code);
      if (found == NULL) {
        printf("No player with given code found\n\n");
      } else {
        printPlayer(found);
        printf("\n");
      }
    } else if (choice == 2) {
			printf("Update player by code:\n");
      printf("Please, enter player code: ");
      scanf("%[^\n]", input);
      getc(stdin);
      int code = atoi(input), age;
      char name[MAX_LENGTH];
      char club[MAX_LENGTH];
      player *found = findPlayerByCode(&teams, code);
      if (found == NULL) {
        printf("No player with given code found\n\n");
        continue;
      }
      printf("Please, enter player name: ");
      scanf("%[^\n]", name);
      getc(stdin);
      printf("Please, enter player age (17-99): ");
      scanf("%[^\n]", input);
      getc(stdin);
			age = atoi(input);
      if (age < 17 || age > 99) {
        printf("Invalid player age\n\n");
        continue;
      }

      printf("Please, player club: ");
      scanf("%[^\n]", club);
      getc(stdin);
			
			strcpy(found->name, name);
      found->age = age;
      strcpy(found->club, club);
      printf("Player was successfully updated\n\n");
    } else if (choice == 3) {
      printPlayers(players);
			printf("\n\n");
    } else if (choice == 4) {
			printf("Delete player by code:\n");
      printf("Please, enter player code: ");
      scanf("%[^\n]", input);
      getc(stdin);
      int code = atoi(input);
      player *found = findPlayerByCode(&players, code);
      if (found == NULL) {
        printf("No player with given code found\n\n");
      } else {
        deletePlayerByCode(&players, code);
        printf("Player was successfully deleted\n\n");
      }
    } else if (choice == 5) {
      isOver = 1;
    }
  }
}

int main() {
  int isOver = 0;

  while (isOver != 1) {
    int choice = readMainMenuOption();
    printf("\n");
    if (choice == 0) {
      printf("Help");
    } else if (choice == 1) {
      isOver = 1;
    } else if (choice == 2) {
      controlTeams();
    } else if (choice == 3) {
      controlPlayers();
    }
  }
  freeTeamsDb(teams);
  freePlayersDb(players);
  printf("Good Bye!");
  return 0;
}
