///* -----------------------------------------------------------------------
// * Demonstration of how to write unit tests for dominion-base
// * Include the following lines in your makefile:
// *
// * unittest1: unittest1.c dominion.o rngs.o
// *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
// * -----------------------------------------------------------------------
// */
//
//#include "dominion.h"
//#include "dominion_helpers.h"
//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <time.h>
//#include "rngs.h"
//
//// set NOISY_TEST to 0 to remove printfs from output
//#define NOISY_TEST 1
//
//int main() {
//    int r;
//    int handCount;
//    int seed = 1000;
//    int numPlayer = 2;
//    int result;
//    int p;
//    int k[10] = {adventurer, council_room, feast, gardens, mine
//        , remodel, smithy, village, baron, great_hall};
//    struct gameState G;
//
//    time_t time_seed;
//    srand((unsigned) time(&time_seed));
//
//    printf ("TESTING numHandCard():\n");
//    for (p = 1; p <= numPlayer; p++)
//    {
//                handCount = rand() % 6; // make handcount be between [0, 6)
//#if (NOISY_TEST == 1)
//                printf("Test player %d with %d card(s) in hand.\n", p, handCount);
//#endif
//                memset(&G, 23, sizeof(struct gameState));   // clear the game state
//                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
//                G.handCount[p] = handCount;                 // set the number of cards on hand
//                G.whoseTurn = p;
//                result = numHandCards(&G);
//#if (NOISY_TEST == 1)
//                printf("player %d has %d card(s) in hand.\n", p, result);
//#endif
//                assert(result == handCount); // check if the number of cards is correct
//    }
//
//    printf("All tests passed!\n");
//
//    return 0;
//}
