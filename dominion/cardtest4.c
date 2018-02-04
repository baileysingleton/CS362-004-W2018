#include "dominion.h"
#include <stdio.h>
#include <assert.h>
#include "dominion_helpers.h"
#include "rngs.h"

int main () {

    struct gameState G;
	int cardResult;
	int fail = 0;
	int numAction1, numAction2, actionDiff;
	int numCards1, numCards2, cardDiff;
	int i;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    initializeGame(2, k, 69, &G); //player 0's turn
	printf("TEST: GREAT HALL CARD\n"); 
	for(i = 0; i < 5; i++){
		G.hand[0][i] = great_hall;
	}
	numAction1 = G.numActions;
	numCards1 = G.handCount[0];
	printf("INITIAL NUM ACTIONS: %d, INITIAL HAND COUNT: %d\n", G.numActions, G.handCount[0]);

	printf("PLAYING GREAT HALL CARD\n");
	cardResult = cardEffect(gardens, 0,0,0, &G, 0, 0);
	printf("TEST: CARD EFFECT SHOULD RETURN 0\n");
	if(cardResult == 0)
		printf("SUCCESS! CARD EFFECT RETURNS 0!\n");
	else{
		printf("FAIL! CARD EFFECT DID NOT RETURN 0!\n");
		fail ++;
	}
	printf("TURN: %d\n", G.whoseTurn);
	numAction2 = G.numActions;
	numCards2 = G.handCount[0];

	cardDiff = numCards2 - numCards1;
	actionDiff = numAction2 - numAction1;
	printf("TEST: NUM ACTIONS SHOULD BE ONE MORE THAN BEFORE\n");

	if(actionDiff == 1)
		printf("SUCCESS! There is one more Action than before\n");
	else{
		printf("FAIL! There are %d more Actions than before!\n", actionDiff);
		fail++;
	}

	printf("TEST: There should be the same number of cards in hand as before\n");

	if(cardDiff == 0)
		printf("SUCCESS! A card was drawn and discarded\n");
	else{
		printf("FAIL! Something went wrong\n");
		fail++;
	}
	printf("TEST COMPLETE! THE TEST RAN WITH %d FAILURES\n", fail);
}
	

