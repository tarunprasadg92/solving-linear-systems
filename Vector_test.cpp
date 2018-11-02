#include <iostream>
#include <cassert>
#include "Vector.h"

using namespace std;

int main()
{
    cout << "\n\tTESTING VECTORS\n\n";
    cout << "Testing constructors...." << endl;
    
    Vector v1(5);

    double ele[] = {1.0, 1.0, 2.0};
    Vector v2(3, ele);

    Vector v3(v2);
    cout << "Success..." << endl;

    cout << "Testing Read() function..." << endl;
    assert(v1.Read(0) == 0);
    assert(v1.Read(4) == 0);
    assert(v2.Read(0) == 1.0);
    assert(v2.Read(2) == 2.0);
    assert(v3.Read(0) == 1.0);
    assert(v3.Read(2) == 2.0);
    cout << "Success..." << endl;

    cout << "Testing GetSize() function.." << endl;
    assert(v1.GetSize() == 5);
    assert(v2.GetSize() == 3);
    assert(v3.GetSize() == 3);
    cout << "Success..." << endl;

    cout << "Testing zero-based and one-based indexing..." << endl;
    double elements[] = {-2.0, -1.0, 0.0, 1.0, 2.0};
    Vector v4(5, elements);
    assert(v4[4] == 2.0);
    assert(v4[0] == -2.0);
    assert(v4(5) == 2.0);
    assert(v4(1) == -2.0);
    cout << "Success..." << endl;

    cout << "Testing operator overloading..." << endl;
    Vector v5 = v4;
    assert(v5[4] == 2.0);
    assert(v5[0] == -2.0);
    assert(v5(5) == 2.0);
    assert(v5(1) == -2.0);
    cout << "\"=\" success..." << endl;

    Vector v6 = (+v5);
    assert(v6[4] == 2.0);
    assert(v6[0] == -2.0);
    assert(v6(5) == 2.0);
    assert(v6(1) == -2.0);
    cout << "Unary \"+\" success..." << endl;
    
    Vector v7 = (-v5);
    assert(v7[4] == -2.0);
    assert(v7[0] == 2.0);
    assert(v7(5) == -2.0);
    assert(v7(1) == 2.0);
    cout << "Unary \"-\" success..." << endl;
   
    Vector v8 = v6 + v7;
    assert(v8[4] == 0.0);
    assert(v8[0] == 0.0);
    assert(v8(5) == 0.0);
    assert(v8(1) == 0.0);
    cout << "Binary \"+\" success..." << endl;

    Vector v9 = v5 - v6;
    assert(v9[4] == 0.0);
    assert(v9[0] == 0.0);
    assert(v9(5) == 0.0);
    assert(v9(1) == 0.0);
    cout << "Binary \"-\" success..." << endl;

    Vector v10 = v7 * 2;
    assert(v10[4] == -4.0);
    assert(v10[0] == 4.0);
    assert(v10(5) == -4.0);
    assert(v10(1) == 4.0);
    cout << "Scalar multiplication success..." << endl << endl;

    cout << "\tALL TEST CASES SUCCESS.." << endl << endl;

    return 0;
}
