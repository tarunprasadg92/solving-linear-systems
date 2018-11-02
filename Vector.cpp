#include <iostream>
#include <cstddef>
#include "Vector.h"

using namespace std;

// Copy Constructor
Vector::Vector(const Vector& otherVector)
{
    mSize = otherVector.mSize;
    mData = new double[mSize];
    for (int i = 0; i < mSize; i++)
    {
        mData[i] = otherVector.mData[i];
    }
}

// Constructor with size
Vector::Vector(int size)
{
    mSize = size;
    mData = new double[mSize];
}

// Constructor with size and data
Vector::Vector(int size, double *v)
{
    mSize = size;
    mData = new double[mSize];
    for (int i = 0; i < mSize; i++)
    {
        mData[i] = v[i];
    }
}

// Destructor
Vector::~Vector()
{
    mSize = 0;
    delete[] mData;
}

// Returns the number of elements in the vector
int Vector::GetSize() const
{
    return mSize;
}

// Returns reference of element at position i - starting from index 0
double& Vector::operator [] (int i)
{
    if ((i >= 0) && (i < mSize))
    {
        return mData[i];
    }
}

// Returns element at position i
double Vector::Read(int i) const
{
    return mData[i];
}

// Returns reference of element at position i - starting from index 1
double& Vector::operator () (int i)
{
    if ((i > 0) && (i <= mSize))
    {
        return mData[i - 1];
    }
}

// "=" Operator overloading
Vector& Vector::operator = (const Vector& otherVector)
{
    if (otherVector.mSize == mSize)
    {
        for (int i = 0; i < mSize; i++)
        {
            mData[i] = otherVector.mData[i];
        }
    }
}

// "Unary +" Operator overloading
Vector Vector::operator + () const
{
    Vector new_vector(mSize);
    for (int i = 0; i < mSize; i++)
    {
        new_vector.mData[i] = mData[i];
    }
    return new_vector;
}

// "Unary -" Operator overloading
Vector Vector::operator - () const
{
    Vector new_vector(mSize);
    for (int i = 0; i < mSize; i++)
    {
        new_vector.mData[i] = -mData[i];
    }
    return new_vector;
}

// "Binary +" Operator overloading
Vector Vector::operator + (const Vector& v1) const
{
    if (mSize == v1.mSize)
    {
        Vector new_vector(mSize);
        for (int i = 0; i < mSize; i++)
        {
            new_vector[i] = mData[i] + v1.mData[i];
        }
        return new_vector;
    }
}

// "Binary -" Operator overloading
Vector Vector::operator - (const Vector& v1) const
{
    if (mSize == v1.mSize)
    {
        Vector new_vector(mSize);
        for (int i = 0; i < mSize; i++)
        {
            new_vector[i] = mData[i] - v1.mData[i];
        }
        return new_vector;
    }
}

// "Binary *" Operator overloading
Vector Vector::operator * (double a) const
{
    Vector new_vector(mSize);
    for (int i = 0; i < mSize; i++)
    {
        new_vector[i] = mData[i] * a;
    }
    return new_vector;
}
