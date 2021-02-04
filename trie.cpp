#include<bits/stdc++.h>
using namespace std;

#define alphabet_size 26

struct Trie{
    Trie* children[alphabet_size];
    bool endofword;
};

Trie* newnode(){
    Trie* pnode=new Trie;
    pnode->endofword=false;
    for(int i=0;i<alphabet_size;++i)
        pnode->children[i]=nullptr;
}

void insert(Trie* root,string key)
{
    Trie* cur=root;
    for(int i=0;i<key.length();++i)
    {
        int idx=key[i]-'a';
        if(cur->children[idx]==nullptr)
            cur->children[idx]=newnode();
        cur=cur->children[idx];
    }
    cur->endofword=true;
}

bool search(Trie* root, string key)
{
    Trie* cur=root;
    for(int i=0;i<key.length();++i)
    {
        int idx=key[i]-'a';
        if(cur->children[idx]==nullptr)
            return false;
        cur=cur->children[idx];
    }
    if(cur!=nullptr &&cur->endofword==true)
        return true;
    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<string>keys(n);
    for(int i=0;i<n;++i)
        cin>>keys[i];
    Trie* root=newnode();
    for(int i=0;i<n;++i)
        insert(root,keys[i]);
    cout<<search(root, "the")<<endl;
    cout<<search(root,"these")<<endl;

}
