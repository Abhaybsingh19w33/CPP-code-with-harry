// A List is a bi-directional linear storage of elements. Few key features as to why a list should be used is,

// It gives faster insertion and deletion operations.
// Its access to random elements is slow.

// What makes a list different from an array?

// An array stores the elements in a contiguous manner in which inserting some element calls for a shift of other elements, which is time taking. But in a list, we can simply change the address the pointer is pointing to.

#include <iostream>
#include <list>

using namespace std;

void display(list<int> &lst)
{
    list<int>::iterator it;
    // begin() and end() to define the starting and the end of the loop. end() returns the pointer next to the last element.
    // We dereference the list iterator, using * to print the element at that index.
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{

    list<int> list1; // empty list of 0 length

    list1.push_back(5);
    //  pop_back() to delete one element from the back of the list
    list1.push_back(7);
    list1.push_back(1);
    list1.push_back(9);
    list1.push_back(12);

    display(list1);

    list1.pop_back();
    display(list1);
    list1.pop_front();
    // pop_front() to delete elements from the front
    display(list1);

    // Using remove():
    // We can remove an element from a list by passing it in the list remove method. It will delete all the occurrences of that element. The remove method receives one value as a parameter and removes all the elements which match this parameter.
    list1.remove(9);
    display(list1);

    // Using sort():
    // We can sort a list in ascending order using its sort method
    list1.sort();
    display(list1);

    list<int> list2(3); // empty list of length 3
    list<int>::iterator it = list2.begin();
    *it = 45;
    it++;
    *it = 6;
    it++;
    *it = 9;
    it++;

    display(list2);
    // merges list2 at the back of list1
    list1.merge(list2);
    display(list1);
    return 0;
}
