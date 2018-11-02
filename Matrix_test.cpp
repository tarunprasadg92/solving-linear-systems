#include <iostream>
#include <cassert>
#include "Matrix.h"

using namespace std;

int main()
{
    cout << "\n\tTESTING MATRICES\n\n";
    cout << "Testing constructors..." << endl;
    
    Matrix m1(2, 2);
    
    double ele[] = {2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0};
    Matrix m2(3, 3, ele);
    
    Matrix m3(m2);
    cout << "Success..." << endl;
    
    cout << "Testing GetNumberOfRows() function..." << endl;
    assert(m1.GetNumberOfRows() == 2);
    assert(m2.GetNumberOfRows() == 3);
    assert(m3.GetNumberOfRows() == 3);
    cout << "Success..." << endl;
    
    cout << "Testing GetNumberOfColumns() function..." << endl;
    assert(m1.GetNumberOfColumns() == 2);
    assert(m2.GetNumberOfColumns() == 3);
    assert(m3.GetNumberOfColumns() == 3);
    cout << "Success..." << endl;
    
    cout << "Testing Read() function..." << endl;
    assert(m1.Read(0,0) == 0.0);
    assert(m1.Read(1,1) == 0.0);
    assert(m2.Read(0,0) == 2.0);
    assert(m2.Read(2,2) == 2.0);
    assert(m3.Read(1,1) == 2.0);
    assert(m3.Read(1,0) == 2.0);
    cout << "Success..." << endl;
    
    cout << "Testing one-based indexing..." << endl;
    double ele1[] = {1.0, 2.0, 3.0, 3.0, 2.0, 1.0, 4.0, 5.0, 6.0};
    Matrix m4(3, 3, ele1);
    assert(m4(1,1) == 1.0);
    assert(m4(1,2) == 2.0);
    assert(m4(2,1) == 3.0);
    assert(m4(2,3) == 1.0);
    assert(m4(3,2) == 5.0);
    assert(m4(3,3) == 6.0);
    cout << "Success..." << endl;
    
    cout << "Testing operator overloading..." << endl;
    Matrix m5 = m4;
    assert(m5(1,1) == 1.0);
    assert(m5(1,2) == 2.0);
    assert(m5(2,1) == 3.0);
    assert(m5(2,3) == 1.0);
    assert(m5(3,2) == 5.0);
    assert(m5(3,3) == 6.0);
    cout << "\"=\" Success..." << endl;
    
    Matrix m6 = (+m4);
    assert(m6(1,1) == 1.0);
    assert(m6(1,2) == 2.0);
    assert(m6(2,1) == 3.0);
    assert(m6(2,3) == 1.0);
    assert(m6(3,2) == 5.0);
    assert(m6(3,3) == 6.0);
    cout << "Unary \"+\" Success..." << endl;
    
    Matrix m7 = (-m4);
    assert(m7(1,1) == -1.0);
    assert(m7(1,2) == -2.0);
    assert(m7(2,1) == -3.0);
    assert(m7(2,3) == -1.0);
    assert(m7(3,2) == -5.0);
    assert(m7(3,3) == -6.0);
    cout << "Unary \"-\" Success..." << endl;
    
    Matrix m8 = m4 + m2;
    assert(m8(1,1) == 3.0);
    assert(m8(1,2) == 4.0);
    assert(m8(2,1) == 5.0);
    assert(m8(2,3) == 3.0);
    assert(m8(3,2) == 7.0);
    assert(m8(3,3) == 8.0);
    cout << "Binary \"+\" Success..." << endl;
    
    Matrix m9 = m4 - m2;
    assert(m9(1,1) == -1.0);
    assert(m9(1,2) == 0.0);
    assert(m9(2,1) == 1.0);
    assert(m9(2,3) == -1.0);
    assert(m9(3,2) == 3.0);
    assert(m9(3,3) == 4.0);
    cout << "Binary \"-\" Success..." << endl;
    
    cout << "Testing scalar multiplication..." << endl;
    Matrix m10 = m4 * 2;
    assert(m10(1,1) == 2.0);
    assert(m10(1,2) == 4.0);
    assert(m10(2,1) == 6.0);
    assert(m10(2,3) == 2.0);
    assert(m10(3,2) == 10.0);
    assert(m10(3,3) == 12.0);
    cout << "Success..." << endl;
    
    cout << "Testing CalculateDeterminant() function..." << endl;
    double determinant = m2.CalculateDeterminant();
    assert(determinant == 0.0);
    determinant = m4.CalculateDeterminant();
    assert(determinant == 0.0);
    cout << "Success..." << endl;
    
    cout << "Testing Matrix-Vector multiplication..." << endl;
    double v_ele[] = {1.0, 1.0, 1.0};
    Vector v(3, v_ele);
    Vector result_1 = m2 * v;
    assert(result_1.Read(0) == 6.0);
    assert(result_1.Read(1) == 6.0);
    assert(result_1.Read(2) == 6.0);
    cout << "Success..." << endl;
    
    cout << "Testing Vector-Matrix multiplication..." << endl;
    Vector result_2 = v * m2;
    assert(result_2.Read(0) == 6.0);
    assert(result_2.Read(1) == 6.0);
    assert(result_2.Read(2) == 6.0);
    cout << "Success..." << endl << endl;
    
    cout << "\tALL TEST CASES SUCCESS.." << endl << endl;
    
    return 0;
}
