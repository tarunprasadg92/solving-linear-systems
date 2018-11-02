#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF
#include "Vector.h"

class Matrix
{
private:
   double** mData; // entries of matrix
   int mNumRows, mNumCols; // dimensions
public:
   Matrix(const Matrix& otherMatrix);
   Matrix(int numRows, int numCols);
   Matrix(int numRows, int numCols, double *v);
   ~Matrix();
   int GetNumberOfRows() const;
   int GetNumberOfColumns() const;
   double Read(int i, int j) const;
   double& operator()(int i, int j); //1-based indexing
   //overloaded assignment operator
   Matrix& operator=(const Matrix& otherMatrix);
   Matrix operator+() const; // unary +
   Matrix operator-() const; // unary -
   Matrix operator+(const Matrix& m1) const; // binary +
   Matrix operator-(const Matrix& m1) const; // binary -
   // scalar multiplication
   Matrix operator*(double a) const;
   double CalculateDeterminant() const;
   // declare vector multiplication friendship
   friend Vector operator*(const Matrix& m, 
                           const Vector& v);
   friend Vector operator*(const Vector& v, 
                           const Matrix& m);
};
// prototype signatures for friend operators
Vector operator*(const Matrix& m, const Vector& v);
Vector operator*(const Vector& v, const Matrix& m);

#endif

