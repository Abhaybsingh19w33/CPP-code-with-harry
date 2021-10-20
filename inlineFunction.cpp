#include <iostream>
using namespace std;

inline int pro(int a, int b)
{
    return a * b;
}

float defaultValueFunction(int a, int b = 1) { 
    // here b is the default parameter 
    // if any value is not passed then the default value will be ste at its place
    return a*b;
}

// functions with const parameters
int main()
{
    cout << pro(2, 3) << endl;
    cout << defaultValueFunction(2, 3) << endl;
    cout << defaultValueFunction(2) << endl;

    return 0;
}

// inline functions should not be used in static variables and recursion functions