#ifndef NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_DIVIDE_H_ 
#define NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_DIVIDE_H_ 

#include "node.hpp"


class Divide : public Node {

  protected:
    inline void compute() override {
      this->value = &(this->feeders[0]->get_value() / this->feeders[1]->get_value());
    } 
 
    inline void update_feeders_dy() override {
      Node::update_delta(this->feeders[0], *(new Matrix(this->dy->get_rows(), this->dy->get_columns(), 1)) / *(this->dy));
      Node::update_delta(this->feeders[1], (this->feeders[0]->get_value() * -1) / (this->feeders[1]->get_value()^2));
    }

  public:
    Divide(int num_rows, int num_columns) : Node(num_columns, num_columns) {}

    ~Divide(){};
};

#endif //NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_DIVIDE_H_ 