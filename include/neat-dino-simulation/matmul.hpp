#ifndef NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_MATMUL_H_ 
#define NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_MATMUL_H_ 

#include "node.hpp"


class Matmul : public Node {

  protected:
    inline void compute() override {
      this->value = &(Matrix::matmul(this->feeders[0]->get_value(), this->feeders[1]->get_value()));
    } 
 
    inline void update_feeders_dy() override {
      Node::update_delta(this->feeders[0], Matrix::matmul(*this->dy, Matrix::transpose( this->feeders[1]->get_value())));
      Node::update_delta(this->feeders[1], Matrix::matmul(Matrix::transpose(this->feeders[0]->get_value()), *this->dy));
    }

  public:
    Matmul(int num_rows, int num_columns) : Node(num_columns, num_columns) {}
    ~Matmul(){};
};

#endif //NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_MATMUL_H_ 