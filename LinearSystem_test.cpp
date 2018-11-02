#include <iostream>
#include <cassert>
#include "LinearSystem.h"

using namespace std;

int main()
{
    cout << "\n\tTESTING LINEAR SYSTEM\n\n";
    cout << "Testing constructor..." << endl;
    
    double m_ele[] = {0.0, 2.0, 1.0, 1.0, -2.0, -3.0, -1.0, 1.0, 2.0};
    Matrix m2(3, 3, m_ele);
    
    double v_ele[] = {-8.0, 0.0, 3.0};
    Vector v2(3, v_ele);
    
    LinearSystem L(m2, v2);
    cout << "Success... " << endl;
    
    cout << "Testing solve..." << endl;
    cout << "\nInput Matrix A : " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << m_ele[i * 3 + j] << "\t";
        }
        cout << endl;
    }
    
    cout << "\nInput Vector B : " << endl;
    for (int x = 0; x < 3; x++)
    {
        cout << v_ele[x] << "\t";
    }
    cout << endl << endl;
    Vector Result = L.Solve();
    cout << "Solutions : " << endl;
    cout << "X = " << Result.Read(0) << "\t" << "Y = " << Result.Read(1) << "\t" << "Z = " << Result.Read(2) << endl;
    cout << "Success..." << endl << endl;
    
    return 0;
}
