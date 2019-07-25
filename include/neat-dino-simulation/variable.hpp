#ifndef NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_VARIABLE_H_ 
#define NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_VARIABLE_H_ 

#include "node.hpp"


class Variable : public Node {

  protected:
    inline void compute() override {} 
 
    inline void update_feeders_dy() override {}
    inline void update() {
      *this->value += *this->dy;
    }

  public:
    ~Variable(){};
    Variable(Matrix * initial_value) : Node(initial_value) {}
};

#endif //NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_OPS_VARIABLE_H_ 