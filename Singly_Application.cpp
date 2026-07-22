#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int Value;
        Node* Next;
        Node(int value)
        {
            this->Value = value;
            this->Next = NULL;
        }
};
void InsertHead(Node* &Head, int Value)
{
    Node* NewNode = new Node(Value);
    NewNode->Next = Head;
    Head = NewNode;
}
void PrintLinkedList(Node* Head)
{
    while(Head != NULL)
    {
        cout<<Head->Value<<" ";
        Head = Head->Next;
    }
    cout<<endl;
}
void InsertTail(Node* &Head, int Value)
{
    Node* NewNode = new Node(Value);
    Node* Temp = Head;
    if(Head == NULL)InsertHead(Head,Value);
    else
    {
        while(Temp->Next != NULL)
        {
            Temp = Temp->Next;
        }
        Temp->Next = NewNode;
    }
}
void InsertAtPosition(Node* &Head, int Position, int Value)
{
    Node* NewNode = new Node(Value);
    Node* Temp = Head;
    if(Position == 0)
    {
        InsertHead(Head,Value);
    }
    else
    {
        for(int i = 0; i < Position - 1; i++)
        {
            if(Temp == NULL)
            {
                cout<<"-----------------------------------------"<<endl<<"Invalid Position"<<endl;
                return;
            }
            Temp = Temp->Next;
        }
        if(Temp == NULL)
        {
            cout<<"-----------------------------------------"<<endl<<"Invalid Position"<<endl;
            return;
        }
        NewNode->Next = Temp->Next;
        Temp->Next = NewNode;
    }
}
void DeleteHead(Node* &Head)
{
    if(Head == NULL)
    {
        cout<<"Head not available"<<endl;
        return;
    }
    Node * DeleteNode = Head;
    Head = Head->Next;
    delete(DeleteNode);
}
void DeleteTail(Node* &Head)
{
    Node* Temp = Head;
    if(Head == NULL)
    {
        DeleteHead(Head);
        return;
    }
    else if(Head->Next == NULL)
    {
        Node* DeleteNode = Head;
        Head = NULL;
        delete(DeleteNode);
        return;
    }
    while(Temp->Next->Next != NULL)
    {
        Temp = Temp->Next;
    }
    Node* DeleteNode = Temp->Next;
    Temp->Next = NULL;
    delete(DeleteNode);
}
void DeleteAtPosition(Node* &Head, int Position)
{
    if(Position == 0)
    {
        DeleteHead(Head);
        return;
    }
    Node* Temp = Head;
    for(int i=0; i<Position-1; i++)
    {
        if(Temp->Next == NULL)
        {
            cout<<"-----------------------------------------"<<endl<<"Invalid Position"<<endl;
            return;
        }
        Temp = Temp->Next;
    }
    if(Temp->Next == NULL)
    {
        cout<<"-----------------------------------------"<<endl<<"Invalid Position"<<endl;
        return;
    }
    Node* DeleteNode = Temp->Next;
    Temp->Next = Temp->Next->Next;
    delete(DeleteNode);
}
int main()
{
    Node* Head = NULL;
    while(true)
    {
        int Option;
        cout<<"1.Insert head"<<endl;
        cout<<"2.Insert tail"<<endl;
        cout<<"3.Insert at any position"<<endl;
        cout<<"4.Delete head"<<endl;
        cout<<"5.Delete tail"<<endl;
        cout<<"6.Delete at any position"<<endl;
        cout<<"7.View Linked List"<<endl;
        cout<<"8.Terminate"<<endl;
        cout<<"Choose a option: ";
        cin>>Option;
        cout<<endl<<"----------------------------------------"<<endl;


        if(Option == 1)
        {
            int Value;
            cout<<"Enter a value: ";
            cin>>Value;
            InsertHead(Head,Value);
        }
        else if(Option == 2)
        {
            int Value;
            cout<<"Enter a value: ";
            cin>>Value;
            InsertTail(Head,Value);
        }
        else if(Option == 3)
        {
            int Position,Value;
            cout<<"Position: ";
            cin>>Position;
            cout<<"Value: ";
            cin>>Value;
            InsertAtPosition(Head,Position,Value);
        }
        else if(Option == 4)
        {
            DeleteHead(Head);
        }
        else if(Option == 5)
        {
            DeleteTail(Head);
        }
        else if(Option == 6)
        {
            int Position;
            cout<<"Position: ";
            cin>>Position;
            DeleteAtPosition(Head,Position);
        }

        else if(Option == 7)
        {
            PrintLinkedList(Head);
        }
        else if(Option == 8)break;
        cout<<"-----------------------------------------"<<endl;
    }
    return 0;
}