#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/*
struct node
insertend
deletebegin
display
main
*/

int count = 0;

struct node
{
    int data;
    struct node *addr;
};

typedef struct node *NODE;

/* Insert at rear (enqueue) */
NODE insertend(NODE last, int item)
{
    NODE temp;

    if (count >= SIZE)
    {
        printf("\n Queue full");
        return last;
    }

    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;

    if (last == NULL)
    {
        temp->addr = temp;
        count++;
        return temp;
    }
    else
    {
        temp->addr = last->addr;
        last->addr = temp;
        count++;
        return temp;
    }
}

/* Delete from front (dequeue) */
NODE deletebegin(NODE last)
{
    NODE temp;

    if (last == NULL)
    {
        printf("\n Queue empty");
        return NULL;
    }

    if (last->addr == last)
    {
        printf("\n Element deleted is %d\n", last->data);
        free(last);
        count--;
        return NULL;
    }
    else
    {
        temp = last->addr;
        last->addr = temp->addr;
        printf("\n Element deleted is %d\n", temp->data);
        free(temp);
        count--;
        return last;
    }
}

/* Display queue */
void display(NODE last)
{
    NODE temp;

    if (last == NULL)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("\n Queue contents are:\n");
        temp = last->addr;

        while (temp != last)
        {
            printf("%d\t", temp->data);
            temp = temp->addr;
        }
        printf("%d\t", temp->data);
    }
}

int main()
{
    NODE last = NULL;
    int item, ch;

    for (;;)
    {
        printf("\n\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nRead Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("\n Read data to be inserted: ");
                scanf("%d", &item);
                last = insertend(last, item);
                break;

            case 2:
                last = deletebegin(last);
                break;

            case 3:
                display(last);
                break;

            case 4:
                exit(0);

            default:
                printf("\n Invalid choice");
        }
    }

    return 0;
}
