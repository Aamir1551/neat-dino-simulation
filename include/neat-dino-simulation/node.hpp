#ifndef NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_NODE_H_
#define NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_NODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <iostream>

#include "./matrix.hpp"
#include "../../src/linked_list.hpp"
class Linked_list;

class Node {

  protected:
    Linked_list feeders = *(new Linked_list()); 
    Linked_list feeds = *(new Linked_list());
    Matrix * value;
    Matrix * dy;

    static void connect(Node * feeder, Node * leacher) {
      feeder->feeds.push(leacher);
      leacher->feeders.push(feeder);
    }
    virtual void compute() = 0;

    void reset_self_value() {
      (*this->value).set_zero();
    }
    void reset_self_dy() {
      (*this->dy).set_zero();
    };
    virtual void update_feeders_dy() = 0;

    void reset_graph_dirs() {
      for(int i=0; i<this->feeders.get_size(); i++) {
        this->feeders[i]->reset_self_dy();
        this->feeders[i]->reset_graph_dirs();
      }
    }

    void add_dirs_to_feeders() {
      for(int i=0; i<this->feeders.get_size(); i++) {
        *(this->feeders[i]->dy) += (*this->dy);
      }
    }

    explicit Node(int num_rows, int num_columns) {
      this->value = new Matrix(num_rows, num_columns, 0);
      this->dy = new Matrix(num_rows, num_columns, 0);
    } 

    explicit Node(Matrix * initial_value) {
      this->value = initial_value;
      this->dy = new Matrix(initial_value->get_rows(), initial_value->get_columns(), 0);
    }

    static void update_delta(Node * feeder, const Matrix &delta) {
      *feeder->dy += delta;
    }

  public:
    
    inline const Matrix& get_value() const {return  *this->value;};

    ~Node() {
      free(this->value);
      free(this->dy);
    };


    Node& operator+(Node& a);
    Node& operator*(Node& a);
    Node& operator-(Node& a);
    Node& operator/(Node& a);
    Node& matmul(Node &a, Node &b);
  
};


#endif //NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_NODE_H