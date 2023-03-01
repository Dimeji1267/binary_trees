A binary tree is one of the most extensively used tree data structures. It is a hierarchical data structure wherein each node has two children, the left child and the right child. A typical binary tree consists of the following components:

Ø  A root node

Ø  A left subtree

Ø  A right subtree

 

Binary Tree representation: 

1.      Sequential representation:



  Above is a pictorial representation of a binary tree. This particular representation requires an array structure to implement the tree. The size of an array is equal to the number of total nodes in the tree. The root node's index is 0. For example- if a node is at “i” location, then its left child is at the ‘2i’ index, and the right child is at the ‘2i+1’ location in the array. The visual representation of the array is given below: 


2.      Linked-list Representation: 

    

    In this, a linked list is used to store the nodes of the tree. Various nodes are scattered in the memory in non-contiguous locations, and those nodes are connected using the parent-child relationship as signified in a tree.

 As we can see, the topmost node ‘A’ is the parent node of ‘B’ and ‘C’. Each node contains a pointer to the left subtree and a pointer to the right subtree in the above representation. Thus, node A has a pointer corresponding to the right child node ‘C’ and a pointer to the left child node ‘B’. The box in the middle represents the data in the node. The nodes that don’t have a child are known as ‘ass leaf’ nodes. They do not have a pointer to their subtrees and which is why they are set to NULL.

To implement a binary tree, it is necessary to define the conditions for new data to enter into the tree.

Binary tree implementation in C++

Now, we will create a binary tree programme using linked list representation in C++.

In the fragment below, we have used a class to declare a single node and used it to declare a linked list of nodes.

#include<iostream>

using namespace std;

 

class BT

{

public:

int data;

BT  *lChild;

BT  *rChild;

BT * Parent;

};

If you want to declare a group of data whether of similar or different data types, it is declared using the 'class' keyword. In the above fragment, the class is "BT" and it contains a pointer to left and pointer to right. The “BT  *lChild” is pointer to node and it stores the address of left child and similarly “BT  *rChild” is a pointer for right. The “int” data declares data of int type.

In linked list representation, the information of the address of the head node is kept. All the other information can be accessed using this head node. In the given instance, the address of the root node is known. This is mandatory as without knowing the address of the head node, we won’t be able to access the tree using links.

In order to declare the tree, we will first need to create a pointer to the node that will store address of root node by: BT* root. Since our tree does not have any data yet, we will assign our root node as NULL. BT* root = NULL. 
 



 

In the above image, we have assigned the left and right cells of nodes as addresses to their children. The middle cell is for data. The identity of the tree is the address of the root node and we have designated a pointer to the node in which we are storing the address of the root node.

For an empty tree, the root pointer should be set as NULL. Let’s suppose this ‘rootPtr’ to be a different box pointing towards different nodes in our tree, and for pointing to different nodes we have to pass the address of the nodes. At the beginning, it is not pointing towards any node and therefore we will put NULL value.

