class TrieNode {
public:
    int cnt;
    unordered_map<char,TrieNode*> mp;
    TrieNode() { cnt = 0; }
};

class Solution {
public:
    vector<string> ans;
    map<string,int> str_2_idx;
    void update(TrieNode* node , string& s , int stop , int idx) {
        node->cnt++;
        if(idx == stop)
            return;
        char c = s[idx];
        auto& mp = node->mp;
        if(mp.find(c) == mp.end())
            mp[c] = new TrieNode();
        update(node->mp[c],s,stop,idx+1);
    }
    void query(TrieNode* node , string& s , int idx , int stop , char last) {
        if(idx > 0 and node->cnt == 1) {
            int rem = stop-idx;
            TrieNode* curr = node;
            string t = s , res;
            for( int i = idx ; i < stop ; i++ ) {
                auto p = curr->mp.begin();
                char c = p->first;
                t.push_back(c);
                TrieNode* nxt = p->second;
                curr = nxt;
            }
            t.push_back(last);
            if(rem <= 1)
                res = t;
            else
                res = s + to_string(rem) + last;
            ans[str_2_idx[t]] = res;
            return;
        }
        auto& mp = node->mp;
        for(auto p : mp) {
            char c = p.first;
            TrieNode* nxt = p.second;
            s.push_back(c);
            query(nxt,s,idx+1,stop,last);
            s.pop_back();
        }
    }
    vector<string> wordsAbbreviation(vector<string>& words) {
        int n = words.size();
        ans.resize(n);
        map<pair<int,char>,TrieNode*> roots;
        for( int i = 0 ; i < n ; i++ ) {
            int len = words[i].length();
            if(len <= 3)
                ans[i] = words[i];
            else {
                str_2_idx[words[i]] = i;
                auto p = make_pair(len,words[i][len-1]);
                auto it = roots.find(p);
                TrieNode* root;
                if(it == roots.end()) {
                    root = new TrieNode();
                    roots[p] = root;
                }
                else
                    root = it->second;
                update(root,words[i],len-1,0);
            }
        }
        for(auto& p : roots) {
            pair<int,char> key = p.first;
            TrieNode* root = p.second;
            string s = "";
            query(root,s,0,key.first-1,key.second);
        }
        return ans;
    }
};
