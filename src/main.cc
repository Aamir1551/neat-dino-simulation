
#include "../include/neat-dino-simulation/variable.hpp"
#include "../include/neat-dino-simulation/add.hpp"
#include "../include/neat-dino-simulation/subtract.hpp"
#include "../include/neat-dino-simulation/multiply.hpp"
#include "../include/neat-dino-simulation/divide.hpp"
#include "../include/neat-dino-simulation/matmul.hpp"
#include "../include/neat-dino-simulation/matrix.hpp"
#include "../include/neat-dino-simulation/node.hpp"
#include "./linked_list.hpp"

using namespace std;

int main(int argc, const char **argv) {

  Matrix *b = new Matrix(1, 1, 5);
  Variable *a = new Variable(new Matrix(1, 1, 5));
  cout << "hey1" << endl;
  return 0;
}

