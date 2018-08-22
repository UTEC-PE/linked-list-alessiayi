#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* head;
        Node<T>* tail;//Nose para que es
        int nodes;

        void print_reverse(Node<T>* head);

    public:
        List() : head(NULL), tail(NULL) {};//Constructor

        T front(){//Ver primero elemento
          return head -> data;
        }
        T back(){//Ver ultimo elemento
          Node<T>* Temp=head;//Un Temp que apunta a la cabeza
          while(Temp -> next) {//Mientras tenga un siguiente
            Temp=Temp -> next;//Temp apunta al siguiente
          }
          return Temp -> data;
        }
        void push_front(T value){//Insertar al principio
          Node<T>* Tmp = new Node<T>;//Crear el Nodo
          Tmp -> data=value;//Tmp apunta al valor insertado
          Tmp -> next=NULL;//?
          if (head==NULL){//Si la lista es vacia
            head=Tmp;
          }
          else{
            Tmp -> next=head;//El siguiente de Tmp(el valor) apunta al head (el primero que habia)
            head=Tmp;//Head apunta al nuevo valor
          }
        }
        void push_back(T value){//Insertar al final
          Node<T>* Tmp = new Node<T>;
          Tmp -> data=value;//Tmp apunta al valor insertado
          if (head==NULL){
            head=Tmp;
          }
          else{
            Node<T>* Temp=head;//Un Temp que apunta a la cabeza
            while(Temp  -> next) {//Mientras que Temp tenga un next
              Temp=Temp -> next;//Temp apunta al siguiente
            }
            Temp -> next=Tmp;//El siguiente de Temp(el ultimo de la lista) es el valor
            Tmp -> next=NULL;//El ultimo valor apunta a NULL

          }
        }
        void pop_front();//Nose hacerlo
        void pop_back();//Nose hacerlo
        T get(int position);//Nose
        void concat(List<T> &other);//?
        bool empty(){
          if (head==NULL){
            return true;
          }
          else{
            return false;
          }
        }
        int size(){
          int c=0;//contador
          if (head==NULL) {
            return 0;
          }
          Node<T>* Tmp=head;
          while(Tmp) {//Mientras que Tmp sea distinto de NULL
            Tmp=Tmp -> next;//Apunta al siguiente
            c+=1;
          }
          return c;
        }
        void print(){
          if (head==NULL) {
            cout << "Lista vacia" << endl;
          }
          else {
            Node<T>* Tmp=head;
            while(Tmp) {//mientras que Tmp sea distinto que NULL
              cout << Tmp -> data << " ";
              Tmp=Tmp -> next;//Tmp pasa al siguiente elemento
            }
            cout << endl;
          }
        }
        void print_reverse();//Nose
        void clear();//Nose
        Iterator<T> begin();//?
        Iterator<T> end();//?

        ~List(){//destructor
            if(head){
                head->killSelf();
            }
            head = NULL;
        }
};
#endif
