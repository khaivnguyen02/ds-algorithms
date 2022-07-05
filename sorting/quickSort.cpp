/*  TIME COMPLEXITY:
    - average: O(n logn)
    - worst case: O(n^2)
*/
/*  
    STRATEGY
    1. Split the array int 2 roughly equal pieces (partition around a pivot element)
    2. Recursively sort each half
    3. Join the 2 pieces together to make 1 sorted array
*/
// Hoare Partition: compare x with each element and grow left & right piece incrementally
int partition(int *arr, int first, int last)
{
    int x = arr[first];
    int left = first;
    int right = last + 1;

    while (left < right)
    {
        // arr[first + 1... left] <= x AND arr[right...last] >= x
        do
            left++;
        while (arr[left] < x);
        do
            right--;
        while (arr[right] > x);
        if (left < right)
            swap(arr[left], arr[right]);
    }
    swap(arr[right], arr[first]);

    return right;
}

// Post: arr[first...last] are sorted
void quickSort(int *arr, int first, int last)
{
    // Base case
    if (last <= first)
        return;

    // Split array
    int mid = partition(arr, first, last);

    // Recursively sort
    quickSort(arr, first, mid - 1);
    quickSort(arr, mid + 1, last);
}

void swap (int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}