#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;
        Node* prev;

        Node(int val)
        {
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};
int GetSize(Node* head)
{
    int count = 0;
    while(head !=NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
void Insert_At_Head(Node* &head, Node* &tail, int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void Insert_At_Tail(Node* &head, Node* &tail, int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void Insert_At_Position(Node* &head, Node* &tail, int position, int val)
{
    int size = GetSize(head);
    if(position > size)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    else if(position == 0)
    {
        Insert_At_Head(head,tail,val);
        return;
    }
    else if(position == size)
    {
        Insert_At_Tail(head,tail,val);
        return;
    }
    else
    {
        Node* newNode = new Node(val);
        Node* temp = head;
        for(int i = 0; i<position-1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next->prev = newNode;
    }
}

void DeleteHead(Node*&head, Node*&tail)
{
    int size = GetSize(head);
    Node* deleteNode = head;
    if(size == 0)
    {
        cout<<"Linked List is empty"<<endl;
        return;
    }
    else if(size == 1)
    {
        head = NULL;
        tail = NULL;
        delete deleteNode;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
        delete deleteNode;
    }
}
void View(Node* head)
{
    while(head != NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
void ViewReverse(Node* tail)
{
    while(tail != NULL)
    {
        cout<<tail->val<<" ";
        tail = tail->prev;
    }
    cout<<endl;
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    while(true)
    {
        int Option;
        cout<<"----------------------------------------"<<endl;
        cout<<"1.Insert head"<<endl;
        cout<<"2.Insert tail"<<endl;
        cout<<"3.Insert at any position"<<endl;
        cout<<"4.Delete head"<<endl;
        cout<<"5.Delete tail"<<endl;
        cout<<"6.Delete at any position"<<endl;
        cout<<"7.View Linked List"<<endl;
        cout<<"8.View Linked List(Reverse)"<<endl;

        cout<<"9.Terminate"<<endl;
        cout<<"Choose a option: ";
        cin>>Option;
        cout<<endl<<"----------------------------------------"<<endl;

        if(Option == 1)
        {
            int val;
            cout<<"Value: ";
            cin>>val;
            Insert_At_Head(head,tail,val);
        }
        else if(Option == 2)
        {
            int val;
            cout<<"Value: ";
            cin>>val;
            Insert_At_Tail(head,tail,val);
        }
        else if(Option == 3)
        {
            int position;
            int val;
            cout<<"Position: ";
            cin>>position;
            cout<<"Value: ";
            cin>>val;

            Insert_At_Position(head,tail,position,val);
        }
        else if(Option == 4)
        {
            DeleteHead(head,tail);
        }

        else if(Option == 7)
        {
            View(head);
        }
        else if(Option == 8)
        {
            ViewReverse(tail);
        }
        else if(Option == 9)
        {
            break;
        }
    }
    return 0;
}