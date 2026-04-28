#pragma once
#include "node.h"
#include "utility.h"
#include <cstddef>   

template <class List_entry>
class List {
public:
   ~List();
   List();
   List(const List<List_entry> &copy);
   void operator =(const List<List_entry> &copy);
   int size() const; 
   bool full() const; 
   bool empty() const; 
   void clear(); 
   void traverse(void (*visit)(List_entry &)); 
   Error_code retrieve(int position, List_entry &x) const;
   Error_code replace(int position, const List_entry &x);
   Error_code remove(int position, List_entry &x); 
   Error_code insert(int position, const List_entry &x);
protected:
   int count;
   Node<List_entry> *head;
   //Node<List_entry> *set_position(int position) const;
   mutable int current_position;
   mutable Node<List_entry> *current;
   void set_position(int position) const;
};

template <class List_entry>
void List<List_entry>::set_position(int position) const {
    if (position < current_position) {
        current_position = 0;
        current = head;
    }

    for (; current_position != position; current_position++) {
        current = current->next;
    }
}


template <class List_entry>
List<List_entry>::List() {
    head = nullptr;
    count = 0;
    current = nullptr;
    current_position = 0;
}

template <class List_entry>
List<List_entry>::List(const List<List_entry> &copy) {
    head = NULL;
    count = 0;
    current = NULL;
    current_position = 0;

    Node<List_entry>* temp = copy.head;

    while (temp != nullptr) {
        insert(count, temp->entry);
        temp = temp->next;
    }
}

template <class List_entry>
List<List_entry>::~List() {
    clear();
}

template <class List_entry>
void List<List_entry>::operator=(const List<List_entry> &copy) {
    if (this == &copy) return;

    clear();

    Node<List_entry>* temp = copy.head;

    while (temp != nullptr) {
        insert(count, temp->entry);
        temp = temp->next;
    }
}

/*
template <class List_entry>
Node<List_entry>* List<List_entry>::set_position(int position) const {
    Node<List_entry>* current = head;

    for (int i = 0; i < position && current != NULL; i++) {
        current = current->next;
    }

    return current;
}
    */

template <class List_entry>
int List<List_entry>::size() const {
   return count;
}

template <class List_entry>
bool List<List_entry>::full() const { //ei käytännössä täyty
    return false;
}

template <class List_entry>
bool List<List_entry>::empty() const {
    return count == 0;
}

template <class List_entry>
void List<List_entry>::clear() {
    while (head != nullptr) {
        Node<List_entry>* temp = head;
        head = head->next;
        delete temp;
    }

    count = 0;
    current = nullptr;
    current_position = 0;
}

template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &)) {
    Node<List_entry>* temp = head;

    while (temp != nullptr) {
        (*visit)(temp->entry);
        temp = temp->next;
    }
}

template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry& x) const {
    if (position < 0 || position >= count)
        return Error_code::range_error;

    set_position(position);

    x = current->entry;
    return success;
}

template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry& x) {
    if (position < 0 || position >= count)
        return Error_code::range_error;

    set_position(position);

    current->entry = x;
    return success;
}

template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry& x) {
    if (position < 0 || position >= count)
        return Error_code::range_error;

    Node<List_entry>* deleted;

    if (position == 0) {
        deleted = head;
        x = head->entry;
        head = head->next;
    }
    else {
        set_position(position - 1);

        deleted = current->next;
        x = deleted->entry;

        current->next = deleted->next;
    }

    delete deleted;
    count--;

    if (current_position > position)
        current_position--;
    else if (current_position == position)
        current = nullptr;

    return success;
}


template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry& x) {
    if (position < 0 || position > count)
        return Error_code::range_error;

    Node<List_entry>* new_node = new Node<List_entry>(x);

    if (position == 0) {
        new_node->next = head;
        head = new_node;
    }
    else {
        set_position(position - 1);

        new_node->next = current->next;
        current->next = new_node;
    }

    count++;

    if (current_position >= position)
        current_position++;

    return success;
}