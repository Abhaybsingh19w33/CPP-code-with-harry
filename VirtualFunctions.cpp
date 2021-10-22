// A member function in the base class which is declared using virtual keyword is called virtual functions. They can be redefined in the derived class

// #include <iostream>
// using namespace std;

// class BaseClass
// {
// public:
//     int var_base = 1;
//     virtual void display()
//     {
//         cout << "1 Dispalying Base class variable var_base " << var_base << endl;
//     }
// };

// class DerivedClass : public BaseClass
// {
// public:
//     int var_derived = 2;
//     void display()
//     {
//         cout << "2 Dispalying Base class variable var_base " << var_base << endl;
//         cout << "2 Dispalying Derived class variable var_derived " << var_derived << endl;
//     }
// };

// int main()
// {
//     BaseClass *base_class_pointer;
//     BaseClass obj_base;
//     DerivedClass obj_derived;

//     base_class_pointer = &obj_derived;
//     base_class_pointer->display();
//     return 0;
// }

// The main thing to note here is that if we don’t use the “virtual” keyword with the “display” function of the base class then beside of the point that we have pointed our base call pointer to derived class object still the compiler would have called the “display” function of the base class because this is its default behavior as we have seen in the previous tutorial.

// But we have used the “virtual” keyword with the “display” function of the base class to make is virtual function so when the display function is called by using the base class pointer the display function of the derived class will run because the base class pointer is pointing to the derived class object.

// In C++ we are provided with the functionality to point the pointer to derived class or base class

#include <iostream>
using namespace std;
class BaseClass
{
public:
    int var_base = 0;
    virtual void display()
    {
        cout << "Dispalying Base class variable var_base " << var_base << endl;
    }
};

class DerivedClass : public BaseClass
{
public:
    int var_derived = 1;
    // virtual
    void display()
    {
        cout << "Dispalying Base class variable var_base " << var_base << endl;
        cout << "Dispalying Derived class variable var_derived " << var_derived << endl;
    }
};

class GrandDerivedClass : public DerivedClass
{
public:
    int var_grand_derived = 2;
    // virtual
    void display()
    {
        cout << "Dispalying Base class variable var_base " << var_base << endl;
        cout << "Dispalying Derived class variable var_derived " << var_derived << endl;
        cout << "Dispalying Derived class variable var_grand_derived " << var_grand_derived << endl;
    }
};

int main()
{
    // remember this will only work in base -> derived -> grandderived
    // small to big
    BaseClass obj_base;
    BaseClass *base_class_pointer;
    DerivedClass obj_derived;
    DerivedClass *derived_class_pointer;
    GrandDerivedClass obj_grand_derived;
    GrandDerivedClass *grand_derived_class_pointer;

    cout << "Base Class" << endl;
    base_class_pointer = &obj_base;
    base_class_pointer->display();

    cout << endl;
    // only base class memeber variables and functions can be invoked
    base_class_pointer = &obj_derived; // Pointing base class pointer to derived class
    // base_class_pointer->var_derived = 134; // Will throw an error
    base_class_pointer->display();

    cout << endl;
    base_class_pointer = &obj_grand_derived;
    base_class_pointer->display();

    // derived_class_pointer = &obj_base; // throws an error
    // derived_class_pointer->var_base = 9448;
    // derived_class_pointer->var_derived = 98;
    // derived_class_pointer->display();

    cout << endl
         << "Derived Class" << endl;
    derived_class_pointer = &obj_derived;
    derived_class_pointer->display();

    cout << endl;
    derived_class_pointer = &obj_grand_derived;
    derived_class_pointer->display();

    cout << endl
         << "Grand Derived Class" << endl;
    grand_derived_class_pointer = &obj_grand_derived;
    grand_derived_class_pointer->display();

    return 0;
}
