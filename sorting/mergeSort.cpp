// Time complexity: O(n logn)

// Pre: arr[first...mid] and arr[mid + 1... last] are sorted
// Post: arr[first...last] are sorted
void merge(int arr[], int first, int mid, int last)
{
    int size = last - first + 1;
    int *temp = new int[size];

    int leftPos = first;
    int rightPos = mid + 1;
    int newPos = 0;

    while(leftPos <= mid && rightPos <= last)
    {
        if (arr[leftPos] <= arr[rightPos])
            temp[newPos++] = arr[leftPos++];
        else 
            temp[newPos++] = arr[rightPos++];
    }

    while (leftPos <= mid)
        temp[newPos++] = arr[leftPos++];
    while (rightPos <= last)
        temp[newPos++] = arr[rightPos++];

    for (int i = first, j = 0; i <= last; i++, j++)
        arr[i] = temp[j];
    
    delete[] temp;
}

// Post: arr[first...last] are sorted
void mergeSort(int *arr, int first, int last)
{
    // Base case
    if (last <= first)
        return;

    // Split array
    int mid = (first + last) / 2;

    // Recursively sort
    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);

    // Join
    merge(arr, first, mid, last);
}
