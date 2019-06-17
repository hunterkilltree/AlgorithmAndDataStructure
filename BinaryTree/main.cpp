#include "BinaryTree.h"

int main() {
    BinaryTree Tree;

    Tree.insert(23);
    Tree.insert(18);
    Tree.insert(44);
    Tree.insert(12);
    Tree.insert(20);
    Tree.insert(35);
    Tree.insert(52);
    Tree.insert(55);
    Tree.insert(40);
    Tree.insert(21);
    Tree.insert(56);
    Tree.insert(56);
    Tree.insert(57);

    std::cout << "InOrder: ";
    Tree.displayInOrder();
    //
    // std::cout << "\nThe number of Node: ";
    // std::cout << Tree.getSize();
    //
    //
    // std::cout << "\nLeaves : ";
    // Tree.printAllLeaves();
    //
    // std::cout << "\nPrint all Children of  18 : ";
    // Tree.printChildren(18);
    // std::cout << "\nPrint all Children of  44 : ";
    // Tree.printChildren(44);
    // std::cout << "\nPrint all Children of 23 : ";
    // Tree.printChildren(52);
    // std::cout << "\nPrint all Children of 0 : ";
    // Tree.printChildren(0);
    //
    //
    // std::cout << "\nPreOrder: ";
    // Tree.displayPreOrder();
    //
    // if (Tree.isBalance() )
    //     std::cout<< "\nThe given tree is balance\n";
    // else
    //     std::cout<< "\nThe given tree is not balance\n";
    //
    // std::cout << "Print BreadthFirstSearch: ";
    // Tree.printBreadthFirstSearch();

    return 0;
}
