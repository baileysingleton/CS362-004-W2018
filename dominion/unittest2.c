#include "dominion.h"
#include <stdio.h>
#include <assert.h>
#include "dominion_helpers.h"
#include "rngs.h"

// This unit test is to test the card cost. This will test every card.
int main () {
	int cost[27] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};
	int returnCost;
	int i;
	int fail = 0;

	printf("TEST PHASE 1: CHECK ALL CARDS AND THEIR COSTS\n");
	for(i = 0; i < 26; i ++){
		printf("TEST: Card %d should cost %d...\n", i, cost[i]);
		returnCost = getCost(i);
		if(returnCost == cost[i])
			printf("SUCCESS: Card %d costs %d!\n", i, returnCost);
		else{
			printf("FAIL: Card %d cost %d, when it should have cost %d\n", i, returnCost, cost[i]);
			fail = 1;
		}
	}
	printf("END TEST PHASE 1. INITIATE TEST PHASE 2: INVALID CARD NUMBER SHOULD RETURN -1.\n");

	printf("TEST: Passing 500000 into GetCost function...\n");
	returnCost = getCost(500000);
	if(returnCost == -1)
		printf("SUCCESS: Return cost is -1.\n");
	else{
		printf("FAIL: Return cost is %d\n", returnCost);
		fail = 1;
	}

	printf("TEST: Passing '-1' into GetCost function...\n");
	returnCost = getCost(-1);
	if(returnCost == -1)
		printf("SUCCESS: Return cost is -1.\n");
	else{
		printf("FAIL: Return cost is %d\n", returnCost);
		fail = 1;
	}

	printf("TESTS COMPLETE!\n");
	if(fail)
		printf("SOME TESTS HAVE FAILED.\n");
	else
		printf("ALL TESTS HAVE PASSED!\n");
		
} 
