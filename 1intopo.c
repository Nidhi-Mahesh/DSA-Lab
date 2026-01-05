    /*struct stack
    push
    pop
    F
    G
    Validate
    infix_postfix
    main
    */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 20

struct stack 
{
    int top;
    char data[SIZE];
};

typedef struct stack STACK;

/* -------- push -------- */
void push(STACK *s, char item)
{
    if (s->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = item;
}

/* -------- pop -------- */
char pop(STACK *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

/* -------- F -------- */
int F(char symbol)
{
    switch (symbol)
    {
        case '^':
        case '$': return 6;
        case '*':
        case '/': return 4;
        case '+':
        case '-': return 2;
        case '(':
        case '#': return 0;
        default:  return 8;
    }
}

/* -------- G -------- */
int G(char symbol)
{
    switch (symbol)
    {
        case '^':
        case '$': return 5;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 1;
        case ')':
        case '#': return 0;
        case '(': return 7;
        default:  return 9;
    }
}

/* -------- Validate -------- */
int Validate(char *infix)
{
    int i = 0, balance = 0;
    char prev = '\0';

    while (infix[i] != '\0')
    {
        char curr = infix[i];

        if (!isalnum(curr) && curr != '+' && curr != '-' &&
            curr != '*' && curr != '/' && curr != '^' &&
            curr != '$' && curr != '(' && curr != ')')
            return 0;

        if (curr == '(')
            balance++;
        else if (curr == ')')
            balance--;

        if (balance < 0)
            return 0;

        if ((curr == '+' || curr == '-' || curr == '*' ||
             curr == '/' || curr == '^' || curr == '$') &&
            (i == 0 || infix[i + 1] == '\0' ||
             prev == '+' || prev == '-' || prev == '*' ||
             prev == '/' || prev == '^' || prev == '$' ||
             prev == '('))
            return 0;

        if (isalnum(curr) && isalnum(prev))
            return 0;

        prev = curr;
        i++;
    }

    if (balance != 0)
        return 0;

    return 1;
}

/* -------- infix to postfix -------- */
void infix_postfix(char *infix, char *postfix)
{
    STACK s;
    s.top = -1;

    int i, j = 0;
    char symbol;

    push(&s, '#');

    for (i = 0; infix[i] != '\0'; i++)
    {
        symbol = infix[i];

        if (isalnum(symbol))
        {
            postfix[j++] = symbol;
        }
        else
        {
            while (F(s.data[s.top]) > G(symbol))
            {
                postfix[j++] = pop(&s);
            }

            if (F(s.data[s.top]) != G(symbol))
                push(&s, symbol);
            else
                pop(&s);   // removes '('
        }
    }

    while (s.data[s.top] != '#')
    {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}

/* -------- main -------- */
int main()
{
    char infix[SIZE], postfix[SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    if (!Validate(infix))
    {
        printf("Invalid infix expression\n");
        return 0;
    }

    infix_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}

    