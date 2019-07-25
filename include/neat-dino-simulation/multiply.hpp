#ifndef NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_MULTIPLY_H_ 
#define NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_MULTIPLY_H_ 

#include "node.hpp"


class Multiply : public Node {

  protected:
    inline void compute() override {
      this->value = &(this->feeders[0]->get_value() * this->feeders[1]->get_value());
    } 
 
    inline void update_feeders_dy() override {
      Node::update_delta(this->feeders[0], (*(this->dy)) * (this->feeders[1]->get_value()));
      Node::update_delta(this->feeders[1], (*(this->dy)) * (this->feeders[0]->get_value()));
    }

  public:
    ~Multiply(){};
    Multiply(int num_rows, int num_columns) : Node(num_columns, num_columns) {}
};

#endif //NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_DIVIDE_H_ 