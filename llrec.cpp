#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    if(head == NULL) {
        smaller = NULL;
        larger = NULL;
        return;
    }

    Node* current = head;
    head = head->next;
    llpivot(head, smaller, larger, pivot)

    if(current->val <= pivot) {
        current->next = smaller;
        smaller = current;
    }
    else {
        current->next = larger;
        larger = current;
    }
}

