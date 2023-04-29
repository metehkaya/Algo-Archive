class Node {
public:
    bool mark;
    unordered_map<char,Node*> mp;
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
            if(node->mp.find(c) == node->mp.end())
                node->mp[c] = new Node();
            node = node->mp[c];
        }
        node->mark = true;
    }
    bool query(Node* node , string& s , int idx , bool used) {
        if(node->mark)
            return used;
        for(auto it : node->mp) {
            char c = it.first;
            Node* nxt_node = it.second;
            if(!used or s[idx] == c)
                if(query(nxt_node,s,idx+1,(used or s[idx] != c)))
                    return true;
        }
        return false;
    }
    bool differByOne(vector<string>& ar) {
        root = new Node();
        for(string& s : ar)
            update(s);
        for(string& s : ar)
            if(query(root,s,0,false))
                return true;
        return false;
    }
};
