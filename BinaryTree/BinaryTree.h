#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data, TreeNode* l = NULL, TreeNode* r = NULL){
            val = data;
            left = l;
            right = r;
    }
};

class BinaryTree {
private:
    TreeNode* root;

    void insert(TreeNode *&, int);
    void displayPreOrder(TreeNode*); //Root->Left->Right
    void displayInOrder(TreeNode*); //Left->Root->Right
    void displayPostOrder(TreeNode*);// Left->Right->Root
    void destroySubtree(TreeNode*); // for destructor
    bool search(TreeNode*, int); // using BST while loop
    TreeNode* getAddress(TreeNode*, int); // getAddress of the value we need by using Binary Search Tree
    int getSize(TreeNode*); // get size of BinaryTree
    int maxDepth(TreeNode*);
    bool isBalance(TreeNode*);
    void printAllLeaves(TreeNode*);
    int countAllParentHas2Child(TreeNode*);
    void printBreadthFirstSearch(TreeNode*);

public:
    BinaryTree() { root = NULL;}
    ~BinaryTree() { destroySubtree(root); }


    void insert(int num) {
        insert(root, num);
    };

    void displayPreOrder() {
        displayPreOrder(root);
    }

    void displayInOrder() {
        displayInOrder(root);
    }

    int getSize(){
        return getSize(root);
    }

    void printAllLeaves(){
        printAllLeaves(root);
    }


    bool isBalance() {
        return isBalance(root);
    }

    void printBreadthFirstSearch() {
        printBreadthFirstSearch(root);
    }

    //show children of given NodeValue
    void printChildren(int num){
        TreeNode *parent = NULL;

        if (search(root, num)) {
            parent = getAddress(root, num);

            if(parent->left == NULL && parent->right == NULL)
                std::cout << "It's a leaf";

            if (parent->left != NULL)
                displayPreOrder(parent->left);

            if (parent->right != NULL)
                displayPreOrder(parent->right);
        }
        else
            std::cout << "Invalid node";
    }
};
