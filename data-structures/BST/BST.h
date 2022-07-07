class BTnode
{
public:
    int key;
    int depth;
    BTnode *left, *right, *parent;
    BTnode(int key, BTnode *left, BTnode *right, BTnode *parent) : key(key), left(left), right(right), parent(parent) { depth = 0; };
};

class BST
{
private:
    BTnode *root;
    BTnode *insert(BTnode *root, int key);
    bool search(BTnode * root, int target);
    int min(BTnode * root);
    int max(BTnode * root);
    void inorder(BTnode *root) const;
    void ascii(BTnode *root) const;
    
public:
    BST();
    bool isEmpty() const;
    void insert(int key); // Worst case: O(n), Ideal/Average case: O(logn)
    bool search(int target);
    
    int min();
    int max();

    int successor(BTnode *x);

    void print() const;
};

// RULE OF THUMB: Balanced is best for efficiency

/*
    AVL TREES (Height balanced trees)
        - Invariant: For every node, heights of left subtree and right subtree differ by AT MOST one.
        - Uses "zig-zag" or "zig"
*/