#include "dominion.h"
#include <stdio.h>
#include <assert.h>
#include "dominion_helpers.h"
#include <time.h>
#include "rngs.h"
#include <stdlib.h>

int main () {
	srand(time(NULL));
    struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int handCount;
   	int	randNum;
	int i;
	int numPlayers = 2;
	int fail = 0;

	initializeGame(numPlayers, k, 5, &G);
	printf("TEST 3: TESTING NUM HAND CARDS FUNCTION.");

	for(i = 0; i < 1000; i ++){
		randNum = rand() % 500;
		G.handCount[0] = randNum;
		printf("TEST: The hand size of player 0 should be of size %d...\n",randNum);
		handCount = numHandCards(&G);
		if(handCount == randNum)
			printf("SUCCESS: There are %d cards in player 0's hand!\n",handCount);
		else{
			printf("FAIL: The number of cards in the hand of player 0 (%d) does not match the TEST number:\n", handCount);
			fail++;
		}
	}
	G.whoseTurn++;
	for(i = 0; i < 1000; i ++){
		randNum = rand() % 500;
		G.handCount[1] = randNum;
		printf("TEST: The hand size of player 1 should be of size %d...\n",randNum);
		handCount = numHandCards(&G);
		if(handCount == randNum)
			printf("SUCCESS: There are %d cards in player 1's hand!\n",handCount);
		else{
			printf("FAIL: The number of cards in the hand of player 1 (%d) does not match the TEST number:\n", handCount);
			fail++;
		}
	}
	printf("TEST COMPLETE. FROM 2000 TESTS, THERE WERE %d FAILURES.\n", fail);
} 
