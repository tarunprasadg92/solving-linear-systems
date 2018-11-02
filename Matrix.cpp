#include <iostream>
#include <cstddef>

#include "Matrix.h"
#include "Vector.h"

using namespace std;

// Copy Constructor
Matrix::Matrix(const Matrix& otherMatrix)
{
    mNumRows = otherMatrix.mNumRows;
    mNumCols = otherMatrix.mNumCols;
    
    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; i++)
    {
        mData[i] = new double[mNumCols];
    }
    
    for (int x = 0; x < mNumRows; x++)
    {
        for (int y  = 0; y < mNumCols; y++)
        {
            mData[x][y] = otherMatrix.mData[x][y];
        }
    }
}

// Constructor to create empty matrix with given rows and columns
Matrix::Matrix(int numRows, int numCols)
{
    mNumRows = numRows;
    mNumCols = numCols;
    
    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; i++)
    {
        mData[i] = new double[mNumCols];
    }
}

// Constructor to create matrix with given data and rows and columns
Matrix::Matrix(int numRows, int numCols, double *v)
{
    mNumRows = numRows;
    mNumCols = numCols;
    
    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; i++)
    {
        mData[i] = new double[mNumCols];
    }
    
    for (int x = 0; x < mNumRows; x++)
    {
        for (int y  = 0; y < mNumCols; y++)
        {
            mData[x][y] = v[x * mNumCols + y];
        }
    }
}

// Destructor
Matrix::~Matrix()
{
    for (int x = 0; x < mNumRows; x++)
    {
        delete[] mData[x];
    }
    delete[] mData;
    
    mNumRows = 0;
    mNumCols = 0;
}

// Returns number of rows in the matrix
int Matrix::GetNumberOfRows() const
{
    return mNumRows;
}

// Returns number of columns in the matrix
int Matrix::GetNumberOfColumns() const
{
    return mNumCols;
}

// Return element at position i,j - 0-based indexing
double Matrix::Read(int i, int j) const
{
    return mData[i][j];
}

// Return element at position i,j - 1-based indexing
double& Matrix::operator () (int i, int j)
{
    if ((i > 0) && (i <= mNumRows) && (j > 0) && (j <= mNumCols))
    {
        return mData[i - 1][j - 1];
    }
}

// "=" Operator overloading
Matrix& Matrix::operator = (const Matrix& otherMatrix)
{
    if ((mNumRows == otherMatrix.mNumRows) && (mNumCols == otherMatrix.mNumCols))
    {
        for (int x = 0; x < mNumRows; x++)
        {
            for (int y  = 0; y < mNumCols; y++)
            {
                mData[x][y] = otherMatrix.mData[x][y];
            }
        }
    }
}

// "Unary +" Operator overloading
Matrix Matrix::operator + () const
{
    Matrix new_matrix(mNumRows, mNumCols);
    for (int x = 0; x < mNumRows; x++)
    {
        for (int y  = 0; y < mNumCols; y++)
        {
            new_matrix.mData[x][y] = mData[x][y];
        }
    }
    return new_matrix;
}

// "Unary -" Operator overloading
Matrix Matrix::operator - () const
{
    Matrix new_matrix(mNumRows, mNumCols);
    for (int x = 0; x < mNumRows; x++)
    {
        for (int y  = 0; y < mNumCols; y++)
        {
            new_matrix.mData[x][y] = -mData[x][y];
        }
    }
    return new_matrix;
}

// "Binary +" Operator overloading
Matrix Matrix::operator + (const Matrix& m1) const
{
    if ((mNumRows == m1.mNumRows) && (mNumCols == m1.mNumCols))
    {
        Matrix new_matrix(mNumRows, mNumCols);
        for (int x = 0; x < mNumRows; x++)
        {
            for (int y  = 0; y < mNumCols; y++)
            {
                new_matrix.mData[x][y] = mData[x][y] + m1.mData[x][y];
            }
        }
        return new_matrix;
    }
}

// "Binary -" Operator overloading
Matrix Matrix::operator - (const Matrix& m1) const
{
    if ((mNumRows == m1.mNumRows) && (mNumCols == m1.mNumCols))
    {
        Matrix new_matrix(mNumRows, mNumCols);
        for (int x = 0; x < mNumRows; x++)
        {
            for (int y  = 0; y < mNumCols; y++)
            {
                new_matrix.mData[x][y] = mData[x][y] - m1.mData[x][y];
            }
        }
        return new_matrix;
    }
}

// "Binary *" Operator overloading
Matrix Matrix::operator * (double a) const
{
    Matrix new_matrix(mNumRows, mNumCols);
    for (int x = 0; x < mNumRows; x++)
    {
        for (int y  = 0; y < mNumCols; y++)
        {
            new_matrix.mData[x][y] = mData[x][y] * a;
        }
    }
    return new_matrix;
}

// Returns the determinant value of the matrix
double Matrix::CalculateDeterminant() const
{
    double det = 0.0;
    if ((mNumRows == 2) && (mNumCols == 2))
    {
        det = (mData[0][0] * mData[1][1]) - (mData[0][1] * mData[1][0]);
    }
    
    if ((mNumRows == 3) && (mNumCols == 3))
    {
        det = mData[0][0] * ((mData[1][1] * mData[2][2]) - (mData[1][2] * mData[2][1])) - mData[0][1] * ((mData[1][0] * mData[2][2]) - (mData[1][2] * mData[2][0])) + mData[0][2] * ((mData[1][0] * mData[2][1]) - (mData[2][0] * mData[1][1]));
    }
    return det;
}

// Performs matrix-vector multiplication
Vector operator * (const Matrix& m, const Vector& v)
{
    int vector_size = v.GetSize();
    if ((m.mNumRows == m.mNumCols) && (m.mNumCols == vector_size))
    {    
        double *rhs_array = new double[vector_size];
        for (int i = 0; i < vector_size; i++)
        {
            rhs_array[i] = v.Read(i);
        }
        double *result_array = new double[vector_size];        
                
        for (int x = 0; x < m.mNumRows; x++)
        {
            double temp = 0.0;
            for (int y  = 0; y < m.mNumCols; y++)
            {
                temp += m.mData[x][y] * rhs_array[y];
            }
            result_array[x] = temp;
        }
        Vector result(vector_size, result_array);
        return result;
    }
}

// Performs vector-matrix multiplication
Vector operator * (const Vector& v, const Matrix& m)
{
    int vector_size = v.GetSize();
    if ((m.mNumRows == m.mNumCols) && (m.mNumRows == vector_size))
    {    
        double *lhs_array = new double[vector_size];
        for (int i = 0; i < vector_size; i++)
        {
            lhs_array[i] = v.Read(i);
        }
        double *result_array = new double[vector_size];
        
        for (int x = 0; x < m.mNumCols; x++)
        {
            double temp = 0.0;
            for (int y  = 0; y < m.mNumRows; y++)
            {
                temp += lhs_array[y] * m.mData[y][x];
            }
            result_array[x] = temp;
        }
        Vector result(vector_size, result_array);
        return result;
    }
}
