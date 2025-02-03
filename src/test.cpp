#include <iostream>
#include "additup.hpp"

using namespace std;

int main(int argc, char* argv[])
{

    int n = add(2, 3);
    cout << "n = " << n << endl;

    int n2 = multiply(2, 3);
    cout << "n2 = " << n2 << endl;

    int n3 = pow(2, 3);
    cout << "n3 = " << n3 << endl;
    
    n3 = pow(3, 2);
    cout << "n3 = " << n3 << endl;
    
    n3 = pow(2, 0);
    cout << "n3 = " << n3 << endl;

    int n4 = sin(0);
    cout << "n4 = sin(0) = " << n4 << endl;
    
    int n5 = cos(0);
    cout << "n5 = cos(0) = " << n5 << endl;

    n4 = sin(pi/4);
    cout << "n4 = sin(0) = " << n4 << endl;
    
    n5 = cos(pi/4);
    cout << "n5 = cos(0) = " << n5 << endl;
    
    //int n6 = pi_();
    //cout << "n6 = pi = " << n6 << endl;

    cout << "pi = " << pi << endl;


    
    return 0;
}