#include<stdlib.h>

#include "./linked_list.hpp"
#include "../include/neat-dino-simulation/node.hpp"

//template <typename T> 
void Linked_list::push(Node *value) {
  if(this->size == this->maximum_capacity -1) {
    this->arr = (Node **) realloc(this->arr, this->maximum_capacity * 2);
    this->maximum_capacity *= 2;
  }
  this->arr[this->size] = value;
  this->size++;
}

//template <typename T> 
void Linked_list::pop() {
  if(this->size == 0) {
    //thrwo error (exit program and print error)
  }
  this->size--;
}

//template <typename T> 
Node* Linked_list::peek() const {
  return (this->arr[this->size -1]);
}

//template <typename T>
Node* const Linked_list::yield() const {
  return *(this->arr);
}