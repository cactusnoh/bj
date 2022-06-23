#define SEED   100000

typedef struct list_node {
    struct list_node* link;
    int data;
} NODE;

NODE* getRandom(int, int, int*);
int  checkSortedData(NODE*);
void SwapData(NODE*, NODE*);
void QuickSortR(NODE*, NODE*);
NODE* PartitionR(NODE*, NODE*);
void QuickSortL(NODE*, NODE*);
NODE* PartitionL(NODE*, NODE*);
void SelectionSort(NODE*);
void BubbleSort(NODE*);
void printQue(NODE*);