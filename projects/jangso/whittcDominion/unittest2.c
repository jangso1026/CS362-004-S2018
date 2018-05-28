///* -----------------------------------------------------------------------
// * Demonstration of how to write unit tests for dominion-base
// * Include the following lines in your makefile:
// *
// * unittest2: unittest2.c dominion.o rngs.o
// *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
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
//    int handCount = 5;
//    int seed = 1000;
//    int numPlayer = 2;
//    int result;
//    int cardEnum;
//    int p;
//    int hc;
//    int handPos;
//    int k[10] = {adventurer, council_room, feast, gardens, mine
//        , remodel, smithy, village, baron, great_hall};
//    struct gameState G;
//    
//    time_t time_seed;
//    srand((unsigned) time(&time_seed));
//    
//    printf ("TESTING handCard():\n");
//    for (p = 1; p <= numPlayer; p++)
//    {
//        handPos = 0;
//        for(hc = 0; hc < handCount; hc++) {
//            cardEnum = rand() % 26; // make cardEnum be between [0, 26)
//#if (NOISY_TEST == 1)
//            printf("Test player %d with %d cardEnum.\n", p, cardEnum);
//#endif
//            memset(&G, 23, sizeof(struct gameState));   // clear the game state
//            r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
//            G.handCount[p] = handCount;                 // set the number of cards on hand
//            G.whoseTurn = p;                            // set the player
//            G.hand[p][handPos] = cardEnum;              // set card 
//            result = handCard(handPos, &G);
//#if (NOISY_TEST == 1)
//            printf("According to function, player %d has %d card(s) in hand.\n", p, result);
//#endif
//            assert(result == cardEnum); // check if the number returned is correct
//            
//            handPos++;
//        }
//    }
//    
//    printf("All tests passed!\n");
//    
//    return 0;
//}
//
