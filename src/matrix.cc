#include<stdlib.h>
#include<memory>
#include<math.h>

#include "../include/neat-dino-simulation/matrix.hpp"


///
///  For all the smart pointers release them first, otherwise there will be a memory loss
///
///


Matrix& Matrix::operator+(const Matrix &a) const{

  std::unique_ptr<Matrix> t(new Matrix(a.rows, a.columns));

  for(int i=0; i<this->rows * this->columns; i++) {
    *(t->values.get() + i) = *(a.values.get() + i) + *(this->values.get() + i);
  } 
  return *t.get();
}

Matrix& Matrix::operator-(const Matrix &a) const{

  std::unique_ptr<Matrix> t(new Matrix(a.rows, a.columns));

  for(int i=0; i<this->rows * this->columns; i++) {
    *(t->values.get() + i) = *(a.values.get() + i) - *(this->values.get() + i);
  } 
  return *t.get();
}

Matrix& Matrix::operator*(const Matrix &a) const {

  std::unique_ptr<Matrix> t(new Matrix(a.rows, a.columns));

  for(int i=0; i<this->rows * this->columns; i++) {
    *(t->values.get() + i) = *(a.values.get() + i) * *(this->values.get() + i);
  } 
  return *t.get();
}


Matrix& Matrix::operator*(const double a) const {

  std::unique_ptr<Matrix> t(new Matrix(this->rows, this->columns));

  for(int i=0; i<this->rows * this->columns; i++) {
    *(t->values.get() + i) = a * *(this->values.get() + i);
  } 
  return *t.get();
}

Matrix& Matrix::operator/(const Matrix &a) const {

  std::unique_ptr<Matrix> t(new Matrix(a.rows, a.columns));

  for(int i=0; i<this->rows * this->columns; i++) {
    *(t->values.get() + i) = *(a.values.get() + i) / *(this->values.get() + i);
  } 
  return *t.get();
}


Matrix& Matrix::operator^(const double a) const{

  std::unique_ptr<Matrix> t(new Matrix(this->rows, this->columns));

  for(int i=0; i<this->rows * this->columns; i++) {
    *(t->values.get() + i) =  pow(*(this->values.get() + i), a);
  } 
  return *t.get();
}

Matrix& Matrix::matmul(const Matrix &a, const Matrix &b) {
  std::unique_ptr<Matrix> t(new Matrix(a.rows, b.columns));
  for(int i=0; i<a.rows; i++) {
    for(int j=0; j<b.columns; j++) {
      double s = 0;
      for(int k=0; k<a.columns; k++) {
        s += a.get(i, k) + b.get(k, j);
      }
      *((*t.get()).values.get() + i) = s;
    }
  }
  return *t.get();
}

void Matrix::set_zero() {
  for(int i=0; i<this->rows * this->columns; i++) {
      this->values.get()[i] = 0;
  }
}

Matrix& Matrix::transpose(const Matrix &a) {
  Matrix *c = new Matrix(a.columns, a.rows);
  for(int j=0; j<a.columns; j++) {
    for(int i=0; i<a.rows; i++) {
      (c->values.get())[i * (a.columns) + j] = (a.values.get())[i * (a.columns) + j];
    }
    return *c;
  }
  
}