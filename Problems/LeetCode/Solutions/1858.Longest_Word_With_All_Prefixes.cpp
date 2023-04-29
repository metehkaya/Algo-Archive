class Node {
public:
    bool mark;
    map<char,Node*> next;
    Node() {
        mark = false;
    }
};

class Solution {
public:
    Node* root;
    void update(string& s) {
        Node* node = root;
        for(char c : s) {
            if(node->next.find(c) == node->next.end())
                node->next[c] = new Node();
            node = node->next[c];
        }
        node->mark = true;
    }
    void query(Node* node , string& s , string& ans) {
        if(s.length() > ans.length())
            ans = s;
        for(auto it : node->next)
            if(it.second->mark) {
                s.push_back(it.first);
                query(it.second,s,ans);
                s.pop_back();
            }
    }
    string longestWord(vector<string>& words) {
        root = new Node();
        for(string s : words)
            update(s);
        string s = "" , ans = "";
        query(root,s,ans);
        return ans;
    }
};
