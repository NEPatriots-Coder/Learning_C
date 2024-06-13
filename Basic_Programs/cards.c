// Las Vegas Style Blackjack!!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define DECKS 6
#define CARDS_PER_DECK 52
#define MAX_CARDS (DECKS * CARDS_PER_DECK)
#define MAX_BET 20
#define STARTING_BANK 1000

#define MIN(a, b) ((a) < (b) ? (a) : (b))
//Enumeration (or enum) is a user defined data type in C. It is mainly used to assign names to integral constants,
// the names make a program easy to read and maintain. 'Geeks for Geeks
typedef enum {
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
} Face;

typedef enum {
    HEARTS, DIAMONDS, CLUBS, SPADES
} Suit;

typedef struct {
    Face face;
    Suit suit;
} Card;

void initializeDeck(Card *deck);
void shuffleDeck(Card *deck);
int getCardValue(Card card);
void printCard(Card card);
int getCardScore(Card card);
int getHandScore(Card *hand, int numCards);
void printHand(Card *hand, int numCards);
void dealInitialCards(Card *deck, Card *playerHand, Card *dealerHand);
void playerTurn(Card *deck, Card *playerHand, Card *dealerHand, int *playerScore, int *bank, int *bet);
void dealerTurn(Card *deck, Card *dealerHand, int *dealerScore);
void displayResult(int playerScore, int dealerScore, int *bank, int bet);
void getBet(int *bet, int bank);
void checkBetAndInitializeDeck(int bet, int bank, Card *deck, int *invalidBet);
void playGame(Card *deck, Card *playerHand, Card *dealerHand, int *playerScore, int *dealerScore, int *bank, int bet);

int main() {
    Card deck[MAX_CARDS];
    Card playerHand[MAX_CARDS];
    Card dealerHand[MAX_CARDS];
    int playerScore, dealerScore, bank = STARTING_BANK, bet;
    int invalidBet = 0;

    srand(time(NULL));

    printf("Welcome to Blackjack!\n");
    while (bank > 0) {
        getBet(&bet, bank);
        if (bet == 0) {
            printf("Thanks for playing! You're leaving with $%d.\n", bank);
            break;
        }

        checkBetAndInitializeDeck(bet, bank, deck, &invalidBet);
        if (invalidBet) {
            break;
        }

        playGame(deck, playerHand, dealerHand, &playerScore, &dealerScore, &bank, bet);
        if (bet == INT_MAX) {
            break;
        }

        printf("Bank: $%d\n", bank);
    }

    if (bank <= 0) {
        printf("You're out of money! Better luck next time.\n");
    }

    return 0;
}

void getBet(int *bet, int bank) {
    if (bet == NULL) {
        printf("Error: your bet is not valid.\n");
        return;
    }
    printf("Bank : $%d\n", bank);

    int betLimit = bank > MAX_BET ? MAX_BET : bank;
    printf("Enter a bet (up to $%d, or 0 to quit): ", betLimit);

    int res = scanf("%d", bet);

    if (res != 1) {
        printf("Invalid bet format. Exiting Game.\n");
        *bet = INT_MAX;
    } else if (*bet < 0 || *bet > betLimit) {
        printf("Invalid bet amount. Exiting Game.\n");
        *bet = INT_MAX;
    }
}

void checkBetAndInitializeDeck(int bet, int bank, Card *deck, int *invalidBet) {
    if (bet > MIN(bank, MAX_BET)) {
        printf("Your bet exceeds available bet or balance. Call Vinny for a loan\n");
        *invalidBet = 1;
        return;
    }

    initializeDeck(deck);
    shuffleDeck(deck);
}

void playGame(Card *deck, Card *playerHand, Card *dealerHand, int *playerScore, int *dealerScore, int *bank, int bet) {
    dealInitialCards(deck, playerHand, dealerHand);
    playerTurn(deck, playerHand, dealerHand, playerScore, bank, &bet);
    if (*playerScore <= 21) {
        dealerTurn(deck, dealerHand, dealerScore);
        displayResult(*playerScore, *dealerScore,  bank, bet);  // Pass bank as a pointer
    } else {
        printf("Player busts! Dealer Wins\n");
        *bank -= bet;
    }
}


void initializeDeck(Card *deck) {
    int i, j, index = 0;
    for (i = 0; i < DECKS; i++) {
        for (j = ACE; j <= KING; j++) {
            deck[index].face = (Face)j;
            deck[index].suit = HEARTS;
            index++;
            deck[index].face = (Face)j;
            deck[index].suit = DIAMONDS;
            index++;
            deck[index].face = (Face)j;
            deck[index].suit = CLUBS;
            index++;
            deck[index].face = (Face)j;
            deck[index].suit = SPADES;
            index++;
        }
    }
}

