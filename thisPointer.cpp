// “this” is a keyword that is an implicit pointer.
// “this” pointer points to the object which calls the member function

#include <iostream>
using namespace std;

// Example 1
class A
{
    int a;

public:
    void setData(int a)
    {
        this->a = a;
    }

    void getData()
    {
        cout << "The value of a is " << a << endl;
    }
};

// Example 2
// “this” pointer can be used to return a reference to the invoking object.

class B
{
    int a;

public:
    // return B object on which i can perform another fucntion
    // this can be used on Left hand side also
    B &setData(int a)
    {
        this->a = a;
        return *this;
    }

    void getData()
    {
        cout << "The value of a is " << a << endl;
    }
};

int main()
{
    A a;
    a.setData(4);
    a.getData();

    B b;
    b.setData(4).getData();
    return 0;
}
