#include "BinaryTree.h"

void BinaryTree::insert(TreeNode *&tree, int num) {
    if (tree == NULL) {
        tree = new TreeNode(num);
        return;
    }

    if (num < tree->val) {
        insert(tree->left, num);
    }
    else if (num > tree->val) {
        insert(tree->right, num);
    }
    else {
        return;
    }
}

void BinaryTree::displayPreOrder(TreeNode* tree) {
    if (tree != NULL) {
        std::cout << tree->val << ' ';
        displayPreOrder(tree->left);
        displayPreOrder(tree->right);
    }
}

void BinaryTree::displayInOrder(TreeNode* tree) {
    if (tree != NULL) {
        displayInOrder(tree->left);
        std::cout << tree->val << ' ';
        displayInOrder(tree->right);
    }
}

void BinaryTree::displayPostOrder(TreeNode* tree) {
    if (tree != NULL) {
        displayPostOrder(tree->left);
        displayPostOrder(tree->right);
        std::cout << tree->val << ' ';
    }
}

void BinaryTree::destroySubtree(TreeNode* tree) {
    if(tree != NULL) {
        destroySubtree(tree->left);
        destroySubtree(tree->right);
        delete[] tree;
        tree = NULL;
    }
}

bool BinaryTree::search(TreeNode *tree, int num) {
    while(tree){
        if (tree->val < num) {
            tree = tree->right;
        }
        else if (tree->val > num) {
            tree = tree->left;
        }
        else
            return true;
    }
    return false;
}

TreeNode* BinaryTree::getAddress(TreeNode *tree, int num) {
    while(tree) {
        if (tree->val < num)
            tree = tree->right;
        else if (tree->val > num)
            tree = tree->left;
        else
            return tree;
    }
}

int BinaryTree::getSize(TreeNode* tree){
    if (tree == NULL)
        return 0;

    return getSize(tree->left) + getSize(tree->right) + 1;
}

int BinaryTree::maxDepth(TreeNode* root) {
    if (root == NULL)
        return 0;
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}


// O(n^2) check the given tree isBalance
bool BinaryTree::isBalance(TreeNode* root) {
    if (root == NULL)
        return true;

    int LeftDepth = maxDepth(root->left);
    int RightDepth = maxDepth(root->right);

    return abs(RightDepth - LeftDepth) <= 1 && isBalance(root->left) && isBalance(root->right);
}

void BinaryTree::printAllLeaves(TreeNode* tree){
    if (tree == NULL)
        return;

    if (tree->left == NULL && tree->right == NULL)
        std::cout<< tree->val << ' ';

    printAllLeaves(tree->left);
    printAllLeaves(tree->right);
}

int BinaryTree::countAllParentHas2Child(TreeNode* tree) {
    if (tree != NULL) {
        if (tree->left != NULL && tree->right != NULL) {
            return 1 + countAllParentHas2Child(tree->left) + countAllParentHas2Child(tree->right);
        }
        else {
            return countAllParentHas2Child(tree->left) + countAllParentHas2Child(tree->right);
        }
    }
    else {
        return 0;
    }
}

void  BinaryTree::printBreadthFirstSearch(TreeNode* tree) {
    queue<TreeNode*> q;
    TreeNode* currentNode = tree;


    while(currentNode != NULL) {
        std::cout << currentNode->val << ' ';
        if (currentNode->left != NULL) {
            q.push(currentNode->left);
        }
        if (currentNode->right != NULL) {
            q.push(currentNode->right);
        }
        if(!q.empty()) {
            currentNode = q.front();
            q.pop();
        }
        else {
            currentNode = NULL;
        }
    }
}
