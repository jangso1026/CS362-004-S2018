/*
 * cardtest2.c
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
        int r;
    int discarded;
    int shuffledCards = 0;
        int newCards = 3; //cards which have to be drawn

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
        int playedCard;

    // initialize a game state and player cards
    r = initializeGame(numPlayers, k, seed, &G);

        printf("inital: \n");
        printf("handcount %d\n", G.handCount[thisPlayer]);
        printf("deckcount %d\n", G.deckCount[thisPlayer]);
        printf("discardcount %d\n", G.discardCount[thisPlayer]);



    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    // copy the game state to a test case
    //memcpy(&testG, &G, sizeof(struct gameState));
        testG = G;
        if(testG.deckCount[thisPlayer] < 2){
            shuffledCards = testG.discardCount[thisPlayer];
        }

    cardEffect(smithy, choice1, choice2, choice3, &G, handpos, &bonus);
        discarded = G.discardCount[thisPlayer] - testG.discardCount[thisPlayer] - shuffledCards;
        playedCard = G.playedCardCount;

        printf("shuffle = %d, discarded = %d\n", shuffledCards, discarded);

        printf("check card count and to check if cards got drawn from the player's deck.\n");
        printf("hand count = %d, expected = %d \n ", G.handCount[thisPlayer], testG.handCount[thisPlayer] + newCards - playedCard);
        printf("deck count = %d, expected = %d \n", G.deckCount[thisPlayer], testG.deckCount[thisPlayer] - newCards - discarded + shuffledCards);
        printf("discard count = %d, expected = %d\n", G.discardCount[thisPlayer], testG.discardCount[thisPlayer] + discarded);

        assert(G.handCount[thisPlayer] == (testG.handCount[thisPlayer] + newCards - playedCard));
        assert(G.deckCount[thisPlayer] == (testG.deckCount[thisPlayer] - newCards - discarded + shuffledCards));
        assert(G.discardCount[thisPlayer] == (testG.discardCount[thisPlayer] + discarded));

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

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


    return 0;
}
