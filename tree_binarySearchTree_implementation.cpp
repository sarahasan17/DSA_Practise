#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
node* insert(node* root,int val){
    if(root==NULL){
        root=new node(val);
    }
    else if(root->data<val){
        root->right=insert(root->right,val);
    }
    else{
        root->left=insert(root->left,val);
    }
    return root;
}
bool search(node* root,int val){
    if(root==NULL){
        return false;
    }
    else if(root->data==val){
        return true;
    }
    else if(root->data<val){
        return search(root->right,val);
    }
    return search(root->left,val);
}
int findmin(node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}
node* deletenode(node* root,int val){
    if(root==NULL){
        return root;
    }
    else if(root->data<val){
        root->right=deletenode(root->right,val);
    }
    else if(root->data>val){
        root->left=deletenode(root->left,val);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        else if(root->left==NULL){
            node* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL){
            node* temp=root;
            root=root->left;
            delete temp;
        }
        else{
            int t=findmin(root->right);
            root->data=t;
            root->right=deletenode(root->right,t);
        }
    }
    return root;
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";    
        inorder(root->right);
    }
}
int main(){
    node* root=NULL;
    root=insert(root,4);
    root=insert(root,3);
    root=insert(root,2);
    root=insert(root,6);
    inorder(root);
    cout<<endl;
    root=deletenode(root,3);
    inorder(root);
    
}
