#ifndef INTLIST_H
#define INTLIST_H
#include <iostream>
#include "IntNode.h"
using namespace std;

class IntList
{
    public:
        IntList();     // Constructor: creates an empty list
        ~IntList();    // Destructor

        int length(); // Returns the length of the list

        // Inserts a node with value the_number at the head of the list
        void headInsert(int the_number);

        // Inserts a node with value the_number at the end of the list
        void endInsert(int the_number);

        // Removes the first instance of a node with value the_number from the list
        void remove(int the_number);

        // Removes all the nodes in the list
        void removeAll();

        // Reverses the order of the nodes in the list
        void reverse();

        // A friend function for writing the contents of the list to an output stream
        friend ostream& operator <<(ostream& outs, const IntList& lis);

    private:
        NodePtr head; // pointer to the head of the list
};

#endif // INTLIST_H
