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
void InsertTail(Node* &head, Node* &tail, int val)
{
    Node* NewNode = new Node(val);
    if(head == NULL)
    {
        head = NewNode;
        tail = NewNode;
    }
    else
    {
        tail->next = NewNode;
        tail = tail->next;
    }
}
void View(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void ReversePrint(Node* head)
{
    if(head == NULL)return;
    ReversePrint(head->next);
    cout<<head->val<<" ";
}

void Sort(Node* head)
{
    for(Node* i = head; i->next != NULL; i = i->next)
    {
        for(Node* j = i->next; j != NULL; j = j->next)
        {
            if(i->val > j->val) swap(i->val,j->val);
        }
    }
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
    View(head);
    Sort(head);
    View(head);
    ReversePrint(head);
    return 0;
}