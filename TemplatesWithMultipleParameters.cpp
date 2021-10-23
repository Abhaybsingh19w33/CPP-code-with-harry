#include <iostream>
using namespace std;

/*
template<class T1, class T2>
class nameOfClass{
    //body
}
*/

class myClass1
{
public:
    int data1;
    char data2;
    void display()
    {
        cout << this->data1 << " " << this->data2 << endl;
    }
};

template <class T1, class T2>
class myClass2
{
public:
    T1 data1;
    T2 data2;
    myClass2(T1 a, T2 b)
    {
        data1 = a;
        data2 = b;
    }
    void display()
    {
        cout << this->data1 << " " << this->data2 << endl;
    }
};

int main()
{
    myClass2<int, char> obj(1, 'c');
    obj.display();

    myClass2<int, float> obj2(1, 1.8);
    obj2.display();
}
