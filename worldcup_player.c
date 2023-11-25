#include <stdio.h>
#include <stdlib.h>
#include "worldcup_player.h"

void insertPlayer(player **playerList, player *player) {
	player->next = *playerList;
	*playerList = player;	
}

player *findPlayerByCode(player **playerList, int code) {
	player* curr = *playerList;
	while(curr != NULL) {
		if (curr->code == code) {
			return curr;
		}
		curr = curr->next;
	}
	return NULL;
}

void deletePlayerByCode(player **playerList, int code) {
	player* curr = *playerList;
	if (curr->code == code) {
		*playerList = (*playerList)->next;
		free(curr);
	}
	else {
		while(curr->next != NULL) {
			if (curr->next->code == code) {
				player* tmp = curr->next;
				curr->next = curr->next->next;
				free(tmp);
			}
			curr = curr->next;
		}
	}
}

void printPlayers(player *playerList) {
	player* curr = playerList;
	printf("Teams list\n");
	while(curr != NULL) {
		printPlayer(curr);
		printf("\n");
		curr = curr->next;
	}
}

void freePlayersDb(player *playerList) {
	player* curr = playerList;
	while(curr != NULL) {
		player* tmp = curr->next;
		free(curr);
		curr = tmp;
	}
}
