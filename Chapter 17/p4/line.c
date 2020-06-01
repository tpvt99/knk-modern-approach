#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct single_word {
    char *word;
    struct single_word *next;
};

struct single_word *line = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void) {
    if (line != NULL) {
        struct single_word *curr = line->next, *prev = line;
        for(;curr!= NULL; prev=curr, curr=curr->next)
            free(prev);
        free(prev);
        line = NULL;
    }

    line_len = 0;
    num_words = 0;
}

void add_word(const char *word) {
    struct single_word *next_word = malloc(sizeof(struct single_word));
    if (next_word == NULL) {
        printf("No enough space in allocation struct single_word\n");
        return;
    }
    next_word->word = malloc(strlen(word) + 1);
    if (next_word->word == NULL) {
        printf("No enough space in allocation string memory\n");
        return;
    }
    strcpy(next_word->word, word);
    struct single_word *curr = line, *prev = NULL;
    for(;curr!= NULL; prev=curr, curr=curr->next)
        ;
    if (prev == NULL) { // first word
        next_word->next = line;
        line = next_word;
    } else {
        prev->next = next_word;
        next_word->next = curr;
    }

    line_len += strlen(word);
    num_words++;
}

int space_remaining(void) {
    return MAX_LINE_LEN - line_len;
}

void flush_line(void) {
    if (line_len > 0) {
        for (struct single_word *head = line; head != NULL; head = head->next) {
            printf(head->word);
            if (head->next != NULL)
                printf(" ");
        }
    }

}

void write_line(void) {
    int extra_spaces, spaces_to_insert, j;

    extra_spaces = MAX_LINE_LEN - line_len;
    struct single_word *head = line;
    for (;head != NULL;head=head->next) {
        printf("%s", head->word);
        spaces_to_insert = extra_spaces / (num_words-1);
        for (j=1;j<=spaces_to_insert+1;j++)
            putchar(' ');
        extra_spaces -= spaces_to_insert;
        num_words-=1;
    }
    putchar('\n');
}

void print_line(void) {
    printf("h->");
    for (struct single_word *head = line; head != NULL; head = head->next) {
        printf(head->word);
    }
    printf("->NULL\n");
}
