/*
Syntax for initialization list in constructor:
constructor (argument-list) : initilization-section
{
    assignment + other code;
}

*/

// The initialization list in constructors is another concept of initializing the data members of the class

#include <iostream>
using namespace std;

class Test
{
    int a;
    int b;

public:
// this is not a function constructor
// this is just to initilaize a value, it only looks like a constructor
    Test(int i, int j) : a(i), b(j)
    {
        cout << "Constructor executed" << endl;
        cout << "Value of a is " << a << endl;
        cout << "Value of b is " << b << endl;
    }
};

int main()
{
    Test t(4, 6);

    return 0;
}


// The main thing to note here is that if we use the code shown below to initialize data members the compiler will throw an error because the data member “a” is being initialized first and the “b” is being initialized second so we have to assign the value to “a” data member first.

// Test(int i, int j) : b(j), a(i+b)
// Code Snippet 3: Initialization list in Constructors Example 1

// But if we use the code shown below to initialize data members the compiler will not throw an error because the data member “a” is being initialized first and we are assigning the value to the data member “a” first.

// Test(int i, int j) : a(i), b(a + j)