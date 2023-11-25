#include <stdio.h>
#include <stdlib.h>
#include "worldcup_team.h"

void insertTeam(team** teamList, team* team) {
	team->next = *teamList;
	*teamList = team;
}

team* findTeamByCode(team** teamList, int code) {
	team* curr = *teamList;
	while(curr != NULL) {
		if (curr->code == code) {
			return curr;
		}
		curr = curr->next;
	}
	return NULL;
}

void deleteTeamByCode(team** teamList, int code) {
	team* curr = *teamList;
	if (curr->code == code) {
		*teamList = (*teamList)->next;
		free(curr);
	}
	else {
		while(curr->next != NULL) {
			if (curr->next->code == code) {
				team* tmp = curr->next;
				curr->next = curr->next->next;
				free(tmp);
			}
			curr = curr->next;
		}
	}
}

void printTeams(team* teamList) {
	team* curr = teamList;
	printf("Teams list\n");
	while(curr != NULL) {
		printTeam(curr);
		printf("\n");
		curr = curr->next;
	}
}

void freeTeamsDb(team* teamList) {
	team* curr = teamList;
	while(curr != NULL) {
		team* tmp = curr->next;
		free(curr);
		curr = tmp;
	}
}
