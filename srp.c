#include <stdio.h>
#include <string.h>

struct ProductionRule {
    char left[10];
    char right[10];
};

int main() {
    char input[50], stack[50] = "", temp[50], token[3];
    int i, j, stack_length, substring_length, stack_top, rule_count = 0;
    struct ProductionRule rules[10];

    printf("Enter the number of production rules: ");
    scanf("%d", &rule_count);

    printf("Enter the production rules (in the form 'left->right'):\n");
    for (i = 0; i < rule_count; i++) {
        scanf("%s", temp);
        char *token1 = strtok(temp, "!>");
        char *token2 = strtok(NULL, "!>");
        strcpy(rules[i].left, token1);
        strcpy(rules[i].right, token2);
    }

    printf("Enter the input string: ");
    scanf("%s", input);

    i = 0;
    while (1) {
        if (i < strlen(input)) {
            if (input[i] == 'i' && input[i + 1] == 'd') {
                strcpy(token, "id");
                token[2] = '\0';
                i += 2;
            } else {
                token[0] = input[i];
                token[1] = '\0';
                i++;
            }
            strcat(stack, token);

            printf("%s\t", stack);
            for (int k = i; k < strlen(input); k++) {
                printf("%c", input[k]);
            }
            printf("\tShift %s\n", token);
        }
        for (j = 0; j < rule_count; j++) {
            char *substring = strstr(stack, rules[j].right);
            if (substring != NULL) {
                stack_length = strlen(stack);
                substring_length = strlen(substring);
                stack_top = stack_length - substring_length;

                stack[stack_top] = '\0';
                strcat(stack, rules[j].left);

                printf("%s\t", stack);
                for (int k = i; k < strlen(input); k++) {
                    printf("%c", input[k]);
                }
                printf("\tReduce %s!>%s\n", rules[j].left, rules[j].right);

                j = -1; 
            }
        }
        if (strcmp(stack, rules[0].left) == 0 && i == strlen(input)) {
            printf("\nAccepted\n");
            break;
        }
        if (i == strlen(input)) {
            printf("\nNot Accepted\n");
            break;
        }
    }

    return 0;
}
