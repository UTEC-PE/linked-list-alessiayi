
#include <iostream>
#include "list.h"

using namespace std;

int main() {
  List<int>* numbers= new List<int>;
  List<int>* numbers1= new List<int>;
  numbers->push_front(5);
  numbers->push_front(3);
  numbers->push_front(8);
  numbers->push_back(1);
  numbers->print();

  numbers1->push_front(9);
  numbers1->push_front(2);
  numbers1->push_front(6);
  numbers1->push_back(5);
  numbers1->print();

  numbers->pop_front();
  numbers->push_front(7);
  numbers->pop_back();
  numbers->print();
  cout << "Primero: " << numbers->front() << endl;
  cout << "Ultimo: " << numbers->back() << endl;
  cout << "Tama;o: " << numbers->size() << endl;
  cout << "Vacia: " << numbers->empty() << endl;
  cout << "Num es posicion 1: " << numbers->get(1) << endl;
  numbers->concat(numbers1);
  numbers->print();
  numbers->print_reverse();
  numbers->clear();
  numbers->print();

  return 0;
}
