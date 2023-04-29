class Node {
public:
    int last_idx,cnt;
    map<char,Node*> next;
    Node() {
        last_idx = -1;
        cnt = 0;
    }
};

class Solution {
public:
    Node* root;
    void update(string& s , int idx) {
        Node* node = root;
        for(char c : s) {
            if(node->next.find(c) == node->next.end())
                node->next[c] = new Node();
            node = node->next[c];
        }
        node->cnt += (idx != node->last_idx);
        node->last_idx = idx;
    }
    int query(string& s) {
        Node* node = root;
        for(char c : s) {
            if(node->next.find(c) == node->next.end())
                return 0;
            node = node->next[c];
        }
        return node->cnt;
    }
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        root = new Node();
        for( int i = 0 ; i < responses.size() ; i++ ) {
            string response = responses[i];
            response.push_back(' ');
            string s = "";
            for(char c : response) {
                if(c == ' ') {
                    update(s,i);
                    s = "";
                }
                else
                    s.push_back(c);
            }
        }
        vector<vector<int>> v;
        for( int i = 0 ; i < features.size() ; i++ )
            v.push_back({-query(features[i]),i});
        sort(v.begin(),v.end());
        vector<string> ans;
        for(auto item : v)
            ans.push_back(features[item[1]]);
        return ans;
    }
};
