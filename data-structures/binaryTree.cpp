class BTnode
{
public:
    int data;
    int key;
    BTnode *left, *right, *parent;

    BTnode(int &k, BTnode * newLeft, BTnode * newRight) 
    {
        key = k;
        left = newLeft;
        right = newRight;
    }     
};

bool search(BTnode *root, int target)
{
    // Base case
    if (root == nullptr)
        return false;
    if (root->key == target)
        return true;

    if (target < root->key)
        return search(root->left, target);
    else
        return search(root->right, target);
}

// Return the new root of the binary search tree
BTnode * insert(BTnode * root, int key)
{
    // Base case
    if (root == nullptr)
        return new BTnode(key, nullptr, nullptr);
    
    if (key <= root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}