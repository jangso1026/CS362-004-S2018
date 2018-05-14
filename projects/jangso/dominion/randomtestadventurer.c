/*
 * randomtestadventurer.c
 * Include the following lines in your makefile:
 *
 * randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
 *      gcc -o randomtestadventurer -g  randomtestadventurer.c gameStateRandomizer.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "gameStateRandomizer.h"

#define TESTCARD "adventurer"

int main() {
	int r;
    int discarded;
    int newCards = 0; //treasure cards which have to be drawn
    int cardsDrawn = 0;
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
    for (j = 0; j < 10; ++j) { //iterate 10 times to have more cases
			newCards = 0;
			cardsDrawn = 0;
			printf("init game\n");
    	// initialize a game state and player cards
    	r = initializeGame(numPlayers, k, seed, &G);
    	randomizeDiscard(&G, thisPlayer, rand() % 5);
			printf("deckcount %d\n", G.deckCount[thisPlayer]);



    	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    	// copy the game state to a test case

			testG = G;
			printf("CardEffect time\n");
			printGameState(&G, thisPlayer);
			for (i = G.deckCount[thisPlayer] - 1; i > -1; --i) {
			Card card = G.deck[thisPlayer][i];
			cardsDrawn++;
			if (card == copper || card == silver || card == gold) {
				newCards++;
				if (newCards == 2) {
					break;
				}
			}
		}
		printf("should draw %d cards and %d treasures!\n", cardsDrawn, newCards);
    cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);
		printf("after CardEffect time\n");
		printGameState(&G, thisPlayer);
		discarded = G.discardCount[thisPlayer] - testG.discardCount[thisPlayer];

		printf("discarded = %d\n", discarded);

		printf("check card count, to check if non-treasure cards got discarded, and to check if cards got drawn from the player's deck.\n");

		printf("hand count = %d, expected = %d \n ", G.handCount[thisPlayer], testG.handCount[thisPlayer] + newCards);
		assert(G.handCount[thisPlayer] == (testG.handCount[thisPlayer] + newCards));

		printf("deck count = %d, expected = %d \n", G.deckCount[thisPlayer], testG.deckCount[thisPlayer] - newCards - discarded);
		assert(G.deckCount[thisPlayer] == (testG.deckCount[thisPlayer] - cardsDrawn));

		printf("discard count = %d, expected = %d\n", G.discardCount[thisPlayer], testG.discardCount[thisPlayer] + discarded);
		assert(G.discardCount[thisPlayer] == (testG.discardCount[thisPlayer] + discarded));

		printf("passed\n");
		printf("\n");
		
		int lastPos = G.handCount[thisPlayer];

		printf("check if treasure cards are drawn.\n");
		assert(G.hand[thisPlayer][lastPos-1] == 4 || G.hand[thisPlayer][lastPos-1] == 5 || G.hand[thisPlayer][lastPos-1] == 6);
		assert(G.hand[thisPlayer][lastPos - 2] == 4 || G.hand[thisPlayer][lastPos - 2] == 5 || G.hand[thisPlayer][lastPos -2] == 6);
		printf("passed\n");
		printf("\n");

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
