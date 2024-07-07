#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};
void insert(TrieNode *root,string &k){
    TrieNode*  r=root;
    for(int i=0;i<k.length();i++){
        int b=k[i]-'a';
        if(r->child[b]==NULL){
            r->child[b]=new TrieNode();
        }
        r=r->child[b];
    }
    r->isEnd=true;
}
bool search(TrieNode *root,string &k){
    TrieNode*  r=root;
    for(int i=0;i<k.length();i++){
        int b=k[i]-'a';
        if(r->child[b]==NULL){
            return false;
        }
        r=r->child[b];
    }
    return r->isEnd;
}
bool isEmpty(TrieNode *root){
    for(int i=0;i<26;i++){
        if(root->child[i]!=NULL){
            return false;
        }
    }
    return true;
}
TrieNode* Delete(TrieNode *root,string &k,int i){
    if(root==NULL) return NULL;
    if(i==k.length()){
        root->isEnd=false;
        if(isEmpty(root)){
            delete(root);
            root=NULL;
        }
        return root;
    }
    int b=k[i]-'a';
    root->child[b]=Delete(root->child[b],k,i+1);
    if(isEmpty(root) && root->isEnd==false){
        delete(root);
        root=NULL;
    }
    return root;
}
int main(){
    TrieNode* root=new TrieNode();
    vector<string> data={"amma","abbu","sara","bhaiya"};
    for(int i=0;i<data.size();i++){
        insert(root,data[i]);
    }
    vector<string> searching={"sara","anas","abbu"};
    for(int i=0;i<searching.size();i++){
        bool val=search(root,searching[i]);
        cout<<searching[i]<<" found:"<<val<<endl;
    }
    string l="sara";
    root=Delete(root,l,0);
    bool val=search(root,l);
    cout<<"after deleting "<<l<<" found:"<<val<<endl;
    
    
}

