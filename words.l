%{
#include <stdio.h>

int lines = 1;
int words = 0;
int characters = 0;
%}

%%

\n          { lines++; characters++; }
[ \t]+      { characters += yyleng; }
[^\n\t ]+   { words++; characters += yyleng; }
.           { characters++; }

%%


int main() {
    FILE *file=fopen("input.txt","r");
    yyin=file;
    yylex();
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);
    return 0;
}

int yywrap() {
    return 1;
}
