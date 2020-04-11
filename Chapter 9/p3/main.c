#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ACTIONS 4

void generate_random_walk(char walk[][*]);
void print_array(char walk[10][10]);

int main()
{
    char walk[10][10];
    generate_random_walk(walk);
    print_array(walk);


    return 0;
}

void generate_random_walk(char walk[10][10]) {
    for (int i = 0; i< 10; i++) {
        for (int j = 0; j<10; j++) {
            walk[i][j] = '.';
        }
    }
    char c = 'A';
    int i =0, j = 0;
    int new_i=0, new_j = 0;
    int action = 0;
    srand((unsigned int) time(NULL));
    while (c <= 'Z') {
        if (c == 'A') {
            walk[i][j] = c;
        } else {
            //  Randomly choose action
            action = rand() % ACTIONS;
            // Check if next state is taken
            int totalTry = 0; // If equal to ACTIONS, meaning there is no available positions to be taken
            while (1) {
                switch (action) {
                    case 0: new_i = i - 1, new_j = j;break; // up
                    case 1: new_i = i + 1, new_j = j;break; // down
                    case 2: new_i = i, new_j = j - 1;break; // left
                    case 3: new_i = i, new_j = j + 1;break; // right
                    default: printf("Random generator wrong\n"); break;
                }
                if (new_i >= 0 && new_i <= 9 && new_j >= 0 && new_j <= 9) {
                    if (walk[new_i][new_j] == '.') // Great, no taken
                        break;
                }
                action = (action+1) % ACTIONS;
                totalTry += 1;
                if (totalTry == 4)
                    break;
            }
            if (totalTry < 4) {
                walk[new_i][new_j] = c;
                i = new_i, j = new_j;
            } else // Fail when no actions possible
                break;
        }
        c++;
    }
    return ;
}

void print_array(char walk[10][10]) {
    int i = 0, j = 0;
    for (i = 0; i< 10; i++) {
        for (j = 0; j<10; j++) {
            printf("%c ", walk[i][j]);
        }
        printf("\n");
    }
    return;
}
