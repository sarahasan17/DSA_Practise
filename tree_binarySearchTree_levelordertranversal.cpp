//Binary tree:Has at max 2 children node
//Binary search tree:First root, if the value is smaller add it to the left subtree and if the value is more add it to the right sub tree

#include <iostream>
using namespace std;
#include <queue>
#include <vector>
struct node{
    int data;
    node *left;
    node *right;
};
node* getnewnode(int a){
    node* newnode=new node();
    newnode->data=a;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node* insert(node* root,int a){
        if(root==NULL){
            root=getnewnode(a);
        }
        else if(a<=root->data){
            root->left=insert(root->left,a);
        }
        else{
            root->right=insert(root->right,a);
        }
        return root;
    }
    
bool search(node *root,int a){
        if(root==NULL){
            return false;
        }
        else if(root->data==a){
            return true;
        }
        else if(a<=root->data){
            return search(root->left,a);
        }
        else{
            return search(root->right,a);
        }
}
node* findmin(struct node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
struct node *deletenode(struct node* root,int data){
    if(root==NULL){
        return root;
    }
    else if(data<root->data){
        root->left=deletenode(root->left,data);
    }
    else if(data>root->data){
        root->right=deletenode(root->right,data);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        else if(root->right==NULL){
            struct node* temp=root;
            root=root->left;
            delete temp;
        }
        else if(root->left==NULL){
            struct node* temp=root;
            root=root->right;
            delete temp;
        }
        else{
            struct node* temp=findmin(root->right);
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
        }
        
    }
    return root;
    
}
vector<vector<int>> levelorder(struct node* root){
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        vector <int> lev;
        int len=q.size();
        for(int i=0;i<len;i++){
            node* a=q.front();
            q.pop();
            if(a->left!=NULL){
                q.push(a->left);
            }
            if(a->right!=NULL){
                q.push(a->right);
            }
            lev.push_back(a->data);
        }
        ans.push_back(lev);
    }
}
int main(){
    node* root=NULL;
    root=insert(root,2);
    root=insert(root,1);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,3);
    //level order traversal;
    vector <vector<int>> new1=levelorder(root);
    for(int i=0;i<new1.size();i++){
        for(int j=0;j<new1[i].size();j++){
            cout<<new1[i][j]<<' ';
        }
        cout<<endl;
    }
}
