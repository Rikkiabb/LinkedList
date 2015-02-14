#include <iostream>
#include "IntList.h"
using namespace std;

IntList::IntList() // Constructor: creates an empty list
{
    head = NULL;
}

IntList::~IntList() // Destructor
{
    removeAll();
}

int IntList::length() // Returns the length of the list
{
    int length = 0;
    NodePtr temp = head;
    for (; temp != NULL; temp = temp->getLink())
    {
        length++;
    }
    return length;
}

void IntList::headInsert(int the_number) // Inserts a node with value the_number at the head of the list
{
    NodePtr tmpPtr;
    tmpPtr = new IntNode(the_number, head);
    head = tmpPtr;
}

// Special case ef listinn er tómur, svo við þurfum að hugsa um það fyrst.
// Ef listinn er ekki tómur þá setjum við töluna sem kemur inn í nýja nóðu. Því næst þurfum við að komast í endann á listanum til að tengja núverandi endanóðu við nýju nóðuna okkar. Til þess förum við í endan með tmpptr og tengjum svo saman.
void IntList::endInsert(int the_number)  // Inserts a node with value the_number at the end of the list
{
    if (head == NULL)
    {
        headInsert(the_number);
    }
    else
    {
        NodePtr tmpPtr;
        NodePtr Insert = new IntNode(the_number, NULL);
        for(NodePtr end = head; end != NULL; end = end->getLink())
        {
            tmpPtr = end;
        }
        tmpPtr->setLink(Insert);
    }
}

// Hér er sértilvik ef fyrsta talan á listanum er talan sem við erum að leita af og því sjáum við fyrst um það.
// Ef fyrsta talan er ekki talan sem við erum að leita af þá byrjum við að reka okkur í gegnum listann þangað til við lendum á henni eða klárum listann.
// Ef við lendum á henni þá tengjum við stakið fyrir framan hana við stakið fyrir aftan hana og eyðum svo minninum sem við tókum frá.
void IntList::remove(int the_number)  // Removes the first instance of a node with value the_number from the list
{
    NodePtr tempHead = head;
    NodePtr tmp;
    if (head->getData() == the_number)
    {
        head = head->getLink();
        delete tempHead;
        return;
    }
    for(tempHead = head; tempHead != NULL; tempHead = tempHead->getLink())
    {
        if(tempHead->getLink()->getData() == the_number)
        {
            tmp = tempHead->getLink();
            tempHead->setLink(tempHead->getLink()->getLink());
            delete tmp;
            return;
        }
        
    }
}

// hendum minninum sem við erum taka frá hverju fyrir sig og eyðum svo hausnum.
void IntList::removeAll()  // Removes all the nodes in the list
{
    NodePtr temp;
    while (head != NULL)
    {
        temp = head;
        head = head->getLink();
        delete temp;
    }
    head = NULL;
}

// Hér eru tvo sértilvik. Í fyrsta lagi ef listinn er af stærð 0 eða 1 ef svo er þá breytist ekkert í honum í reverse og þá þurfum við ekki að gera neitt. Hinsvegar ef listinn er að stærð tveimur þetta er sértilvik þar sem við notum þrjá benda í almenna tilvikinu en ekki hér.
// Ef listinn er stærri þá erum við með þrjá pointera sem eru allir við hliðinn á hvor öðrum(það er þeir benda á nóður sem eru hlið við hlið) og þeir færast um eina nóðu í einu. Í hverri lykkju færum við svo ein bendir í einu. Þangað til við komumst í endann.
// Eftir forlykkjuna þurfum við svo einungis að stilla síðustu nóðurnar og þá er þetta komið.
void IntList::reverse()   // Reverses the order of the nodes in the list
{
    NodePtr next = NULL;
    NodePtr previous = NULL;
    NodePtr temp = NULL;
    if (length() < 2)
    {
        return;
    }
    if (length() == 2)
    {
        next = head->getLink();
        next->setLink(head);
        head->setLink(NULL);
        head = next;
        return;
    }
    next = head->getLink();
    previous = head;
    temp = next->getLink();
    for (; temp->getLink() != NULL; temp = temp->getLink())
    {
        next->setLink(previous);
        previous = next;
        next = temp;
    }
    next->setLink(previous);
    temp->setLink(next);
    head->setLink(NULL);
    head = temp;
}

ostream& operator <<(ostream& outs, const IntList& lis)
{
    NodePtr temp;
    temp = lis.head;
    for(; temp != NULL; temp = temp->getLink())
    {
        cout << temp->getData() << " ";
    }
    return outs;
}