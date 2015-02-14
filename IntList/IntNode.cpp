#include <iostream>
#include "IntNode.h"

IntNode::IntNode() : data(0), link(NULL) {
    // Default constructor
}

IntNode::IntNode(int value, IntNode *next) : data(value), link(next) {
// Constructs a node with a value and next link
}

// Accessor and Mutator methods follow
int IntNode::getData() const {
    return data;
}

IntNode* IntNode::getLink( ) const {
    return link;
}

void IntNode::setData(int value) {
    data = value;
}

void IntNode::setLink(IntNode *next) {
    link = next;
}
