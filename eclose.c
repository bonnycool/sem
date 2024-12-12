#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char result[20][20], copy[3], states[20][20];

void addstate(char a[3], int i) {
    strcpy(result[i], a);
}

void print(int n) {
    int k = 0;
    printf("epsilon closure of %s: { ", copy);
    while (k < n) {
        printf("%s ", result[k]);
        k++;
    }
    printf("}\n");
}

int main() {
    FILE *INPUT;
    INPUT = fopen("e.txt", "r");
    if (INPUT == NULL) {
        perror("Error opening file");
        return 1;
    }

    char state[3];
    char state1[3], input[3], state2[3];
    int end, i, k, n;

    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("Enter the states:\n");
    for (k = 0; k < n; k++) {
        scanf("%s", states[k]);
    }

    for (k = 0; k < n; k++) {
        i = 0;
        strcpy(state, states[k]);
        strcpy(copy, state);
        addstate(state, i++);

        while (1) {
            end = fscanf(INPUT, "%s %s %s", state1, input, state2);
            if (end == EOF) {
                break;
            }

            if (strcmp(state, state1) == 0) {
                if (strcmp(input, "e") == 0) {
                    addstate(state2, i++);
                    strcpy(state, state2);
                }
            }
        }

        rewind(INPUT);
        print(i);
    }

    fclose(INPUT);
    return 0;
}
