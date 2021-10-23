#include <iostream>
#include <vector>

// we can insert as many elements we want in a vector, without having to put some size parameter as in an array
using namespace std;
void display(vector<int> &v)
{
    // size() which returns the size of the vector
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> vec1;
    int element, size;
    cout << "Enter the size of your vector" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter an element to add to this vector: ";
        cin >> element;
        vec1.push_back(element);
        // push_back(), to insert elements in it from the rear end.
    }
    display(vec1);
    vec1.pop_back();
    // pop_back() This method of vectors, deletes the last element of the vector.
    display(vec1);
    vector<int>::iterator iter = vec1.begin();
    vec1.insert(iter, 566); //insert at the beginning of the vector
    // vec1.insert(iter + 1, 566); insert before 2 element
    // vec1.insert(iter,5, 566); // insert 5 time the data at beginning
    // vec1.insert(iter +1,5, 566); // insert 5 time the data before 2nd element
    display(vec1);
    // insert (iterator, element to insert):
    // This method of vectors inserts an element to the position the iterator is pointing to.

    // v.at(i) can be used instead of v[i]. They will work the same.
    // vector<int> vec1;        // zero length integer vector
    vector<char> vec2(4);    // 4-element character vector
    vector<char> vec3(vec2); // 4-element character vector from vec2
    vector<int> vec4(6, 3);  // 6-element vector of 3s

    return 0;
}
