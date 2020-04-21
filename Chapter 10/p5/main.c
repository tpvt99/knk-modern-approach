#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5


bool straight, flush, four, three, royal;
int pairs;

/* prototype */
void read_cards(int [][*]);
void analyze_hand(int [][*]);
void print_result(void);


int main()
{
    int hands[NUM_CARDS][2];
    for (;;) {
        read_cards(hands);
        analyze_hand(hands);
        print_result();
    }
    return 0;
}

void read_cards(int hands[NUM_CARDS][2]) {
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;
    int counter = 0;

    for (counter = 0; counter < NUM_CARDS; counter ++) {
        hands[counter][0] = 0;
        hands[counter][1] = 0;
    }

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch(rank_ch) {
            case '0':       exit(EXIT_SUCCESS);
            case '2':       rank = 0; break;
            case '3':       rank = 1; break;
            case '4':       rank = 2; break;
            case '5':       rank = 3; break;
            case '6':       rank = 4; break;
            case '7':       rank = 5; break;
            case '8':       rank = 6; break;
            case '9':       rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default:            bad_card = true;
        }

        suit_ch = getchar();

        switch(suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default:            bad_card = true;

        }

        while ((ch=getchar()) != '\n')
            if (ch != ' ')
                bad_card = true;

        if (bad_card) {
            printf("Bad card; ignored.\n");
            continue;
        }

        // check card exists
        for (counter = 0; counter < cards_read; counter++) {
            if (rank == hands[counter][0] && suit == hands[counter][1]) {
                printf("Duplicated card; ignored.\n");
                break;
            }
        }

        if (counter == cards_read) {// means that there is no duplicated
            hands[cards_read][0] = rank;
            hands[cards_read][1] = suit;
            cards_read++;
        }
    }

    for (counter = 0; counter < NUM_CARDS; counter ++) {
        printf("hands[%d]: rank: %d, suit: %d\n", counter, hands[counter][0], hands[counter][1]);
    }
}

void analyze_hand(int hands[NUM_CARDS][2]) {
    int num_consec = 1;
    int rank, suit;
    straight = flush = four = three = royal = false;
    pairs = 0;

    /* Sort the hands by ranking, smaller comes first */
    int card = 0;
    for (card = 0; card < NUM_CARDS-1; card++) {
        int index = card, temp_rank, temp_suit;
        for (int next_card = card+1; next_card < NUM_CARDS; next_card++)
            if (hands[next_card][0] < hands[index][0])
                index = next_card;
        temp_rank = hands[card][0];
        temp_suit = hands[card][1];
        hands[card][0] = hands[index][0];
        hands[card][1] = hands[index][1];
        hands[index][0] = temp_rank;
        hands[index][1] = temp_suit;
    }

    for (card = 0; card < NUM_CARDS; card ++) {
        printf("Sorting hands[%d]: rank: %d, suit: %d\n", card, hands[card][0], hands[card][1]);
    }

    /* check for flush */
    for (suit = 0; suit < NUM_SUITS; suit++) {
        int card;
        for (card = 0; card < NUM_CARDS; card++)
            if (hands[card][1] != suit)
                break;
        if (card == NUM_CARDS) /* NO BREAK MEANS THAT ALL CARDS = SUIT */
            flush = true;
    }

    /* check for royal */
    for (card = 0; card < NUM_CARDS; card++)
        if (hands[card][0] != (8+card)) // 8 is the rank of ten
            break;
    if (card == NUM_CARDS)
        royal = true;

    printf("Flush check: %d\n", flush);
    /* check for straight */


    for (card = 1; card < NUM_CARDS; card++) {
        if (hands[card][0] == (hands[card-1][0]+1))
            num_consec++;
        if (hands[card][0] == hands[card-1][0])
            pairs += 1;
    }
    if (num_consec == NUM_CARDS) {
        straight = true;
        return;
    }

    /* check for ace-low straight */

    if (hands[NUM_CARDS-1][0] == 12)
        straight = true;

    printf("Straight check: %d\n", straight);

    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    for (rank = 0; rank < NUM_RANKS; rank++) {
        int card, counts=0;
        for (card = 0; card < NUM_CARDS; card++)
            if (hands[card][0] == rank)
                counts++;
        if (counts == 4) four = true;
        if (counts == 3) three = true;
    }

    printf("Four check: %d\n", four);
    printf("Three check: %d\n", three);
    printf("Pair check: %d\n", pairs);

}

void print_result(void) {
    if (royal && flush) printf("Royal Flush");
    else if (straight && flush) printf("Straight flush");
    else if (four)  printf("Four of a kind");
    else if (three && pairs == 1)   printf("Full house");
    else if (flush) printf("Flush");
    else if (straight)  printf("Straight");
    else if (three)     printf("Three of a kind");
    else if (pairs == 2)    printf("Two pairs");
    else if (pairs == 1)    printf("Pair");
    else                    printf("High card");
    printf("\n");
}
