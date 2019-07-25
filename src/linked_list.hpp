#ifndef NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_LIST_LINKED_LIST_H_
#define NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_LIST_LINKED_LIST_H_

#include <stdlib.h>
//template <typename T>
class Node;
class Linked_list {

  private:
    Node **  arr = (Node**) malloc(sizeof(Node*) * 64); //make unique ptr
    int size = 0;
    int maximum_capacity = 64;


  public:

    Linked_list(Node * value): size(1) {
      arr[0] = value;
    }

    Linked_list(): size(0) {};

    void push(Node * value);

    void pop();

    Node* peek() const;

    Node* const yield() const;

    inline int get_size() const {
      return size;
    }

    inline Node* operator[](int index) {
      if(index > this->size -1) {
        //throw error
      }
      return this->arr[index];
    };

    ~Linked_list(){};
};
#endif