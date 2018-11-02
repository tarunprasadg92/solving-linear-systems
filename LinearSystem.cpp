#include <iostream>
#include <cstddef>
#include "LinearSystem.h"

using namespace std;

// Constructor to initialize matrix and vector
LinearSystem::LinearSystem(const Matrix& A, const Vector& b)
{
    int matrix_rows = A.GetNumberOfRows();
    int matrix_cols = A.GetNumberOfColumns();    
    double *matrix_data = new double[matrix_rows * matrix_cols];
    
    for (int x = 0; x < matrix_rows; x++)
    {
        for (int y = 0; y < matrix_cols; y++)
        {
            matrix_data[x * matrix_cols + y] = A.Read(x, y);
        }
    }
    
    mpA = new Matrix(matrix_rows, matrix_cols, matrix_data);
    
    int vector_size = b.GetSize();
    double *vector_data = new double[vector_size];
    for (int i = 0; i < vector_size; i++)
    {
        vector_data[i] = b.Read(i);
    }
    
    mpb = new Vector(vector_size, vector_data);
    
    mSize = vector_size;
}

// Destructor
LinearSystem::~LinearSystem()
{
    delete mpA;
    delete mpb;
    mSize = 0;    
}

// Returns vector of solutions for the given matrix and vector
Vector LinearSystem::Solve()
{
    // Create local array to store augmented matrix as vectors
    double *vector_1 = new double[4];
    double *vector_2 = new double[4];
    double *vector_3 = new double[4];
    
    // Initialize the local array with matrix values
    for (int i = 0; i < 3; i++)
    {
        vector_1[i] = mpA->Read(0, i);
        vector_2[i] = mpA->Read(1, i);
        vector_3[i] = mpA->Read(2, i);
    }
    
    // Add values from vector to local array
    vector_1[3] = mpb->Read(0);
    vector_2[3] = mpb->Read(1);
    vector_3[3] = mpb->Read(2);
    
    // Create vectors of augmented matrix - Each row is handled as a vector
    Vector v1(4, vector_1);
    Vector v2(4, vector_2);
    Vector v3(4, vector_3);
    
    // Temporary vector and variables used for computation
    Vector temp(4);
    double temp_val;
    
    // Make element at position (0,0) to be 1
    if (v1.Read(0) != 1)
    {
        if (v2.Read(0) == 1)
        {
            temp = v1;
            v1 = v2;
            v2 = temp;
        }
        else if (v3.Read(0) == 1)
        {
            temp = v1;
            v1 = v3;
            v3 = temp;
        }
        else
        {
            if (v1.Read(0) == 0)
            {
                temp = v1;
                v1 = v2;
                v2 = temp;
            }
            v1 = v1 * (1.0 / v1.Read(0));
        }
    }
    
    // Make element at position (1,0) to be 0
    if (v2.Read(0) != 0)
    {
        temp_val = v2.Read(0) / v1.Read(0);
        temp = v1 * temp_val;
        v2 = v2 - temp;
    }
    
    // Make element at position (2,0) to be 0
    if (v3.Read(0) != 0)
    {
        temp_val = v3.Read(0) / v1.Read(0);
        temp = v1 * temp_val;
        v3 = v3 - temp;
    }
    
    // Make element at position (1,1) to be 1
    if (v2.Read(1) != 1)
    {
        if (v3.Read(1) == 1)
        {
            temp = v2;
            v2 = v3;
            v3 = temp;
        }
        else
        {
            temp_val = (1 / (v2.Read(1)));
            v2 = v2 * temp_val;
        }
    }
    
    // Make element at position (2,1) to be 0
    if (v3.Read(1) != 0)
    {
        temp_val = v3.Read(1) / v2.Read(1);
        temp = v2 * temp_val;
        v3 = v3 - temp;
    }
    
    // Make element at position (2,2) to be 1
    if (v3.Read(2) != 1)
    {
        temp_val = (1 / (v3.Read(2)));
        v3 = v3 * temp_val;
    }

    // Substitute the values to get the values
    double solutions[3];
    solutions[2] = v3.Read(3);
    solutions[1] = v2.Read(3) - (v2.Read(2) * solutions[2]);
    solutions[0] = v1.Read(3) - ((v1.Read(2) * solutions[2]) + (v1.Read(1) * solutions[1]));
    
    // Store the values obtained in a vector and return
    Vector Solution(3, solutions);
    return Solution;
}
