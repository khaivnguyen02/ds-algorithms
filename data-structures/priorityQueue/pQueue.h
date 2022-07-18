class node
{
public:
    int data;
    int key;

    node(int x, int key)
    {
        data = x;
        this->key = key;
    }
};

class PQueue
{
private:
    node *arr;
    int minPos;
    int len;

public:
    void insert(int x, int key);
    node removeMin();
};

void swap(node &a, node &b)
{
    node temp = a;
    a = b;
    b = temp;
}