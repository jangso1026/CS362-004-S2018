#include "dominion.h"

typedef enum { false, true } bool;

typedef struct gameState GameState;

typedef unsigned int Player;

typedef enum CARD Card;

void printGameState(GameState* state, Player player);

void randomizeHand(GameState* state, Player player, unsigned int handCount);

void randomizeDeck(GameState* state, Player player, unsigned int deckCount);

void randomizeDiscard(GameState* state, Player player, unsigned int discardCount);
