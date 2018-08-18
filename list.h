#ifndef LIST_H
#define LIST_H

class List {
    struct Node {
        int data;
        struct Node* next;
    };

    private:
        Node* head;
        int nodes;

        void print_reverse(Node* head);

    public:
        List();

        int front();
        int back();
        void push_front(int value);
        void push_back(int value);
        void pop_front();
        void pop_back();
        int get(int position);
        bool empty();
        int size();
        void print();
        void print_reverse();
        void clear();

        ~List();
};

#endif