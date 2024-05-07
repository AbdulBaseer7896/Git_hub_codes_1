#include <iostream>
using namespace std;

class node
{
public:
    int data;
    int height;
    node *left;
    node *right;

    node()
    {
        this->data = 0;
        this->height = 0;
        this->left = NULL;
        this->right = NULL;
    }

    node(int data)
    {
        this->data = data;
        this->height = 1;
        this->left = NULL;
        this->right = NULL;
    }
};

class tree
{
    node *root;

public:
    tree()
    {
        root = NULL;
    }

node* newNode(int data) 
{ 
    node* nodes = new node(data);
    nodes ->data = data; 
    nodes ->left = NULL; 
    nodes ->right = NULL; 
    nodes ->height = 1; // new node is initially
                      // added at leaf 
    return(nodes); 
} 

int height(node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 
node *rightRotate(node *y) 
{ 
    node *x = y->left; 
    node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), 
                    height(y->right)) + 1; 
    x->height = max(height(x->left), 
                    height(x->right)) + 1; 
  
    // Return new root 
    return x; 
} 
  
  int getBalance(node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - 
           height(N->right); 
} 
  
// A utility function to left 
// rotate subtree rooted with x 
// See the diagram given above. 
node *leftRotate(node *x) 
{ 
    node *y = x->right; 
    node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    // Update heights 
    x->height = max(height(x->left), 
                    height(x->right)) + 1; 
    y->height = max(height(y->left), 
                    height(y->right)) + 1; 
  
    // Return new root 
    return y; 
} 

node * minValueNode(node* root) 
{ 
    node* current = root; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
node* deleteNode(node* root, int data) 
{ 
      
    // STEP 1: PERFORM STANDARD BST DELETE 
    if (root == NULL) 
        return root; 
  
    // If the data to be deleted is smaller 
    // than the root's data, then it lies
    // in left subtree 
    if ( data < root->data ) 
        root->left = deleteNode(root->left, data); 
  
    // If the data to be deleted is greater 
    // than the root's data, then it lies 
    // in right subtree 
    else if( data > root->data ) 
        root->right = deleteNode(root->right, data); 
  
    // if data is same as root's data, then 
    // This is the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (root->left == NULL) ||
            (root->right == NULL) ) 
        { 
            node *temp = root->left ? 
                         root->left : 
                         root->right; 
  
            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
            *root = *temp; // Copy the contents of 
                           // the non-empty child 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            node* temp = minValueNode(root->right); 
  
            // Copy the inorder successor's 
            // data to this node 
            root->data = temp->data; 
  
            // Delete the inorder successor 
            root->right = deleteNode(root->right, 
                                     temp->data); 
        } 
    } 
  
    // If the tree had only one node
    // then return 
    if (root == NULL) 
    return root; 
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height = 1 + max(height(root->left), 
                           height(root->right)); 
  
    // STEP 3: GET THE BALANCE FACTOR OF 
    // THIS NODE (to check whether this 
    // node became unbalanced) 
    int balance = getBalance(root); 
  
    // If this node becomes unbalanced, 
    // then there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && 
        getBalance(root->left) >= 0) 
        return rightRotate(root); 
  
    // Left Right Case 
    if (balance > 1 && 
        getBalance(root->left) < 0) 
    { 
        root->left = leftRotate(root->left); 
        return rightRotate(root); 
    } 
  
    // Right Right Case 
    if (balance < -1 && 
        getBalance(root->right) <= 0) 
        return leftRotate(root); 
  
    // Right Left Case 
    if (balance < -1 && 
        getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
  
    return root; 
} 

    
    void inorder_triversal(node *root)
    {
        if (root != NULL)
        {
            inorder_triversal(root->left);
            cout << root->data << " -> ";
            inorder_triversal(root->right);
        }
    }
};

int main()
{

    tree t;
    node *root = new node(9);
    node *left_chile = new node(5);
    node *right_chile = new node(11);
    node *midle_chile = new node(18);

    node *left_sub_left = new node(2);
    node *left_sub_right = new node(7);

    node *right_sub_left = new node(10);
    node *right_sub_right = new node(14);

    root->left = left_chile;
    root->right = right_chile;
    left_chile->left = left_sub_left;
    left_chile->right = left_sub_right;

    right_chile->left = right_sub_left;
    right_chile->right = right_sub_right;
    cout<<"The Tree no InOrder Triversal:"<<endl;
    t.inorder_triversal(root);
    t.deleteNode(root , 45);
    t.deleteNode(root , 2);
    cout<<endl;
    t.inorder_triversal(root);

}