// In C++ we are provided with the functionality to point the pointer to derived class or base class

#include <iostream>
using namespace std;
class BaseClass
{
public:
    int var_base;
    void display()
    {
        cout << "Dispalying Base class variable var_base " << var_base << endl;
    }

    BaseClass()
    {
        cout << endl
             << "BaseClass Constructor" << endl;
    }
};

class DerivedClass : public BaseClass
{
public:
    int var_derived;
    void display()
    {
        cout << "Dispalying Base class variable var_base " << var_base << endl;
        cout << "Dispalying Derived class variable var_derived " << var_derived << endl;
    }

    DerivedClass()
    {
        cout << endl
             << "DerivedClass Constructor" << endl;
    }
};

class GrandDerivedClass : public DerivedClass
{
public:
    int var_grand_derived;
    void display()
    {
        cout << "Dispalying Base class variable var_base " << var_base << endl;
        cout << "Dispalying Derived class variable var_derived " << var_derived << endl;
        cout << "Dispalying Derived class variable var_grand_derived " << var_grand_derived << endl;
    }

    GrandDerivedClass()
    {
        cout << endl
             << "GrandDerivedClass Constructor" << endl;
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

    cout << endl;
    base_class_pointer = &obj_base;
    base_class_pointer->var_base = 3400;
    base_class_pointer->display();

    cout << endl;

    // only base class memeber variables and functions can be invoked
    base_class_pointer = &obj_derived; // Pointing base class pointer to derived class
    base_class_pointer->var_base = 34;
    // base_class_pointer->var_derived = 134; // Will throw an error
    base_class_pointer->display();

    cout << endl;
    base_class_pointer = &obj_grand_derived;
    base_class_pointer->var_base = 0;
    base_class_pointer->display();

    // derived_class_pointer = &obj_base; // throws an error
    // derived_class_pointer->var_base = 9448;
    // derived_class_pointer->var_derived = 98;
    // derived_class_pointer->display();

    cout << endl;
    derived_class_pointer = &obj_derived;
    derived_class_pointer->var_base = 9448;
    derived_class_pointer->var_derived = 98;
    derived_class_pointer->display();

    cout << endl;
    derived_class_pointer = &obj_grand_derived;
    derived_class_pointer->var_base = 9448;
    derived_class_pointer->var_derived = 98;
    derived_class_pointer->display();
    
    cout << endl;
    grand_derived_class_pointer = &obj_grand_derived;
    grand_derived_class_pointer->var_base = 0;
    grand_derived_class_pointer->var_derived = 1;
    grand_derived_class_pointer->var_grand_derived = 2;
    grand_derived_class_pointer->display();

    return 0;
}
