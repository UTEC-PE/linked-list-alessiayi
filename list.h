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
        List() : head(NULL), tail(NULL), nodes(0) {};//Constructor

        T front(){//Ver primero elemento
          if (head==NULL){//Si esta vacia
            throw "No hay elementos";
          }
          return head -> data;
        };
        T back(){//Ver ultimo elemento
          Node<T>* Temp=head;//Un Temp que apunta a la cabeza
          if (head==NULL){//Si esta vacia
            throw "No hay elementos";
          }
          while(Temp -> next) {//Mientras tenga un siguiente
            Temp=Temp -> next;//Temp apunta al siguiente
          }
          return Temp -> data;
        };
        void push_front(T value){//Insertar al principio
          Node<T>* Tmp = new Node<T>;//Crear el Nodo
          Tmp -> data=value;//Tmp apunta al valor insertado
          if (head==NULL){//Si la lista es vacia
            Tmp -> next=NULL;//Tiene que apuntar al NULL pq es el primero
            head=Tmp;
          }
          else{
            Tmp -> next=head;//El siguiente de Tmp(el valor) apunta al head (el primero que habia)
            head=Tmp;//Head apunta al nuevo valor
          }
          nodes++;
        };
        void push_back(T value){//Insertar al final
          Node<T>* Tmp = new Node<T>;
          Tmp -> data=value;//Tmp apunta al valor insertado
          if (head==NULL){
            Tmp -> next=NULL;//Tiene que apuntar al NULL pq es el primero
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
          nodes++;
        };
        void pop_front(){
          if (empty()){
            throw "Lista Vacia";
          }
          else{
            Node<T>* Tmp = head->next;
            delete head;
            head->next = NULL;
            head = Tmp;
          }
          nodes--;
        };
        void pop_back(){
          Node<T>* Tmp = head;
          if (empty()){
            throw "Lista Vacia";
          }
          if (!head -> next){
            head=NULL;
          }
          else{
            while (Tmp -> next -> next){ //Hasta que haya un sig del seig (penultmo)
              Tmp=Tmp -> next;
            }
            delete Tmp -> next; //Borra al sig (ultimo)
            Tmp -> next=NULL; //El sig apunta al NULL
          }
          nodes--;
        };
        T get(int position){
          if (head==NULL || position > nodes || position < 0){
            throw "Wrong position";
          }
          else{
            if (!position){
              return head -> data;
            }
            else{
              int c=0;
              Node<T>* Tmp = head;
              while (Tmp){
                if (c==position){//Si ya encuentra la posicion pedida
                  return Tmp -> data;
                }
                c++;
                Tmp=Tmp -> next;
              }
              throw "NO";
            }
          }
        };
        void concat(List<T> &other){
          Node<T>* Tmp = head;
          while (Tmp -> next){
            Tmp=Tmp -> next;
          }
          Tmp -> next=other.head;
          nodes += other.size();
        };
        bool empty(){
          if (head==NULL){
            return true;
          }
          else{
            return false;
          }
        };
        int size(){
          return nodes;
        };
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
        };
        void print_reverse(){
          List<T>* LTmp=new List<T>;
          Node<T>* Tmp=head;
          while(Tmp){
            LTmp -> push_front(Tmp -> data);//Hago un push front de la original a la nueva
            Tmp=Tmp -> next;
          }
          //-> es para punteros, . es para objetos
          LTmp -> print();//Imprimo nueva lista
        };
        void clear(){//Borrar todo
          while (head){
            Node<T>* Tmp = head;
            head = head->next;
            delete Tmp;// El siguiente del head apunta a NULL para desaparecer todo
            nodes--;
          }
          head = NULL;
        };
        Iterator<T> begin();
        Iterator<T> end();

        ~List(){//destructor
            if(head){
                head->killSelf();
            }
            head = NULL;
        }
};
#endif
