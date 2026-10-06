#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* left;
        Node* right;

        Node(int val)
        {
            this->val= val;
            this->left = NULL;
            this->right = NULL;
        }
};
vector<int> ans;
vector<int> preorder(Node* root)
{
    if( root == NULL) return ans;
    ans.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
    return ans;
}
vector<int> postorder(Node* root)
{
    if( root == NULL) return ans;
    postorder(root->left);
    postorder(root->right);
    ans.push_back(root->val);
    return ans;
}
vector<int> inorder(Node* root)
{
    if( root == NULL) return ans;
    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
    return ans;
}
vector<int> levelorder(Node* root)
{
    if( root == NULL) return ans;
    queue<Node*> q;   
    q.push(root);
    while(!q.empty())
    {
        //ber kore ani
        Node* temp = q.front();
        q.pop();
        //kaj kori
        ans.push_back(temp->val);

        //child gulo ke push kori
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return ans;
}
Node* InputBinaryTree()
{
    int val;
    cin>>val;
    Node* root;
    if(val == -1) root = NULL;
    else root = new Node(val);
    queue<Node*> q;
    if(root) q.push(root);


    while(!q.empty())
    {
        //ber kore ani
        Node* p = q.front();
        q.pop();

        //Kaj kori
        int l,r;
        cin>>l>>r;
        Node* leftNode;
        if(l == -1) leftNode = NULL;
        else leftNode = new Node(l);
        Node* rightNode;
        if(r == -1) rightNode = NULL;
        else rightNode = new Node(r);

        p->left = leftNode;
        p->right = rightNode;

        //Child push kori
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
    
}
int CountNodes(Node* root)
{
    if(root == NULL) return 0;
    int l = CountNodes(root->left);
    int r = CountNodes(root->right);
    return 1 + l + r;
}
int CountLeafNodes(Node* root)
{
    if(root == NULL) return 0;
    else if(root->left == NULL && root->right == NULL) return 1;
    int l = CountLeafNodes(root->left);
    int r = CountLeafNodes(root->right);
    return l + r;

}
int GetMaxHight(Node* root)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 0;
    int l = GetMaxHight(root->left);
    int r = GetMaxHight(root->right);
    return max(l,r) + 1;
}

int main()
{
    Node* root = InputBinaryTree();

    cout<<GetMaxHight(root);
    
}   