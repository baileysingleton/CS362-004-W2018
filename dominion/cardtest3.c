#include "dominion.h"
#include <stdio.h>
#include <assert.h>
#include "dominion_helpers.h"
#include "rngs.h"

int main () {

    struct gameState G;
	int cardResult;
	int fail = 0;
	int i;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    initializeGame(2, k, 69, &G); //player 0's turn
	printf("TEST: GARDENS CARD\n"); 
	for(i = 0; i < 5; i++){
		G.hand[0][i] = gardens;
	}

	printf("PLAYING GARDENS CARD\n");
	cardResult = cardEffect(gardens, 0,0,0, &G, 0, 0);
	printf("TEST: CARD EFFECT OF GARDENS CARD IS TO RETURN 0\n");
	if(cardResult == 0)
		printf("SUCCESS! GARDENS CARD WORKED AS EXPECTED\n");
	else{
		printf("FAIL! GARDENS CARD DID NOT WORK AS EXPECTED\n");
		fail ++;
	}
	printf("TEST COMPLETE! THE TEST RAN WITH %d FAILURES\n", fail);
}
	

