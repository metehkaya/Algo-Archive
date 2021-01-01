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
    bool wordBreak(string s, vs& words) {
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
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for( int i = 0 ; i < n ; i++ )
            if(dp[i]) {
                Node* node = root;
                for( int j = i ; j < n ; j++ ) {
                    int c = s[j]-'a';
                    if(node->child[c]) {
                        node = node->child[c];
                        if(node->isWord)
                            dp[j+1] = true;
                    }
                    else
                        break;
            }
        }
        return dp[n];
    }
};