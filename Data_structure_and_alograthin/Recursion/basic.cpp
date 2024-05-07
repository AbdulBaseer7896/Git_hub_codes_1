
#include <iostream>
using namespace std;
  
struct treenode {
    int info;
    struct treenode *left, *right;
};
  

struct treenode* create()
{
    int data;
    struct treenode* tree;
  
    tree = new treenode;
  
    cout << "\nEnter data to be inserted " << "or type -1 for no insertion : ";
    cin >> data;
  
    if (data == -1)
        return 0;
 
    tree->info = data;
    cout << "Enter left child of : "<< data;
    tree->left = create();
  
    cout << "Enter right child of : "<< data;
    tree->right = create();
  
    return tree;
};
  

void inorder(struct treenode* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->info << "  ";
    inorder(root->right);
}
  
// Driver Code
int main()
{
    struct treenode* root = NULL;
  
    root = create();
    inorder(root);
  
    return 0;
}