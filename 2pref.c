#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define SIZE 20

/*
struct stack
push
pop
operate
eval
main
*/

struct stack
{
    int top;
    float data[SIZE];
};
typedef struct stack STACK;

void push(STACK *s, float item)
{
    if (s->top == SIZE - 1)
    {
        printf("Invalid prefix expression\n");
        exit(1);
    }
    s->data[++(s->top)] = item;
}

float pop(STACK *s)
{
    if (s->top == -1)
    {
        printf("Invalid prefix expression\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

float operate(float op1, float op2, char symbol)
{
    switch (symbol)
    {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/':
            if (op2 == 0)
            {
                printf("Division by zero\n");
                exit(1);
            }
            return op1 / op2;
        case '^':
        case '$': return pow(op1, op2);
        default:
            printf("Invalid prefix expression\n");
            exit(1);
    }
}

float eval(STACK *s, char prefix[SIZE])
{
    int i;
    char symbol;
    float op1, op2, res;

    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        symbol = prefix[i];

        if (symbol == ' ')
            continue;

        if (isdigit(symbol))
        {
            push(s, symbol - '0');
        }
        else
        {
            /* Must have at least two operands */
            if (s->top < 1)
            {
                printf("Invalid prefix expression\n");
                exit(1);
            }

            op1 = pop(s);
            op2 = pop(s);
            res = operate(op1, op2, symbol);
            push(s, res);
        }
    }

    /* After evaluation, exactly ONE value must remain */
    if (s->top != 0)
    {
        printf("Invalid prefix expression\n");
        exit(1);
    }

    return pop(s);
}

int main()
{
    char prefix[SIZE];
    STACK s;
    float ans;

    s.top = -1;

    printf("Enter prefix expression: ");
    scanf("%[^\n]", prefix);

    ans = eval(&s, prefix);

    printf("The final answer is: %.2f\n", ans);
    return 0;
}
