#include "Mymap_hash.hpp"

int main(){
    HashMap <int> first(15);
    first.insert("hola", 2);
    first.insert("como", 3);
    first.insert("estas", 4);
    first.insert("estas", 8);
    first.display();
    cout << first.search("gjhdj") << endl;
    return 0;
}
