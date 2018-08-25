#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    struct Node<T>* next;
    struct Node<T>* before;

    void killSelf(){
      if (next){
        next->killSelf();
      }
      delete this;
    }
};

#endif
