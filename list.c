#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
    int data;
    struct Element* pnext;
} Element;

Element* newList() {
    Element* head = NULL;
    return head;
}

void prepend(int new, Element** oldhead) {
    Element* newhead = malloc(sizeof(Element));
    newhead->data = new;

    if (*oldhead == NULL)
    {
        newhead->pnext = NULL;
    } else {
        newhead->pnext = *oldhead;
    }
    *oldhead = newhead;
}

void shift(Element* head) {
    if (head->pnext == NULL) {
        free(head);
        head = NULL;
    } else
    {
        Element* newhead = head->pnext;
        free(head);
        Element oldhead = *head;
        *head = *head->pnext;
    }
}

int count(Element* head) {
    if (head == NULL) { return 0; }
    int count = 0;

    while (1) {
        count++;
        if (head->pnext == NULL) {
            return count;
        }
        free(head);
        head = head->pnext;
    }
}


int main() {
    Element* head = newList();
    prepend(1, &head);
    prepend(2, &head);
    prepend(3, &head);
    prepend(4, &head);
    shift(head);

    printf("%d\n", count(head)); // 3
    
    return 0;
}
