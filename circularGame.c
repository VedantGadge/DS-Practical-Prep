#include <stdio.h>
#include <conio.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *createCircularList(int n)
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->val = 1;
    struct Node *prev = head;

    for (int i = 2; i <= n; i++)
    {
        struct Node *node = (struct Node *)(malloc(sizeof(struct Node)));
        node->val = i;
        prev->next = node;
        prev = node;
    }

    prev->next = head;
    return head;
}

int findTheWinner(int n, int k)
{
    struct Node *head = createCircularList(n);

    while (head->next != head)
    {
        for (int i = 1; i < k; i++)
        {
            head = head->next;
        }

        // Find the node before 'head' (i.e., prev)
        struct Node *prev = head;
        while (prev->next != head)
        {
            prev = prev->next;
        }

        // Remove current head
        prev->next = head->next;
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    int winner = head->val;
    free(head);
    return winner;
}

int main() {
    int n = 5, k = 2;
    printf("The winner is: %d\n", findTheWinner(n, k));
    return 0;
}