int main() {

         BT * root = NULL;  // Create empty tree

 

 Since now our tree is empty, let’s insert new data into our tree. To do so, we will have to call and define the ‘insert’ function.

int main() {

         BT *root = NULL;  // Creating an empty tree

    root = Insert(root, 15); 

    root = Insert(root, 10);

    root = Insert(root, 20);

 

In the fragment given below, we will define Insert function which is taking 2 arguments as "root" and new integer data to be inserted in our tree as follows:

// Function to create a new Node

BT * BST::Insert(BT * node, int value)

{

// If Tree doesn't exist

// create a new node

 

if(node == NULL)

{

     node = new BT;

     node->data = value;

     node->lChild = NULL;

     node->rChild = NULL;

        node->Parent = NULL;

}

// Check the right subtree if 

          // given value is greater then the node’s data 

else if(node->data < value){

        node->rChild = Insert(node->rChild, value);

        node->rChild->Parent = node;

}

// Check the left subtree if the 

          // given value is smaller than the given node’s data 

else

{

        node->lChild = Insert(node->lChild, value);

        node->lChild->Parent = node;

}

 

In the above fragment, ‘else if’ condition is done when the root pointer is not NULL. When the new data is less than the data present in the root node, then that data is inserted into its left pointer corresponding to the left child node and assigned that node's parent as root node. Likewise, if the new data is greater than data of root node, then insert that integer into its right child and assign its parent as root node. In the above fragment, root->left is the pointer to its left node. The insert function will call itself again. It’ll check if the root is empty and then follow the same procedure. This is called a recursive loop. The following is a recursive loop code:// Function to create a new Node

 

void BT::preorder(BT * node){

// Stop if no node found

if (node == NULL)

       return;

 

  // first print data of node

     cout<<node->data;  

 

  // then move on left subtree

     preorder(node->left);  

 

  // now move on right subtree

     preorder(node->right);

}

 

 Operations on Binary tree

After successfully creating a new binary search tree, we will now traverse the tree PREorder. A function called printInOrder will be implemented which will traverse the tree from its root nude, then its left subtree and then its right subtree. 



1.   Pre order Traversal

In this example, preorder(Root, Left, Right) : 1 2 3 4 5

The algorithm for traversing preorder is : using recursion.

The procedure as follows:

1.   Go to the root

2.   Then traverse the left subtree, call preorder(left-subtree)

3.   Then traverse the right subtree, call preorder(right-subtree).

The preorder function is defined as follows:-

 

void BT::preorder(BT * node){

// Stop if no node found

if (node == NULL)

       return;

 

  // first print data of node

     cout<<node->data;  

 

  // then move on left subtree

     preorder(node->left);  

 

  // now move on right subtree

     preorder(node->right);

}



 

 2. How to search a key in the Tree

Now, find out if the key exists in our tree or not. To do so, we need to compare the key with the current node. If the key is less than the current node, the left subtree needs to be searched, or else the right subtree would be searched. Till the time key is not found, compare it with the current node. This process is known as a recursive function.



 

int BST::fun(BT * node)

{

// The successor is the minimum data value

// of the right subtree

if (node->rChild != NULL)

{

     return Min(node->rChild);

}

}



 

3. How to find minimum and maximum values in Binary Tree

The easiest thing to find in the binary search tree is finding the minimum and maximum values. We have to get to the leftmost value to get the minimum value. However, to get the maximum value, we have to get to the rightmost value given in the binary tree.

int BST::fun(BT * node)

{

// The successor is the minimum data value

// of the right subtree

if (node->rChild != NULL)

{

     return Min(node->rChild);

}

}

 

4. Deleting or removing a node from the tree

Below mentioned are the three cases with which the node from the tree can be removed:


One of the easiest cases is to remove the leaf node. Only the node that doesn’t have a child needs to be removed. 8, 12, 17, and 25 are the leaf nodes in our tree.

If the removed node has one child (right or left), then the parent code's address needs to be pointed out to the child node of the deleted ones. For example, in the above tree, there are two single nodes, 3 and 88. We have to point to the parent code of 53 to 31 if we want to remove node 88. Thus, make the right node of 31 as 53.

Removing the two children nodes. If the node has two children, you need to find out the predecessor or successor of that particular node first and replace it with the same. For example, If you want to remove node 12, the predecessor needs to be removed 7. Now, 7 will come in place of 12. 7 has two children, i.e. 3 and 15. As we can choose only one (either successor or predecessor), there can be two possible binary representations after deleting a node.

 

In such cases, the successor and predecessor of a node need to be defined first.

4.1 Finding the successor of the key

The immediate number after a key is referred to as the successor. If we wish to identify the successor of a specific key, say "T," we'll look for the minimum key in the right subtree of T. Our bare-bones feature could come in handy here. The minimal key will be found in the right subtree of T.

 

int BST::fun(BT * node)

{

// The successor is the minimum data value

// of the right subtree

if (node->rChild != NULL)

{

     return Min(node->rChild);

}

}

 

4.2 Finding T’s predecessor

The key that comes just before T is Predecessor. We'll make use of the maximum function we've already defined. Now we need to find the maximum value, which is the left subtree of T.

 

int BST::fun2(BT * node)

{

// The predecessor is the maximum data value

// of the left subtree

if (node->lChild != NULL)

{

     return Max(node->lChild);

}

}

}

 

Removing a key from Tree

There are three ways in which a node can be removed:

Remove a node that has no child i.e. a node with node->lChild = NULL and node ->rChild = NULL.

Remove nodes having only one child (left or right).

node->lChild == NULL && node->rChild != NULL

node->lChild != NULL && node->rChild == NULL

 

We must delete the node and reconnect the child node to the removed node's parent node.

Delete a node with two children. We might use the successor or predecessor of the target node to replace it. For example, if the target node to be removed is 12 and has two children, we have two choices: replace 12 with its predecessor (7) or replace 12 with its successor (8). (15). Below mentioned is the code that can be taken into consideration for the three cases.


 

BT * BST::Remove(BT * node,int value)

{

             node = BST::Search(node, int value)

// If the given node is

// not in Tree

             if (node == NULL)

         return NULL;

             // If we found the target,

             if (node->data == value)

             {

 

                             if (node->lChild == NULL && node->rChild == NULL)

                                             node = NULL;

 

             // If the node have only right child

             else if (node->lChild == NULL && node->rChild != NULL)

             {

                             node->rChild->Parent = node->Parent;

                             

                             // Bypass node

                             node = node->rChild;

             }

             // If the node have only left child

             else if (node->lChild != NULL && node->rChild == NULL)

             {

             // If the only child is connected to

             // the parent's node directly

             node->lChild->Parent = node->Parent;

             

             // Bypass node

             node = node->lChild;

             }

             // If the node have both children (left and right)

             else

             {

             

             int funkey = BST::fun(value);

 

             // Replace node's data with fun's data

             node->data = funkey;

             

             // Delete the old successor's key

             node->rChild = Remove(node->rChild, funkey);

             }

}

             // Target node's data is smaller than

             // the given value then search to right

             else if (node->data rChild = Remove(node->rChild, value);

             // Target node's data is greater than

             // the given value then search to left

             else

                             node->lChild = Remove(node->lChild, value);

 

             // Return the updated BST

             return node;

 

}

int main() {

             BT* root = NULL;  // Creating an empty tree

             /*Remaining code for the program*/

void BST::Insert(int value){

     root = Insert(root,15);        

     root = Insert(root,10);        

     root = Insert(root,20);

     root = Insert(root,25);

     root = Insert(root,8);

     root = Insert(root,12);

}

//Print in Preorder traversal

void BST::preorder(){

        preorder(root);

     }

//For searching a particular key in tree

bool BST::Search(int val)

{

// Calling Search() operation

// and passing root node

BT * result = Search(root, val);

// If value is found then return true

// else return false

return result == NULL ?false:true;

}

 

//To find minimum or maximum call these functions as:

int BST::Min()

{

     return Min(root);

}

int BST::Max()

{

return Max(root);

}

 

 

void BST::Remove(int value)

{

     root = Remove(root, value);

}

     }
