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
//REVERSE FUNCTION
void Reverse(Node* &head, Node* &tail)
{
    Node* i = head;
    Node* j = tail;
    while(i != j && i->next!=j)
    {
        swap(i->val,j->val);
        i = i->next;
        j = j->prev;
    }

}
//INPUT & OUTPUT
void InsertTail(Node* &head, Node* &tail, int val)
{
    Node * newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail->next->prev = tail;
    tail = tail->next;
}
void Print(Node* head)
{
    if(head == NULL)return;
    cout<<head->val<<" ";
    Print(head->next);
}
void PrintReverse(Node* tail)
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
    Node * head = NULL;
    Node * tail = NULL;
    while(true)
    {
        int val;
        cin>>val;
        if(val == -1)break;
        InsertTail(head,tail,val);
    }

    Print(head);
    cout<<endl;
    PrintReverse(tail);

    cout<<endl<<"Actual Reverse: "<<endl;
    Reverse(head,tail);
    Print(head);
    return 0;
}