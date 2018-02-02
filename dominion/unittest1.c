#include "dominion.h"
#include <stdio.h>
#include <assert.h>
#include "dominion_helpers.h"
#include "rngs.h"

int main () {

    struct gameState G;
    struct gameState K;
    struct gameState L;
    struct gameState M;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int endGame;
    
    initializeGame(2, k, 69, &G);
    initializeGame(2, k, 69, &K);
    initializeGame(2, k, 69, &L);
	initializeGame(2, k, 69, &M);
	

    // if 3 supply piles are empty, the game should end. 
    G.supplyCount[0] = 0;
    G.supplyCount[1] = 0;
    G.supplyCount[2] = 0;
    
    printf("TEST: Checking if 3 piles are empty the game ends...\n");

    endGame = isGameOver(&G);
    if(endGame == 1)
        printf("PASSED: Game Ended As Expected!");
    else
        printf("FAILED: Game did not end as expected!\n");
	       
    printf("TEST: Checking if province pile is empty the game ends...\n");
	
	K.supplyCount[3] = 0;
	endGame = isGameOver(&K);
	if(endGame == 1)
		printf("PASSED: Game Ended As Expected!\n");
	else
		printf("FAILED: Game did not end as expected!\n");
	
	printf("TEST: Game Should Not End with normal game state...\n");	

	endGame = isGameOver(&L);
	if(endGame == 0)
		printf("PASSED: Game did not end as expected!\n");
	else
		printf("FAILED: Game ended not as expected!\n");

	M.supplyCount[25] = 0;
	M.supplyCount[26] = 0;
	M.supplyCount[27] = 0;
	printf("TEST: Last 3 supply Piles are empty. Game Should end...\n");
	endGame = isGameOver(&M);
	if(endGame == 1)
		printf("PASSED: Game ended as expected!\n");
	else
		printf("FAILED: Game did not end!\n");
} 
