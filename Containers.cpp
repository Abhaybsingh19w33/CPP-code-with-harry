// Containers, objects which store data, Algorithms, set of procedures to process data, and Iterators, objects which point to some element in a container.

// Containers are themselves of three types: 

// Sequence Containers
// A sequence container stores that data in a linear fashion.

// Associative Containers
// An associative container is designed in such a way that enhances the accessing of some element in that container. It is very much used when the user wants to fastly reach some element. Some of these containers are, Set, Multiset, Map, Multimap etc.  They store their data in a tree-like structure.

// Derived Containers
// hese containers are derived from either the sequence or the associative containers. They often provide you with some better methods to deal with your data. They deal with real life modelling. Some examples of derived containers are Stack, Queue, Priority Queue, etc.


// In sequence containers, we have Vectors, which has following properties:

// Faster random access to elements in comparison to array
// Slower insertion and deletion at some random position, except at the end.
// Faster insertion at the end.

// In Lists, we have,

// Random accessing elements is too slow, because every element is traversed using pointers.
// Insertion and deletion at any position is relatively faster, because they only use pointers, which can easily be manipulated.

// In associative containers, every operation except random access is faster in comparison to any other containers, be it inserting or deleting any element.

// In associative containers, we cannot specifically tell which operation is faster or slower, we’ll have to inspect every data structure separately, and to get a clearer picture of all of these