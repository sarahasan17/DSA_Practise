#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode *child[3];
    TrieNode(){
        for(int i=0;i<3;i++){
            child[i]=NULL;
        }
    }
};
bool insert(TrieNode *root,int mat[][3],int row){
    TrieNode *curr=root;
    bool flag=false;
    for(int i=0;i<3;i++){
        int b=mat[row][i];
        if(curr->child[b]==NULL){
            curr->child[b]=new TrieNode();
            flag=true;
        }
        curr=curr->child[b];
    }
    return flag;
}
int countdistinct(TrieNode *root,int mat[][3],int n){
    int c=0;
    for(int i=0;i<n;i++){
        if(insert(root,mat,i)==true){
            c++;
        }
    }
    return c;
}
int main(){
    TrieNode* root=new TrieNode();
    int mat[][3]={{0,0,1},{0,1,0},{0,0,1},{0,1,1}};
    int n=sizeof(mat)/sizeof(mat[0]);
    cout<<countdistinct(root,mat,n)<<endl;
}
