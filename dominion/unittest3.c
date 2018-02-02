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
	int supplyCount1;
   	int	randNum;
   	int	card;
	int i;
	int fail = 0;

	initializeGame(2, k, 5, &G);
	printf("TEST 3: TESTING SUPPLY COUNT FUNCTION.");

	G.supplyCount[1] = 5;
	for(i = 0; i < 1000; i ++){
		randNum = rand() % 500;
		card = rand () % 10;
		G.supplyCount[card] = randNum;
		printf("TEST: There should be %d number of card %d in the deck...\n", randNum, card);
		supplyCount1 = supplyCount(card, &G);
		if(supplyCount1 == randNum)
			printf("SUCCESS: There are %d cards of card %d in the deck!\n", supplyCount1, card);
		else{
			printf("FAIL: The number of cards does not match the TEST number\n");
			fail++;
		}
	}
	printf("TEST COMPLETE. FROM 1000 TESTS, THERE WERE %d FAILURES.\n", fail);
} 
