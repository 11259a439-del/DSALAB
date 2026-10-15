#include <stdio.h>
#include <ctype.h>
#include <string.h>

char s[100]; int top = -1;

int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void push(char c) { s[++top] = c; }
char pop() { return s[top--]; }

int main() {
    char in[100], out[100]; int k = 0;
    scanf("%s", in);

    for (int i = 0; in[i]; i++) {
        char c = in[i];

        if (isalnum(c)) out[k++] = c;
        else if (c == '(') push(c);
        else if (c == ')') {
            while (s[top] != '(') out[k++] = pop();
            pop();
        }
        else {
            while (top >= 0 && priority(s[top]) >= priority(c))
                out[k++] = pop();
            push(c);
        }
    }

    while (top >= 0) out[k++] = pop();
    out[k] = '\0';

    printf("Postfix: %s", out);
    return 0;
}

