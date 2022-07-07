#include "BST.h"
#include "assert.h"

#include <iostream>
#include <cassert>

using namespace std;

BST::BST()
{
    root = NULL;
}

bool BST::isEmpty() const
{
    return root == NULL;
}

void BST::insert(int key)
{
    root = insert(root, key); // helper function
} // insert

bool BST::search(int target)
{
    return search(root, target); // helper function
} 

int BST::min()
{
    return min(root); // helper function
}

void BST::print() const
{
    ascii(root);
    cout << endl;
} // print

void BST::ascii(BTnode *tree) const
{
    if (tree == NULL)
        return;

    ascii(tree->right);

    for (int i = 0; i < tree->depth; i++)
    {
        cout << "  ";
    }
    cout << tree->key << endl;

    ascii(tree->left);

    /*
    if (tree == NULL) return;

    cout << '[' << tree->key;

    if (tree->left) {
        cout << " L";
        ascii(tree->left);
    }
    if (tree->right) {
        cout << " R";
        ascii(tree->right);
    }

    cout << ']';

    */
} // ascii

void BST::inorder(BTnode *tree) const
{

} // inorder

BTnode *BST::insert(BTnode *tree, int key)
{
    // Base case
    if (tree == NULL)
    {
        return new BTnode(key, NULL, NULL, NULL);
    }

    if (key <= tree->key)
    { // left subtree
        tree->left = insert(tree->left, key);
        // assert(tree->left);
        tree->left->parent = tree;
        tree->left->depth = tree->depth + 1;
    }
    else
    { // right subtree
        tree->right = insert(tree->right, key);
        // assert(tree->right);
        tree->right->parent = tree;
        tree->right->depth = tree->depth + 1;
    }

    return tree;
} // insert

bool BST::search(BTnode * root, int target)
{
    // Base case
    if (root == NULL)
        return false;
    if (root->key == target)
        return true;
    
    if (target < root->key)
        return search(root->left, target);
    else
        return search(root->right, target);
} // search

int BST::min(BTnode * root)
{
    if (root->left == NULL)
        return root->key;
    
    return min(root->left);
} // min

int BST::max(BTnode * root)
{
    if (root->right == NULL)
        return root->key;
    return max(root->right);
}

int BST::successor(BTnode *x)
{
    if(x->right)
        return min(x->right);
    
    for(;x->parent;x = x->parent)
    {
        if (x->parent->left == x)
            return x->parent->key;
    }
    return NULL;
}