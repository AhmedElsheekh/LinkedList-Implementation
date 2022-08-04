#include <iostream>

using namespace std;

//-------------------------------------//
//access
//insertion: append, prepend, insert
//deletion: front, middle, back
//search
//-----------------------------------//

//Singly Linked List

class Node
{
public:
    int data;
    Node* next;

    Node(int d):data(d),next(NULL)
    {
    }
};

class Linkedlist
{
public:
    Node* head;
    Node* tail;
    int counter;
public:
    Linkedlist()     //CREATION  time memory O(1)
    {
        head = tail = NULL;
        counter = 0;
    }

    bool isempty()     //time memory O(1)
    {
        return head == NULL;
    }

    void display()         //time O(n) memory O(1)
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    int counte()     //time O(n) memory O(1)
    {
        /*int counter = 0;
        Node* temp = head;
        while(temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;*/

        int c = 0;
        for(Node* temp = head; temp != NULL; temp = temp->next)
            c++;
        return c;
    }

    int getCounter()
    {
        return counter;
    }

    bool isfound(int key)    //time O(n) memory O(1)
    {
        for(Node* temp = head; temp != NULL; temp = temp->next)
        {
            if(temp->data == key)
                return true;
        }
        return false;

        /*Node* temp = head;
        while(temp != NULL)
        {
            if(temp->data == key)
                return true;
        }
        return false;*/
    }

    void insertfirst(int item)  //time memory O(1)
    {
        Node* newnode = new Node(item);

        if(isempty())
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }

        counter++;
    }

    void insertbefore(int item, int newval)   //time 0(n) memory O(1)
    {
        //validation
        if(isempty())
        {
            insertfirst(item);
            return;
        }

        if(!isfound(item))
        {
            cout << item << " is not found to insert before\n";
            return;
        }

        if(item == head->data)
        {
            insertfirst(newval);
            return;
        }

        Node* newnode = new Node(newval);

        Node* temp = head;
        while(temp != NULL && temp->next->data != item)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
        counter++;
    }

    void append(int newv)    //time memory O(1)
    {
        //validation
        if(isempty())
        {
            insertfirst(newv);
            return;
        }
        else
        {
            Node* newnode = new Node(newv);

            tail->next = newnode;
            tail = newnode;
        }
    }

    void delet(int val)     //time O(n) memory O(1)
    {
        Node* delptr = head;
        Node* prev = NULL;

        // delete first node
        if(val == head->data)
        {
            head = head->next;
            delete delptr;
            return;
        }
        else
        {
            while(delptr->data != val)
            {
                prev = delptr;
                delptr = delptr->next;
            }

            prev->next = delptr->next;
            delete delptr;
        }

    }

    void revers()     //time O(n) memory O(1)
    {
        Node* prev, *curr, *fron;

        prev = NULL;
        curr = head;
        fron = head->next;

        while(curr != tail)
        {
            curr->next = prev;
            prev = curr;
            curr = fron;
            fron = fron->next;
        }

        curr->next = prev;
        tail = head;
        head = curr;

    }

    int getTailData(){return tail->data;}
    int getHeadData(){return head->data;}

};

//=======================================================================//

//Doubly Linked List

class DoNode
{
public:
    int data;
    DoNode* next;
    DoNode* prev;
public:
    DoNode(int d)
    {
        data = d;
        next = prev = NULL;
    }
};

class DoublyLinkedList
{
private:
    DoNode* head;
    DoNode* tail;
    int counter;
public:
    DoublyLinkedList()
    {
        head = tail = NULL;
        counter = 0;
    }

    bool isempty()     //time memory O(1)
    {
        return head == NULL;
    }

    bool isfull(int k)     //time memory O(1)
    {
        DoNode* newnode = new DoNode(k);
        return newnode == NULL;
    }

    void insertfirst(int k)    //time memory O(1)
    {
        DoNode* newnode = new DoNode(k);
        if(isempty())
        {
            head = tail = newnode;
        }
        else
        {
            head->prev = newnode;
            newnode->next = head;
            head = newnode;

        }
        counter++;
    }

    void append(int k)      //time memory O(1)
    {
        DoNode* newnode = new DoNode(k);

        if(isempty())
            insertfirst(k);
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            counter++;
        }
    }

    int counte()     //time memory O(1)
    {
        return counter;
    }

    void display()    //time O(n) memory O(1)
    {
        if(isempty())
            return;

        cout << "display from head to back\n";
        DoNode* temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";

        cout << "display from back to head\n";
        /*
        Node* temp1 = head;
        while(temp1 != NULL && temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        while(temp1 != NULL)
        {
            cout << temp1->data << " ";
            temp1 = temp1->prev;
        }
        cout << "\n";
        */

        DoNode* temp1 = tail;
        while(temp1)
        {
            cout << temp1->data << " ";
            temp1 = temp1->prev;
        }
    }

    void deletefirst()     //time memory O(1)
    {
        DoNode* temp = head;
        head = head->next;
        head ->prev = NULL;
        delete temp;
        counter--;
    }

    void deleteback()     //time memory O(1)
    {
        if(head->next == NULL)
        {
            deletefirst();
            return;
        }

        /*
        Node* temp = head;
        while(temp != NULL && temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        */

        DoNode* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        counter--;
    }

    void deleteItem(int k)  //time O(n) memory O(1)
    {
        DoNode* delptr = head;
        DoNode* before = NULL;

        if(delptr->data == k)
        {
            head = head->next;
            head->prev = NULL;
            delete delptr;
            counter--;
            return;
        }

        while(delptr->data != k)
        {
            before = delptr;
            delptr = delptr->next;
        }

        before->next = delptr->next;
        delptr->next->prev = before;
        delete delptr;
        counter--;

    }

    int getTailData(){return tail->data;}
    int getHeadData(){return head->data;}


};

int main()
{
    Linkedlist lst;

    lst.append(10);
    lst.append(20);
    lst.append(30);
    lst.append(40);

    lst.display();
    cout << "\n";

    lst.insertfirst(100);
    lst.insertfirst(200);
    lst.display();
    cout << "\n";

    lst.insertbefore(100, -4);
    lst.display();
    cout << "\n";
    cout << "head " << lst.getHeadData() << endl;
    cout << "tail " << lst.getTailData() << endl;
    cout << "\n";

    lst.revers();
    lst.display();
    cout << "\n";
    cout << "head " << lst.getHeadData() << endl;
    cout << "tail " << lst.getTailData() << endl;
    cout << "\n";

    cout << lst.isfound(100) << endl;
    cout << lst.isfound(0) << endl;

    lst.delet(100);
    lst.display();
    cout << "\n---------------------------------------------------------\n";

    //---------------------------------------------------//

    DoublyLinkedList dls;
    dls.append(10);
    dls.append(20);
    dls.append(30);
    dls.append(40);
    dls.append(50);
    dls.display();
    cout << "\n";

    dls.insertfirst(-5);
    dls.insertfirst(-10);
    dls.display();
    cout << "\n";

    dls.deleteItem(20);
    dls.display();
    cout << "\n";

    cout << dls.counte() << endl;
    cout << dls.getHeadData() << endl;
    cout << dls.getTailData() << endl;


    return 0;
}
