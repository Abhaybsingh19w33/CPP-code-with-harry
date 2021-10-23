// What is a function object? Functor
// A function object is a function wrapped in a class so that it is available as an object.

// why to substitute a function with an object?
// The answer is to make them all usable in an Object-Oriented Programming paradigm.

#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    // Function Objects (Functor) : A function wrapped in a class so that it is available like an object
    int arr[] = {1, 73, 4, 2, 54, 7};
    sort(arr, arr + 5);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // this sort function to sort the array in descending order, is the greater<int>().
    // example  
    sort(arr, arr + 6, greater<int>());

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
