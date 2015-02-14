#ifndef INTNODE_H
#define INTNODE_H

class IntNode
{
    public:
        // Constructors to initialize a node
        IntNode();                      // Constructs a node with a 0 value and a NULL link
        IntNode(int value, IntNode *next); // Constructs a node with a value and next link

        int getData() const;    // Retrieve value for this node
        IntNode* getLink() const;  // Retrieve next node in the list

        void setData(int value); // Use to modify the value stored in the list
        void setLink(IntNode* next); // Use to change the reference to the next node

    private:
        int data;
        IntNode *link;
};

typedef IntNode* NodePtr;

#endif // INTNODE_H
