#include "Mymap.hpp"

int main(){
    MyMap<int, int> hola;
    for (int i = 0; i<20; i++){
        hola.insert(i, i*2);
    }
    cout <<"¿Esta vacia? " << hola.empty()<< endl;
    cout << hola.get(2)<< endl;
    cout <<"¿Contiene el key?: "<< hola.containsKey(4) << endl;
    hola.remove(0);
    hola.remove(1);
    hola.remove(2);
    hola.remove(3);
    hola.remove(4);
    hola.remove(5);
    hola.remove(6);
    hola.remove(7);
    hola.remove(8);
    cout <<"¿Contiene el key?: "<< hola.containsKey(4) << endl;
    hola.clear();
    cout <<"¿Esta vacia? " << hola.empty()<< endl;
    return 0;
}
