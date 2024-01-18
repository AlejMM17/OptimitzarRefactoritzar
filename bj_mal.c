#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_CARDS 52
#define CARD_VALUES 13
#define MAX_HAND 10



int main() {

// Representation of the cards
char *values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
char *suits[] = {"Hearts", "Diamonds", "Spades", "Clubs"};

// Structure for a card
struct card {
    char *value;
    char *suit;
    int numericValue;
};

struct card deck[TOTAL_CARDS], playerHand[MAX_HAND];
int numPlayerCards = 0, playerSum = 0;
char choice;

    for (int i = 0; i < TOTAL_CARDS; i++) {
        deck[i].value = values[i % CARD_VALUES];
        deck[i].suit = suits[i / CARD_VALUES];
        deck[i].numericValue = (i % CARD_VALUES) + 2;
        if (deck[i].numericValue > 10) deck[i].numericValue = 10;
        if (i % CARD_VALUES == CARD_VALUES - 1) deck[i].numericValue = 11;
    }
    srand(time(NULL));
        for (int i = 0; i < TOTAL_CARDS; i++) {
            int j = rand() % TOTAL_CARDS;
            struct card temp = deck[i];
            deck[i] = deck[j];
        deck[j] = temp;
    }

    printf("Welcome to Blackjack!\n");

    playerHand[numPlayerCards++] = deck[0];
    playerHand[numPlayerCards++] = deck[1];

        playerSum += playerHand[0].numericValue;
        playerSum += playerHand[1].numericValue;

    printf("Your cards:\n");

    printf("  %s of %s\n", playerHand[0].value, playerHand[0].suit);
    printf("  %s of %s\n", playerHand[1].value, playerHand[1].suit);

    printf("Total sum: %d\n", playerSum);

    while (playerSum < 21) {
        printf("Do you want another card? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            playerHand[numPlayerCards] = deck[numPlayerCards + 1];
            playerSum += playerHand[numPlayerCards].numericValue;
            ++numPlayerCards;
            printf("New card:\n");
            printf("  %s of %s\n", playerHand[numPlayerCards - 1].value, playerHand[numPlayerCards - 1].suit);
            printf("Total sum: %d\n", playerSum);
        } else {
            break;
        }
    }

    if (playerSum == 21) {
        printf("¡Blackjack! You've won!.\n");
    } else if (playerSum > 21) {
        printf(" You've gone too far. End of the game. \n");
    } else {
        printf("You've fold with %d. End of the game.\n", playerSum);
    }

    return 0;
}
