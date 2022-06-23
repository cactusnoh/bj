#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

int main(void)
{
    int  n, rand_sig = 0, worst_sig = 0;
    NODE* head = 0;
    NODE* tail = 0;
    NODE* temp;

    double select_exe = 0;
    double bubble_exe = 0;
    double quickR_exe = 0;
    double quickL_exe = 0;

    clock_t start, end;

    putchar('\n');

    /* enter size of data array and prepare memory */
    printf("Enter size of array : ");
    scanf("%d", &n);
    putchar('\n');

    printf("\nSelection Sorting...\n");
    /* generate integer data by random number generation */
    srand((unsigned int)time(NULL));
    head = getRandom(n, n, &rand_sig);

    //Selection Sort

    start = clock();
    SelectionSort(head);
    end = clock();
    select_exe += ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    if (checkSortedData(head))
        printf("Sorting is okay\n\n");
    else
        printf("Sorting is wrong\n\n");

    printf("Sorting time for selection sort is %fms\n", select_exe);

    printf("==================================================\n");
    printf("\nBubble Sorting...\n");

    /* generate integer data by random number generation */
    srand((unsigned int)time(NULL));
    head = getRandom(n, n, &rand_sig);

    //Bubble Sort

    start = clock();
    BubbleSort(head);
    end = clock();
    bubble_exe += ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    if (checkSortedData(head))
        printf("Sorting is okay\n\n");
    else
        printf("Sorting is wrong\n\n");

    printf("Sorting time for Bubble Sort is %fms\n", bubble_exe);

    printf("==================================================\n");
    printf("\nQuick Sorting (Right-most)...\n");

    /* generate integer data by random number generation */
    srand((unsigned int)time(NULL));
    head = getRandom(n, n, &rand_sig);

    // Find tail node
    temp = head;
    while (temp) {
       tail = temp;
       temp = temp->link;
    }

    // Quick Sort (Right-most)

    start = clock();
    QuickSortR(head, tail);
    end = clock();
    quickR_exe += ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    if (checkSortedData(head))
       printf("Sorting is okay\n\n");
    else
       printf("Sorting is wrong\n\n");

    printf("Sorting time for QuickSort(Right-most) is %fms\n", quickR_exe);

    printf("==================================================\n");
    printf("\nQuick Sorting (Left-most)...\n");

    /* generate integer data by random number generation */
    srand((unsigned int)time(NULL));
    head = getRandom(n, n, &rand_sig);

    // Find tail node
    temp = head;
    while (temp) {
        tail = temp;
        temp = temp->link;
    }

    // Quick Sort (Left-most)

    start = clock();
    QuickSortL(head, tail);
    end = clock();
    quickL_exe += ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    
    if (checkSortedData(head))
        printf("Sorting is okay\n\n");
    else
        printf("Sorting is wrong\n\n");

    printf("Sorting time for QuickSort(Left-most) is %fms\n", quickL_exe);
}