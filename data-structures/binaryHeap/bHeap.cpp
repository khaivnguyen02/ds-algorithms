// Pre: both left(x) and right(x) are heaps
void heapify(x)
{
    if(key(x) <= min(key(left(x), key(right(x)))){
        return; // already a heap
    }
    else if (key(left(x)) < key(right(x))) {
        swap(x, left(x));
        heapify(left(x));
    }
    else {
        swap(x, right(x));
        heapify(right(x));
    }
}
// Pre: newKey <= key(x)
void decreaseKey(x, newKey)
{
    key(x) = newKey;
    trickleUp(x);
}
void trickleUp(x)
{
    if (parent(x) && key(x) < key(parent(x)))
        swap(x, parent(x))
    trickleUp(parent(x));
}
