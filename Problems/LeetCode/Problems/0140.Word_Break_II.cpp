typedef vector<int> vi;
typedef vector<string> vs;

class Node {
public:
    bool isWord;
    vector<Node*> child;
    Node() {
        isWord = false;
        child.resize(26,NULL);
    }
}*root;

class Solution {
public:
    void solve(int i , int n , string& s , vi& last , string& word , vs& ans) {
        if(i == n) {
            ans.push_back(word);
            return;
        }
        Node* node = root;
        for( int j = i ; j <= last[i] ; j++ ) {
            int c = s[j]-'a';
            node = node->child[c];
            word.push_back(s[j]);
            if(node->isWord) {
                if(j == n-1)
                    solve(j+1,n,s,last,word,ans);
                else if(last[j+1] != -1) {
                    word.push_back(' ');
                    solve(j+1,n,s,last,word,ans);
                    word.pop_back();
                }
            }
        }
        for( int j = i ; j <= last[i] ; j++ )
            word.pop_back();
    }
    vs wordBreak(string s, vs& words) {
        root = new Node();
        int n = words.size();
        for( int i = 0 ; i < n ; i++ ) {
            Node* node = root;
            int len = words[i].length();
            for( int j = 0 ; j < len ; j++ ) {
                int c = words[i][j] - 'a';
                if(node->child[c] == NULL)
                    node->child[c] = new Node();
                node = node->child[c];
            }
            node->isWord = true;
        }
        n = s.length();
        vi last(n+1,-1);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            Node* node = root;
            for( int j = i ; j < n ; j++ ) {
                int c = s[j]-'a';
                if(node->child[c]) {
                    node = node->child[c];
                    if(node->isWord)
                        if(j == n-1 or last[j+1] != -1)
                            last[i] = j;
                }
                else
                    break;
            }
        }
        vs ans;
        string word = "";
        if(last[0] != -1)
            solve(0,n,s,last,word,ans);
        return ans;
    }
};