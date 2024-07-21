#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Global variables
int b[MAX] = {10, 20, 30, 40}; // Prepopulated array with elements 10, 20, 30, and 40
int n = 4;  // Number of elements in the array initially

// Function prototypes
void create();
void insert();
void deletion();
void search();
void display();

int main()
{
    int ch;
    char g = 'y';

    do
    {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0); // Exit the program
            default:
                printf("\nEnter the correct choice.\n");
        }

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g);
    }
    while(g == 'y' || g == 'Y');

    return 0;
}

void create()
{
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Number of elements exceeds the maximum limit of %d.\n", MAX);
        n = 0;
        return;
    }

    printf("\nEnter %d elements:\n", n);
    for(int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion()
{
    if (n == 0)
    {
        printf("\nThe list is empty, nothing to delete.\n");
        return;
    }

    int e, pos = -1;
    printf("\nEnter the element to delete: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++)
    {
        if (b[i] == e)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        printf("\nElement %d not found in the list.\n", e);
    }
    else
    {
        for (int i = pos; i < n - 1; i++)
        {
            b[i] = b[i + 1];
        }
        n--;
        printf("\nElement %d deleted from the list.\n", e);
    }

    display();
}

void search()
{
    if (n == 0)
    {
        printf("\nThe list is empty.\n");
        return;
    }

    int e, found = 0;
    printf("\nEnter the element to search: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++)
    {
        if (b[i] == e)
        {
            printf("Element %d found at position %d.\n", e, i);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Element %d not found in the list.\n", e);
    }
}

void insert()
{
    if (n == MAX)
    {
        printf("\nThe list is full, cannot insert any more elements.\n");
        return;
    }

    int pos, p;
    printf("\nEnter the position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n)
    {
        printf("\nInvalid position!\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &p);

    for (int i = n - 1; i >= pos; i--)
    {
        b[i + 1] = b[i];
    }
    b[pos] = p;
    n++;

    printf("\nElement %d inserted at position %d.\n", p, pos);
    display();
}

void display()
{
    if (n == 0)
    {
        printf("\nThe list is empty.\n");
        return;
    }

    printf("\nThe elements of the list are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
return 0;
}
