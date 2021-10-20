// Protected access modifiers are similar to the private access modifiers
// but protected access modifiers can be accessed in the derived class whereas
// private access modifiers cannot be accessed in the derived class.

// -----------------------------Public Derivation      	Private Derivation    	Protected Derivation
// Private members              Not Inherited           Not Inherited           Not Inherited
// Protected members            Protected               Private                 Protected
// Public members           	Public	                Private                 Protected

// protected variables can only be accessed through it memeber function
#include <iostream>
using namespace std;

class Base
{
protected:
    int protec;

private:
    int priva;

public:
    int getProtectdData()
    {
        return protec;
    }
};

class ProtectedDerived : protected Base
{
public:
    int c;

private:
    int d;

protected:
    int e;

public:
    ProtectedDerived()
    {
        protec = 1;
        // priva = 2;
        c = 3;
        d = 4;
        e = 5;
    }

    int getProtectedData()
    {
        return e;
    }
};

class PrivateDerived : private Base
{
public:
    int c;

private:
    int d;

protected:
    int e;
};

int main()
{
    Base b;
    ProtectedDerived ProDer;
    // cout << ProDer.protec; // not inherited
    // cout << ProDer.priva;   // not inherited
    cout << ProDer.c << endl; // public memeber
    // cout<< ProDer.d; // priavte member
    cout << ProDer.getProtectedData() << endl;
    PrivateDerived PrivateDerived;

    ProtectedDerived d;
    // cout<<d.a; // Will not work since a is protected in both base as well as derived class
    return 0;
}
