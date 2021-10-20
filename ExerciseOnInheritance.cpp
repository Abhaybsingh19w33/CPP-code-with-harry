// SimpleCalculator - Takes input of 2 numbers using a utility function and performs +, -, *, / and
// displays the results using another function.
// ScientificCalculator - Takes input of 2 numbers using a utility function and performs any four scientific operation of your chioice and displays the results using another function.
// Create another class HybridCalculator and inherit it using these 2 classes

#include <bits/stdc++.h>
using namespace std;

class SimpleCalculator
{
public:
    int multiplication(int a, int b)
    {
        return a * b;
    }

    int addition(int a, int b)
    {
        return a + b;
    }

    int subtraction(int a, int b)
    {
        return a - b;
    }

    float division(int a, int b)
    {
        return float(a)/float(b);
    }
};

class ScientificCalculator
{
public:
    float logarithm(float a)
    {
        return log(a);
    }

    float sinFunction(float a)
    {
        return sin(a);
    }

    float cosFunction(float a)
    {
        return cos(a);
    }
};

class HybridCalculator : public ScientificCalculator, public SimpleCalculator
{
};

int main()
{

    HybridCalculator HC;

    cout << HC.addition(1, 2) << endl;
    cout << HC.subtraction(1, 2) << endl;
    cout << HC.multiplication(1, 2) << endl;
    cout << HC.division(1, 2) << endl;
    cout << HC.sinFunction(1) << endl;
    cout << HC.cosFunction(1) << endl;
    cout << HC.logarithm(10) << endl;
    return 0;
}