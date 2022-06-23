#include <stdlib.h>
#include <stdio.h>
#include "Sort.h"


NODE* getRandom(int n, int check, int* signature)
{
    NODE* head = 0;

    if (check <= 0) {
        return NULL;
    }
    else {
        head = (NODE*)malloc(sizeof(NODE));
        head->data = rand() % n;
        (*signature) ^= head->data;
        head->link = getRandom(n, check - 1, signature);
        return head;
    }
}

/* Returns 1 if the data are sorted correctly */
int checkSortedData(NODE* head)
{
    int new_signature = 0;

    NODE* temp = head;
    while (temp != NULL) {
        if (temp->link == NULL)
            break;
        if (temp->data > temp->link->data)
            return 0;
        temp = temp->link;
    }
    return 1;
}

void SwapData(NODE* a, NODE* b) {
    int temp;
    temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void SelectionSort(NODE* head) {
    NODE* i = head;
    NODE* j = i->link;
    NODE* min = i;

    while (i && j) {
        while (j) {
            if (min->data > j->data) {
                min = j;
            }
            j = j->link;
        }
        SwapData(i, min);
        i = i->link;
        min = i;
        j = i->link;
    }
}

void BubbleSort(NODE* start)
{
    int swapped;
    NODE* ptr1;
    NODE* lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->link != lptr)
        {
            if (ptr1->data > ptr1->link->data)
            {
                SwapData(ptr1, ptr1->link);
                swapped = 1;
            }
            ptr1 = ptr1->link;
        }
        lptr = ptr1;
    } while (swapped);
}

void QuickSortR(NODE* left, NODE* right) {
    if (!left || left == right) {
        return;
    }

    NODE *partition = PartitionR(left, right);

    NODE *partition_prev = left;
    while(partition_prev != partition && partition_prev->link != partition) {
        partition_prev = partition_prev->link;
    }

    QuickSortR(left, partition_prev);
    if (partition != right) {
        QuickSortR(partition->link, right);
    }
}

NODE* PartitionR(NODE* left, NODE* right) {
    int pivot_data = right->data;

    NODE *i = left;
    NODE *j = left;

    while (1) {
        if (j->data < pivot_data) {
            SwapData(i, j);
            i = i->link;
        }
        j = j->link;
        if (j == right) {
            break;
        }
    }
    SwapData(right, i);

    return i;
}

void QuickSortL(NODE* left, NODE* right) {
    if (!left || left == right) {
        return;
    }

    NODE *partition = PartitionL(left, right);

    NODE *partition_prev = left;
    while(partition_prev != partition && partition_prev->link != partition) {
        partition_prev = partition_prev->link;
    }

    QuickSortL(left, partition_prev);
    if (partition != right) {
        QuickSortL(partition->link, right);
    }
}

NODE* PartitionL(NODE* left, NODE* right) {
    NODE *i = left;
    NODE *j = left->link;
    while (1) {
        if (j->data <= left->data) {
            i = i->link;
            SwapData(i, j);
        }
        if (j == right) {
            break;
        }
        j = j->link;
    }
    SwapData(left, i);

    return i;
}

void printQue(NODE* front) {

    NODE* temp = front;
    while (temp)
    {
        printf(" %d", temp->data);
        temp = temp->link;
    }
    printf("\n");
}