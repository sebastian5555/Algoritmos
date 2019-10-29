
#include "Bst.hpp"

int main(){
    BST<int> first;
    first.insertNode(3);
    first.insertNode(2);
    first.insertNode(1);
    first.insertNode(7);
    first.insertNode(5);
    first.insertNode(9);
    first.insertNode(4);
    first.remove(5);
    first.displayNode();
    cout << "\n";
    return 0;
}
