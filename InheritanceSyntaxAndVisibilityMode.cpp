#include <iostream>
using namespace std;

// Base Class
class Employee
{
public:
    int id;
    float salary;
    Employee(int inpId)
    {
        id = inpId;
        salary = 34.0;
    }
    Employee() {}
};

// Derived Class syntax
// class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
// {
//     class members/methods/etc...
// }

// Creating a Programmer class derived from Employee Base class
// Default visibility mode is private
// Public Visibility Mode: Public members of the base class becomes Public members of the derived class
// Private Visibility Mode: Public members of the base class become private members of the derived class
// Private members are never inherited
class Programmer : public Employee
{
public:
    int languageCode;
    Programmer(int inpId)
    {
        id = inpId;
        languageCode = 9;
    }
    void getData()
    {
        cout << id << endl;
    }
    // Constructors are not inherited.They are called implicitly or explicitly by the child constructor.The compiler creates a default constructor(one with no arguments) and a default copy constructor(one with an argument which is a reference to the same type).
    // Programmer() {}
};

int main()
{
    Employee harry(1), rohan(2);
    cout << harry.salary << endl;
    cout << rohan.salary << endl;
    Programmer skillF(10);
    cout << skillF.languageCode << endl;
    cout << skillF.id << endl;
    skillF.getData();
    return 0;
}
