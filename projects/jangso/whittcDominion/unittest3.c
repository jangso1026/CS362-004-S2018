
///* -----------------------------------------------------------------------
// * Demonstration of how to write unit tests for dominion-base
// * Include the following lines in your makefile:
// *
// * unittest3: unittest3.c dominion.o rngs.o
// *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
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
//    int deckCount = 20;
//    int handCount = 5;
//    int discardCount = 15;
//    int card;
//    int count;
//    int isItTrue;
//    
//    time_t time_seed;
//    srand((unsigned) time(&time_seed));
//    
//    printf ("TESTING fullDeckCount():\n");
//    for (p = 1; p <= numPlayer; p++)
//    {
//            memset(&G, 23, sizeof(struct gameState));   // clear the game state
//            r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
//            G.deckCount[p] = 0;                 // set the number of cards on deck
//            G.handCount[p] = 0;                 // set the number of cards on hand
//            G.discardCount[p] = 0;           // set the number of discard cards
//            G.whoseTurn = p;                            // set the player
//            card = rand() % 26;                         //set card number
//            printf("Card is %d.\n", card);
//            count = 0;
//        printf("On deck: ");
//                for(i = 0; i < deckCount; i++){
//                    isItTrue = -1;
//                    
//                    while(isItTrue != 0){
//                        cardEnum = rand() % 26; // make cardEnum be between [0, 26)
//                        isItTrue = gainCard(cardEnum, &G, 1, p);
//                    }
//                    
//                    printf("%d ", cardEnum);
//                    if(card == cardEnum) {
//                        count++;
//                    }
//                }
//         printf("\n");
//         printf("On hand: ");
//            
//                for(i = 0; i < handCount; i++){
//                    isItTrue = -1;
//                    
//                    while(isItTrue != 0){
//                        cardEnum = rand() % 26; // make cardEnum be between [0, 26)
//                        isItTrue = gainCard(cardEnum, &G, 2, p);
//                    }
//                    
//                    printf("%d ", cardEnum);
//                    if(card == cardEnum) {
//                        count++;
//                    }
//                }
//        printf("\n");
//        printf("On discard deck: ");
//            
//                for(i = 0; i < discardCount; i++){
//                    isItTrue = -1;
//                    
//                    while(isItTrue != 0){
//                        cardEnum = rand() % 26; // make cardEnum be between [0, 26)
//                        isItTrue = gainCard(cardEnum, &G, 0, p);
//                    }
//                    
//                    printf("%d ", cardEnum);
//                    if(card == cardEnum) {
//                        count++;
//                    }
//                }
//        
//        printf("\n");
//#if (NOISY_TEST == 1)
//            printf("player %d: %d card(s) should be found.\n", p, count);
//#endif
//        
//            result = fullDeckCount(p, card, &G);
//            
//#if (NOISY_TEST == 1)
//            printf("According to function, player %d has %d card(s) in hand.\n", p, result);
//#endif
//            assert(result == count); // check if the number returned is correct
//
//        
//    }
//    
//    printf("All tests passed!\n");
//    
//    return 0;
//}
//
//
