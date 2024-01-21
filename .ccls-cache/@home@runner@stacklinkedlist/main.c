#include <stdio.h>
#include <stdlib.h>

struct list {
    int num;
    struct list *prev;
};

struct list *push(struct list *h, struct list **c) {
    int numb;
    printf("Enter the Number for the list: ");
    scanf("%d", &numb);

    struct list *newnode = malloc(sizeof(struct list));
    newnode->num = numb;
    newnode->prev = *c;
    *c = newnode;

    return newnode;
}

void printList(struct list *top) {
    while (top->prev != NULL) {
        printf("%d ", top->num);
        top = top->prev;
    }
    printf("\n");
}

void freeList(struct list *top) {
    while (top != NULL) {
        struct list *next = top->prev;
        free(top);
        top = next;
    }
}

struct list* pop(struct list *top) {
    if (top == NULL) {
        printf("Stack is empty, cannot pop.\n");
        return NULL;
    }

    struct list *newTop = top->prev;
    printf("Popped element: %d\n", top->num);
    free(top);
    return newTop;
}

int main(void) {
    int n;
    struct list *tail;
    struct list *head;
    struct list *current;
    struct list *top = NULL;

    struct list *temp = malloc(sizeof(struct list));
    temp->num = 0;
    temp->prev = NULL;
    tail = temp;
    current = temp;

    printf("Enter How many lists You Want: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        top = push(head, &current);
    }

    printf("Numbers in the list: ");
    printList(top);

    top = pop(top);
    printf("Numbers in the list after popping: ");
    printList(top);
    freeList(top);

    return 0;
}
