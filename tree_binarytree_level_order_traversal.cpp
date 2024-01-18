#include <iostream>
using namespace std;
#include <vector>
#include <queue>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

node* newnode(int data){
    struct node* root=new node();
    root->data=data;
    root->left=root->right=NULL;
    return root;
}
void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

vector<vector<int>> levelorder(struct node* root){
    vector<vector<int>> ans;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> lev;
        int len=q.size();
        for(int i=0;i<len;i++){
            struct node* temp=q.front();
            q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            lev.push_back(temp->data);
        }
        ans.push_back(lev);
    }
    return ans;
}

int main(){
    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    cout<<"Level Order traversal"<<endl;
    vector<vector<int>> ans=levelorder(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
