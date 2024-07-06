#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode *child[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};
void insert(TrieNode* root,string &k){
    for(int i=0;i<k.length();i++){
        int b=k[i]-'a';
        if(root->child[b]==NULL){
            root->child[b]=new TrieNode();
        }
        root=root->child[b];
    }
    root->isEnd=true;
}
bool search(TrieNode* root,string &k){
    for(int i=0;i<k.length();i++){
        int b=k[i]-'a';
        if(root->child[b]==NULL){
            return false;
        }
        root=root->child[b];
    }
    return root->isEnd;
}
bool isEmpty(TrieNode* root){
    for(int i=0;i<26;i++){
        if(root->child[i]!=NULL){
            return false;
        }
    }
    return true;
}
TrieNode* Delete(TrieNode* root,string &k,int i){
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
    vector<string> inputStrings
        = { "and", "ant", "do", "geek", "dad", "ball" ,"geeks"};

    // number of insert operations in the Trie
    int n = inputStrings.size();

    for (int i = 0; i < n; i++) {
        insert(root, inputStrings[i]);
    }
    //delete
    string word="geek";
    root=Delete(root,word,0);
    // Stores the strings that we want to search in the Trie
    vector<string> searchQueryStrings
        = { "do", "geeks", "bat" };
    // number of search operations in the Trie
    int searchQueries = searchQueryStrings.size();

    for (int i = 0; i < searchQueries; i++) {
        cout << "Query String: " << searchQueryStrings[i]
             << "\n";
        if (search(root, searchQueryStrings[i])) {
            // the queryString is present in the Trie
            cout << "The query string is present in the "
                    "Trie\n";
        }
        else {
            // the queryString is not present in the Trie
            cout << "The query string is not present in "
                    "the Trie\n";
        }
    }

    return 0;
}
