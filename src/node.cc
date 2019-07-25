
#include "../include/neat-dino-simulation/node.hpp"
#include "../include/neat-dino-simulation/divide.hpp"
#include "../include/neat-dino-simulation/add.hpp"
#include "../include/neat-dino-simulation/subtract.hpp"
#include "../include/neat-dino-simulation/multiply.hpp"
#include "../include/neat-dino-simulation/matmul.hpp"

#include "./linked_list.hpp"

Node& Node::operator +(Node &a) {
  
  Node *t = new Add((*this->value).get_rows(), (*this->value).get_columns());
  Node::connect(&a, t);
  Node::connect(this, t);
  return *t;

};

Node& Node::operator *(Node &a) {
  
  Node *t = new Multiply((*this->value).get_rows(), (*this->value).get_columns());
  Node::connect(&a, t);
  Node::connect(this, t);
  return *t;

};

Node& Node::operator /(Node &a) {
  
  Node *t = new Divide((*this->value).get_rows(), (*this->value).get_columns());
  Node::connect(&a, t);
  Node::connect(this, t);
  return *t;

};

Node& Node::operator -(Node &a) {
  
  Node *t = new Subtract((*this->value).get_rows(), (*this->value).get_columns());
  Node::connect(&a, t);
  Node::connect(this, t);
  return *t;

};

Node& Node::matmul(Node &a, Node &b) {
  
  Node *t = new Matmul((*a.value).get_rows(), (*b.value).get_columns());
  Node::connect(&a, t);
  Node::connect(this, t);
  return *t;

};