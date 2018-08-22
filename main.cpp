
#include <iostream>
#include "list.h"

using namespace std;

int main() {
  List<int> numbers;
  numbers.push_front(5);
  numbers.push_front(3);
  numbers.push_front(8);
  numbers.push_back(1);
  numbers.print();
  cout << "Primero: " << numbers.front() << endl;
  cout << "Ultimo: " << numbers.back() << endl;
  cout << "Tama;o: " << numbers.size() << endl;
  cout << "Vacia: " << numbers.empty() << endl;
  return 0;
}
