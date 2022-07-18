// Sorting Integers in Linear Time
/*
    Strategy:
    - take advantage of the fact that arrays have O(1) direct access
    - count frequency of each element in A[N]
    - place elements by frequency / rank
*/
// Stable sort: If you have 2 equals elements in the input array, they maintain the order in the output array

// Desc: src array A[n], dest array B[n]. place sorted A[] into B[]
// Pre: Each obj contains .key in range [0, d-1]
void countingSort(obj A[], obj B[], unsigned n, unsigned d)
{
    int C[d];

    // compute frequencies
    for (int i = 0; i < d; i++)
        C[i] = 0;

    for (int j = 0; j < n; j++)
        C[A[j].key]++;

    // compute ranks
    for (int i = 1; i < d; i++)
        C[i] += C[i - 1];

    // place elements base on rank
    for (int j = n; j--;)
    {
        int pos = --C[A[j].key];
        B[pos] = A[j];
    }
}

// Running time: if N ~ d, then O(N) ---> Linear Time Sorting