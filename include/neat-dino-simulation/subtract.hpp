#ifndef NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_SUBTRACT_H_ 
#define NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_SUBTRACT_H_ 

#include "node.hpp"


class Subtract : public Node {

  protected:
    inline void compute() override {
      this->value = &(this->feeders[0]->get_value() - this->feeders[1]->get_value());
    } 
 
    inline void update_feeders_dy() override {
      Node::update_delta(this->feeders[0], *this->dy);
      Node::update_delta(this->feeders[1], (*(this->dy)) * -1);
    }

  public:
    ~Subtract(){};
    explicit Subtract(int num_rows, int num_columns) : Node(num_columns, num_columns) {}
};

#endif //NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_SUBTRACT_H_ 

