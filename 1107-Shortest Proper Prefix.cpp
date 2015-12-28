#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

struct Node{
    char in; // 进入当前节点的字符
    bool word; // 是否是query中的字符
    int count; // prefix数量
    vector<Node*> kids; // 子节点
};

// 向curr的子节点添加字符word[pos]
void trie_add(Node* curr, string& word, int pos){
    if(pos >= word.size()){
        curr->word = true;
        return ;
    }
    
    bool flag = true;
    for(auto p : curr->kids){
        if(p->in == word[pos]){
            flag = false;
            p->count += 1;
            trie_add(p, word, pos+1);
        }
    }
    
    if(flag){
        // add new kid
        Node* p = new Node;
        p->in = word[pos];
        p->word = false;
        p->count = 1;
        curr->kids.push_back(p);
        trie_add(p, word, pos+1);
    }
}

vector<string> result;
void find(Node* curr, string prefix){ // count: 当前的prefix数量
    if(curr->count <= 5){
        result.push_back(prefix);
        return ;
    }
    
    for(auto p : curr->kids){
        find(p, prefix + p->in);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    
    Node* root = new Node;
    root->in = '\0';
    root->word = false;
    root->count = 0;
    
    string query;
    while(N--){
        cin >> query;
        root->count += 1;
        trie_add(root, query, 0);
    }
    
    find(root, "");
    
    cout << result.size() << endl;
    /*
    cout << "Num. of shortest prefix: " << result.size() << endl;
    for(string s : result){
        cout << s << endl;
    }
    */
    
    return 0;
}
