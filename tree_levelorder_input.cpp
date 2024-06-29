#include <iostream>
#include <queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* levelorder(node* root,vector<int> a){
    queue<node*> q;
    root=new node(a[0]);
    q.push(root);
    int i=1;
    while(!q.empty()){
        node* m=q.front();
        q.pop();
        if(i<a.size() && a[i]!=-1){
            m->left=new node(a[i]);
            q.push(m->left);
        }
        i++;
        if(i<a.size() && a[i]!=-1){
            m->right=new node(a[i]);
            q.push(m->right);
        }
        i++;
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
void levelorder_display(node *root){
    queue<node*> q;
    q.push(root);
    int i=1;
    while(!q.empty()){
        node* m=q.front();
        cout<<m->data<<" ";
        q.pop();
        if(m->left){
            q.push(m->left);
        }
        if(m->right){
            q.push(m->right);
        }
    }
}
int main(){
    node* root=NULL;
    vector<int> a={7,2,3,-1,4,-1,7};
    root=levelorder(root,a);
    levelorder_display(root);
    cout<<endl;
    inorder(root);
}
