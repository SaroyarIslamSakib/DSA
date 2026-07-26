#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* next;

        Node(int val)
        {
            this->val = val;
            this->next = NULL;
        }
};
//REVERSE FUNCTION
void Reverse(Node* &head, Node*cur)
{
    if(cur->next == NULL)
    {
        head = cur;
        return;
    }
    Reverse(head,cur->next);
    cur->next->next = cur;
    cur->next = NULL;
}
//INPUT & OUTPUT
void InsertTail(Node* &head, Node* & tail, int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
}
void Print(Node* head)
{
    if(head == NULL)return;
    cout<<head->val<<" ";
    Print(head->next);
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    while(true)
    {
        int val;
        cin>>val;
        if(val == -1)break;
        InsertTail(head,tail,val);
    }
    Print(head);
    cout<<endl;

    //Reverse
    Reverse(head,head);

    Print(head);

    return 0;
}