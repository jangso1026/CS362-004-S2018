#include "gameStateRandomizer.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rngs.h"

// struct gameState {
//   int numPlayers; //number of players
//   int supplyCount[treasure_map+1];  //this is the amount of a specific type of card given a specific number.
//   int embargoTokens[treasure_map+1];
//   int outpostPlayed;
//   int outpostTurn;
//   int whoseTurn;
//   int phase;
//   int numActions; /* Starts at 1 each turn */
//   int coins; /* Use as you see fit! */
//   int numBuys; /* Starts at 1 each turn */
//   int hand[MAX_PLAYERS][MAX_HAND];
//   int handCount[MAX_PLAYERS];
//   int deck[MAX_PLAYERS][MAX_DECK];
//   int deckCount[MAX_PLAYERS];
//   int discard[MAX_PLAYERS][MAX_DECK];
//   int discardCount[MAX_PLAYERS];
//   int playedCards[MAX_DECK];
//   int playedCardCount;
// };

void printArray(char* msg, int* arr, unsigned int size) {
  if (msg == NULL || arr == NULL) {
    printf(": NULL\n");
    return;
  }
  int i;
  printf("%s: [", msg);
  if (size == 0) {
    printf("]\n");
    return;
  }
  for (i = 0; i < size - 1; ++i) {
    printf("%d, ", arr[i]);
  }
  printf("%d]\n", arr[size - 1]);
}

void printGameState(GameState* state, Player player) {
  printf("GameState for player: %d\n", player);
  printArray("\tHand", state->hand[player], state->handCount[player]);
  printArray("\tDeck", state->deck[player], state->deckCount[player]);
  printArray("\tDiscard", state->discard[player], state->discardCount[player]);
}

void randomizeHand(GameState* state, Player player, unsigned int handCount) {
  assert(state != NULL && "Game state cannot be null!");
  while (handCount > state->handCount[player]) {
    drawCard(player, state);
  }
  while (handCount < state->handCount[player]) {
    discardCard(state->handCount[player] - 1, player, state, 0);
  }
}

void randomizeDeck(GameState* state, Player player, unsigned int deckCount) {
  assert(state != NULL && "Game state cannot be null!");
  while (deckCount != state->deckCount[player]) {
    drawCard(player, state);
    int last = state->handCount[player] - 1;
    int card = state->hand[player][last];
    discardCard(last, player, state, 0);
    gainCard(card, state, 0, player);
  }
  shuffle(player, state);
}

void randomizeDiscard(GameState* state, Player player, unsigned int discardCount) {
  assert(state != NULL && "Game state cannot be null!");
  while (discardCount != state->discardCount[player]) {
    drawCard(player, state);
    int last = state->handCount[player] - 1;
    int card = state->hand[player][last];
    discardCard(last, player, state, 0);
    gainCard(card, state, 0, player);
  }
}
