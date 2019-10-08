#include "Bst.hpp"

int main(){
    BST<int> first;
    first.insertNode(3);
    first.insertNode(2);
    first.insertNode(1);
    first.insertNode(7);
    first.displayNode();
    cout << "\n";
    return 0;
}
