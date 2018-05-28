///* -----------------------------------------------------------------------
// * Demonstration of how to write unit tests for dominion-base
// * Include the following lines in your makefile:
// *
// * unittest4: unittest4.c dominion.o rngs.o
// *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
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
//#define NOISY_TEST 0
//
//int main() {
//    int i;
//    int r;
//    int seed = 1000;
//    int numPlayer = 2;
//    int result;
//    int cardEnum;
//    int p;
//    int k[10] = {adventurer, council_room, feast, gardens, mine
//        , remodel, smithy, village, baron, great_hall};
//    struct gameState G;
//    int deckCount = 2;
//    int handCount = 2;
//    int discardCount = 2;
//    int card;
//        int toFlag = 3;
//        int supplyPile;
//
//    time_t time_seed;
//    srand((unsigned) time(&time_seed));
//
//    printf ("TESTING gainCard():\n");
//    for (p = 1; p <= numPlayer; p++)
//    {
//            memset(&G, 23, sizeof(struct gameState));   // clear the game state
//            r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
//            G.deckCount[p] = deckCount;                 // set the number of cards on deck
//            G.handCount[p] = handCount;                 // set the number of cards on hand
//            G.discardCount[p] = discardCount;           // set the number of discard cards
//            G.whoseTurn = p;
//                                         // set the player
//
//                for(i = 0; i < deckCount; i++){                    //adding cards on deck
//                    cardEnum = rand() % 26; // make cardEnum be between [0, 26)
//                    G.deck[p][i] = cardEnum;
//                }
//
//                for(i = 0; i < handCount; i++){                    //adding cards on hands
//                    cardEnum = rand() % 26; // make cardEnum be between [0, 26)
//                    G.hand[p][i] = cardEnum;
//                }
//
//                for(i = 0; i < discardCount; i++){            //adding cards on discard deck
//                    cardEnum = rand() % 26; // make cardEnum be between [0, 26)
//                    G.discard[p][i] = cardEnum;
//                }
//
//                                for(i = 0; i < toFlag; i++){
//                                    card = rand() % 7;                        //make card be between [0, 7) since they have the plenty supply
//                                    supplyPile = G.supplyCount[card];
//                                    printf("Card is %d.\n", card);
//                                    printf("Supply is %d.\n", supplyPile);
//
//                                    if(i == 0){
//#if (NOISY_TEST == 1)
//                                        printf("player %d and toFlag %d: %d card(s) should be found on discard deck.\n", p, i, discardCount + 1);
//#endif
//                                        gainCard(card, &G, i, p);
//                                        result = G.discardCount[p];
//#if (NOISY_TEST == 1)
//                                        printf("According to function, player %d has %d card(s) in discard deck.\n", p, result);
//#endif
//                                        assert(result == (discardCount + 1));
//                                    }
//
//                                    else if(i == 1) {
//#if (NOISY_TEST == 1)
//                                        printf("player %d and toFlag %d: %d card(s) should be found on deck.\n", p, i, deckCount + 1);
//#endif
//                                        gainCard(card, &G, i, p);
//                                        result = G.deckCount[p];
//#if (NOISY_TEST == 1)
//                                        printf("According to function, player %d has %d card(s) in deck.\n", p, result);
//#endif
//                                        assert(result == (deckCount + 1));
//                                    }
//
//
//                                    else if(i == 2){
//#if (NOISY_TEST == 1)
//                                        printf("player %d and toFlag %d: %d card(s) should be found on hand.\n", p, i, handCount + 1);
//#endif
//                                        gainCard(card, &G, i, p);
//                                        result = G.handCount[p];
//#if (NOISY_TEST == 1)
//                                        printf("According to function, player %d has %d card(s) in hand.\n", p, result);
//#endif
//                                        assert(result == (handCount + 1));
//                                    }
//
//                                    int newSupplyPile = G.supplyCount[card];
//                                    printf("newSupply is %d.\n", newSupplyPile);
//
//                                    assert((supplyPile - 1) == newSupplyPile);
//
//                    }
//
//
//
//
//    }
//
//    printf("All tests passed!\n");
//
//    return 0;
//}
