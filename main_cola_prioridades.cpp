#include "cola_prioridades.hpp"

int main(){
  Bheap<string> hola;
  cout << "Vacio: "<< hola.empty() << endl;
  cout << "Tamaño: "<< hola.size() << endl;
  hola.push("Juano", 3 );
  hola.push("Ernesto", 7 );
  hola.push("Andres", 2 );
  hola.push("Carlos", 10 );
  hola.push("Julian", 4 );
  hola.push("Manuela", 12 );
  hola.push("Sara", 8 );
  hola.push("Diana", 5 );
  hola.display();
  hola.pop();
  hola.pop();
  cout << endl;
  hola.display();

}
