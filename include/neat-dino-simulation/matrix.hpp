#ifndef NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_MATRIX_H_
#define NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_MATRIX_H_

#include<stdlib.h>
#include<stdio.h>
#include<memory>

class Matrix {

  private:
    std::unique_ptr<float> values;
    const int rows = 0;
    const int columns = 0;

  public:
    Matrix(int rows, int columns, double v = 0): rows(rows), columns(columns) {
      values = std::make_unique<float>(rows * columns);
      for(int i=0; i<rows * columns; i++) {
        *(values.get() + i)= v;
      }
    }

    ~Matrix() {
      this->values.reset();
    }

    inline const int get_rows() const {
      return this->rows;
    }

    inline const int get_columns() const {
      return this->columns;
    }

    static Matrix * randMatrix(int rows, int columns, int min, int max) {
      Matrix *temp = new Matrix(rows, columns);
      for(int i=0; i<rows*columns; i++) {
        *(temp->values.get() + i) = (rand() % (max-min)) + min;
      }
      return temp;
    }

    inline int get(int i, int j) const {
      return (*this->values.get() + i * columns + j);
    };

    void set_zero();

    static Matrix& transpose(const Matrix &a);
    
    Matrix& operator +(const Matrix& a) const;
    Matrix& operator -(const Matrix& a) const;
    Matrix& operator *(const Matrix& a) const;
    Matrix& operator *(const double a) const;
    Matrix& operator /(const Matrix& a) const;
    Matrix& operator ^(const double a) const;

    inline Matrix& operator *=(const double a) const {
      return *this *  a;
    };

    inline Matrix& operator *=(const Matrix& a) const {
      return (*this) *  a;
    };

    inline Matrix& operator /=(const Matrix& a) const {
      return *this /  a;
    };

    inline Matrix& operator +=(const Matrix &a) const {
     return *this+ a;
    };

    inline Matrix& operator -=(const Matrix &a) const{
      return (*this)-a;
    };

    static Matrix& matmul(const Matrix &a, const Matrix &b); 

};

inline Matrix& operator*(const double a, const Matrix &b) {
  return b*a; 
}

#endif //NEAT_DINO_GAME_COMPUTATIONAL_GRAPH_MATRIX_H_