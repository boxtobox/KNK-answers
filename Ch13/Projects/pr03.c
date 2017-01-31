#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
	bool in_hand[NUM_SUITS][NUM_RANKS] = { false };
	int num_cards, rank, suit;
	const char rank_code[][6] =
	{"Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King", "Ace" };
	const char suit_code[][9] = { "clubs" , "diamonds" , "hearts", "spades" };
	srand((unsigned)time(NULL));	/* passing return value of time avoids dealing same cards everytime we run the program*/
	printf("Enter number of cards in hand: ");
	scanf("%d", &num_cards);
    if (num_cards < 0 || num_cards > 52) {
        printf("Enter an integer between 1 and 52\n");
        return 1;
    }

	printf("Your hand:\n");
	while (num_cards > 0) {
		suit = rand() % NUM_SUITS;	/* picks a random suit */
		rank = rand() % NUM_RANKS;	/* picks a random rank */
		if (!in_hand[suit][rank]) {
			in_hand[suit][rank] = true;
			num_cards--;
			printf("%s of %s\n", rank_code[rank], suit_code[suit]);
		}
	}
	return 0;
}
