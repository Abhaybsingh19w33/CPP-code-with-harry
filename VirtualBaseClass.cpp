// The virtual base class is a concept used in multiple inheritances to prevent ambiguity between multiple instances.

#include <iostream>
using namespace std;
class A
{
    
public:
    int a;
    A() {
        a = 0;
    }
    void say()
    {
        cout << "Hello world" << endl;
    }
};

class B : public virtual A
{
};

class C : public virtual A
{
};

class D : public B, public C
{
};

int main()
{
    A a;
    B b;
    C c;
    D d;

    a.say();
    cout << a.a << endl;
    b.say();
    cout << b.a << endl;
    c.say();
    cout << c.a << endl;
    d.say();
    cout << d.a << endl;

    return 0;
}