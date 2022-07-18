#include "pQueue.h"

// 1. Place (x, k) at the end of array
// 2. Update minPos
void PQueue::insert(int x,int key)
{
    arr[len++] = node(x, key);
    if (minPos == -1 || arr[minPos].key > key)
        minPos = len - 1;
}

node PQueue::removeMin()
{
    swap(arr[--len], arr[minPos]);
    return arr[len];
}