void shuffleDeck(Card *deck) {
    int i, j;
    Card temp;
    for (i = 0; i < MAX_CARDS; i++) {
        j = rand() % MAX_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int getCardValue(Card card) {
    switch (card.face) {
        case JACK:
        case QUEEN:
        case KING:
            return 10;
        default:
            return card.face;
    }
}

void printCard(Card card) {
    switch (card.face) {
        case ACE:
            printf("A");
            break;
        case JACK:
            printf("J");
            break;
        case QUEEN:
            printf("Q");
            break;
        case KING:
            printf("K");
            break;
        default:
            printf("%d", card.face);
            break;
    }

    switch (card.suit) {
        case HEARTS:
            printf("H");
            break;
        case DIAMONDS:
            printf("D");
            break;
        case CLUBS:
            printf("C");
            break;
        case SPADES:
            printf("S");
            break;
    }
}

int getCardScore(Card card) {
    if (card.face == ACE)
        return 11;
    return getCardValue(card);
}

int getHandScore(Card *hand, int numCards) {
    int score = 0;
    int numAces = 0;
    for (int i = 0; i < numCards; i++) {
        score += getCardScore(hand[i]);
        if (hand[i].face == ACE)
            numAces++;
    }
    while (score > 21 && numAces > 0) {
        score -= 10;
        numAces--;
    }
    return score;
}

void printHand(Card *hand, int numCards) {
    for (int i = 0; i < numCards; i++) {
        printCard(hand[i]);
        printf(" ");
    }
    printf("\n");
}

void dealInitialCards(Card *deck, Card *playerHand, Card *dealerHand) {
    playerHand[0] = deck[0];
    playerHand[1] = deck[1];
    dealerHand[0] = deck[2];
    dealerHand[1] = deck[3];
    printf("Player's hand: ");
    printHand(playerHand, 2);
    printf("Dealer's hand: ");
    printCard(dealerHand[0]);
    printf(" * \n");
}

void playerTurn(Card *deck, Card *playerHand, Card *dealerHand, int *playerScore, int *bank, int *bet) {
    int numCards = 2;
    *playerScore = getHandScore(playerHand, numCards);
    char choice;
    do {
        printf("Hit (H) or Stand (S)? ");
        scanf(" %c", &choice);
        if (choice == 'H' || choice == 'h') {
            playerHand[numCards++] = deck[numCards + 1];
            printf("Player's hand: ");
            printHand(playerHand, numCards);
            *playerScore = getHandScore(playerHand, numCards);
            if (*playerScore > 21) {
                break;
            }
        } else if ((choice == 'D' || choice == 'd') && *playerScore == 11 && *bet <= (MIN(*bank, MAX_BET) / 2)) {
            printf("Doubling down!\n");
            *bet *= 2;
            playerHand[numCards++] = deck[numCards + 1];
            printf("Player's hand: ");
            printHand(playerHand, numCards);
            *playerScore = getHandScore(playerHand, numCards);
            break;
        }
    } while (choice == 'H' || choice == 'h');
}

void dealerTurn(Card *deck, Card *dealerHand, int *dealerScore) {
    int numCards = 2;
    *dealerScore = getHandScore(dealerHand, numCards);
    printf("Dealer's hand: ");
    printHand(dealerHand, numCards);
    while (*dealerScore < 17) {
        dealerHand[numCards++] = deck[numCards + 1];
        *dealerScore = getHandScore(dealerHand, numCards);
        printf("Dealer hits. Dealer's hand: ");
        printHand(dealerHand, numCards);
    }
    if (*dealerScore > 21) {
        printf("Dealer busts!\n");
    } else {
        printf("Dealer stands.\n");
    }
}



/**
 * Function to display results of a gambling game.
 * @param playerScore: Final score of player.
 * @param dealerScore: Final score of dealer.
 * @param bank: Pointer to current bank balance.
 * @param bet: Current bet value.
 */

void displayResult(int playerScore, int dealerScore, int *bank, int bet) {
    // Invalid parameters
    if (bank == NULL) {
        printf("Bank pointer is NULL.\n");
        return;
    }
    if (bet < 0 || bet > *bank) {
        printf("Invalid bet value.\n");
        return;
    }
    if (playerScore < 0 || playerScore > 21 || dealerScore < 0 || dealerScore > 21) {
        printf("Invalid player or dealer score.\n");
        return;
    }

    printf("Player's final score: %d\n", playerScore);
    printf("Dealer's final score: %d\n", dealerScore);

    // Player wins
    if ((playerScore <= 21 && playerScore > dealerScore) || dealerScore > 21) {
        printf("Player wins $%d!\n", bet);
        *bank += bet;  // Increment bank balance by the bet amount
    }
        // Dealer wins
    else if ((dealerScore <= 21 && dealerScore > playerScore) || playerScore > 21) {
        printf("Dealer wins. You lose $%d.\n", bet);
        *bank -= bet;  // Decrement bank balance by the bet amount
    }
        // Tie
    else {
        printf("It's a tie. Your bet is returned.\n");
    }
}
