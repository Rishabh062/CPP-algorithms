#include<bits\stdc++.h>
using namespace std;
struct Node 
{
    int data;
    Node* left;
    Node* right;
};
// Function for creating new node
 Node* CreateNode(int data){
    Node* newNode=new Node();
    if(!newNode){
        cout<<"Memory Error"<<"\n";
        return NULL;
    }
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;

}
// function for inserting element in binary tree
Node* InsertNode(Node* root,int data)
{
    if(root==NULL){
        root=CreateNode(data);
        return root;
    }
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->left!=NULL)
          q.push(temp->left);
        else{
            temp->left=CreateNode(data);
            return root;
        }
        if(temp->right!=NULL)
          q.push(temp->right);
        else{
            temp->right=CreateNode(data);
            return root;
        }
    }

}

// function for inorder
void inorder(Node* temp)
{
    if(temp==NULL)
      return ;
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);

    
}


int main(){
    Node* root= CreateNode(10);
    root->left=CreateNode(11);
    root->left->left=CreateNode(7);
    root->right=CreateNode(9);
    root->right->left=CreateNode(15);
    root->right->right=CreateNode(8);
    
    cout<<"Inorder traversal before insertion"<<"\n";
    inorder(root);
    cout<<"\n";

    int key=12;
    root= InsertNode(root,key);

    cout<<"Inorder traversal after insertion"<<"\n";
    inorder(root);
    cout<<"\n";
    return 0;
}