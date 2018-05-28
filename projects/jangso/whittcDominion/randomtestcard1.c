/*
 * randomtestcard1.c
 * Include the following lines in your makefile:
 *
 * randomtestcard1: randomtestcard1.c dominion.o rngs.o
 *      gcc -o randomtestcard1 -g  randomtestcard1.c gameStateRandomizer.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "gameStateRandomizer.h"

#define TESTCARD "smithy"

int main() {
	int r;
    int discarded = 1;
		int cardsDrawn = 3;
    int handpos = 0, choice1 = -1, choice2 = -1, choice3 = -1, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		    sea_hag, tribute, smithy, council_room};
		int pre_supplyPile;
		int post_supplyPile;
		int i;
		int j;
		PlantSeeds(seed);
    for (j = 0; j < 10; ++j) {
			printf("init game\n");
    // initialize a game state and player cards
    	r = initializeGame(numPlayers, k, seed, &G);
    	randomizeDiscard(&G, thisPlayer, rand() % 5);
			printf("deckcount %d\n", G.deckCount[thisPlayer]);



    	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);


			testG = G;
			printf("CardEffect time\n");
			printGameState(&G, thisPlayer);
			printf("should draw %d cards!\n", cardsDrawn);
    	cardEffect(smithy, choice1, choice2, choice3, &G, handpos, &bonus);
			printf("after CardEffect time\n");
			printGameState(&G, thisPlayer);

			printf("discarded = %d\n", discarded);

			printf("check card count and to check if cards got drawn from the player's deck.\n");

			printf("hand count = %d, expected = %d \n ", G.handCount[thisPlayer], testG.handCount[thisPlayer] + cardsDrawn - discarded);
			assert(G.handCount[thisPlayer] == (testG.handCount[thisPlayer] + cardsDrawn - discarded));

			int testDeckCount = testG.deckCount[thisPlayer];
			int testDiscardCount = testG.discardCount[thisPlayer];
			if (testDeckCount - cardsDrawn > 0) {
				testDeckCount -= cardsDrawn;
			} else if (testDeckCount - cardsDrawn == 0) {
				testDeckCount = 0;
			} else {
				testDiscardCount = 0;
				testDeckCount += testG.discardCount[thisPlayer] - cardsDrawn;
		}
		printf("deck count = %d, expected = %d \n", G.deckCount[thisPlayer], testDeckCount);
		assert(G.deckCount[thisPlayer] == testDeckCount);

		printf("discard count = %d, expected = %d\n", G.discardCount[thisPlayer], testDiscardCount);
		assert(G.discardCount[thisPlayer] == testDiscardCount);

		printf("passed\n");
		printf("\n");

		int lastPos = G.handCount[thisPlayer];

		printf("check if other player's deck got effected.\n");
		printf("other player:\n");
		printf("hand count = %d, expected = %d \n ", G.handCount[thisPlayer + 1], testG.handCount[thisPlayer + 1]);
		printf("deck count = %d, expected = %d \n", G.deckCount[thisPlayer + 1], testG.deckCount[thisPlayer + 1]);
		printf("discard count = %d, expected = %d\n", G.discardCount[thisPlayer + 1], testG.discardCount[thisPlayer + 1]);

		assert(G.handCount[thisPlayer+1] == testG.handCount[thisPlayer+1]);
		assert(G.deckCount[thisPlayer+1] == testG.deckCount[thisPlayer+1]);
		assert(G.discardCount[thisPlayer+1] == testG.discardCount[thisPlayer+1]);
		printf("passed\n");
		printf("\n");

		printf("check victory and king supply piles to see nothing has changed.\n");
		for(i = 1; i < 4; i++) {
			pre_supplyPile = testG.supplyCount[i];
			post_supplyPile = G.supplyCount[i];
			assert(pre_supplyPile == post_supplyPile);
		}

		for(i = 7; i < 26; i++) {
			pre_supplyPile = testG.supplyCount[i];
			post_supplyPile = G.supplyCount[i];
			assert(pre_supplyPile == post_supplyPile);
		}

		printf("passed\n");
}
    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


    return 0;
}
