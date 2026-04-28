#pragma once
#include <cstddef>  

template <class Node_entry>
struct Node {
//  data members
   Node_entry entry;
   Node<Node_entry> *next;
//  constructors
   Node();
   Node(Node_entry, Node<Node_entry> *link = NULL);
};


template <class Node_entry>
Node<Node_entry>::Node() {
    next = NULL;
}

template <class Node_entry>
Node<Node_entry>::Node(Node_entry item, Node<Node_entry>* add_on) {
    entry = item;
    next = add_on;
} 