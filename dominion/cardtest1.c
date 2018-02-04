#include "dominion.h"
#include <stdio.h>
#include <assert.h>
#include "dominion_helpers.h"
#include "rngs.h"

int main () {

    struct gameState G;
	int cardResult;
	int handSize1;
	int handSize2;
	int handDifference;
	int fail = 0;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    initializeGame(2, k, 69, &G); //player 0's turn
	printf("TEST: SMITHY CARD\n"); 
	printf("HAND COUNT BEFORE SMITHY: %d\n", G.handCount[0]);
	handSize1 = G.handCount[0];
	G.hand[0][0] = smithy;
	printf("PLAYING SMITHY CARD\n");
	cardResult = cardEffect(smithy, 0,0,0, &G, 0, 0);
	handSize2 = G.handCount[0];
	printf("CARD EFFECT: %d\n", cardResult);
	printf("GAME STATE SHOULD RETURN 0\n");

	if(cardResult == 0)
		printf("SUCCESS: Game state is 0! \n");
	else{
		printf("FAIL: Game state is not 0! \n");
		fail++;
	}

	handDifference = handSize2 - handSize1;
	printf("HAND COUNT AFTER SMITHY: %d\n", G.handCount[0]);
	printf("TEST: HAND SIZE DIFFERENCE SHOULD BE 2 LARGER.\n");
	if(handDifference == 2)
		printf("SUCCESS! HAND SIZE DIFFERENCE IS 2\n");
	else{
		printf("FAIL: HAND SIZE DIFFERENCE IS %d\n", handDifference);
		fail ++;
	}
	printf("TEST COMPLETE. TEST FAILED %d NUMBER OF TIMES\n", fail);	
}
