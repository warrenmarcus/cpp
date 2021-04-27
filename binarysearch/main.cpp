// Binary search Tree

#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main ()
{
    int value;
    
    BinarySearchTree<int> tree;
    cout << "Insert values (stop when entering 0): " << endl ;
    cin >> value;
    while (value != 0)
    {
        
        tree.insert(value);
        cin >> value;
    }
    
    cout << "Print the values: " << endl;
    tree.printTree();
    cout << endl << "Print the tree: " << endl;
    tree.print_Internal();
    
    cout << "Remove values (stop when entering 0): " << endl;
    cin >> value;
    while (value != 0)
    {
        tree.remove(value);
        cin >> value;
    }
    
    cout << "Print the values: " << endl;
    tree.printTree();
    cout << endl;
    cout << "Print the tree: " << endl;
    tree.print_Internal();
    
    
    return 0;
}

