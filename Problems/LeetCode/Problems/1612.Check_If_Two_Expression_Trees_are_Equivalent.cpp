struct Node {
    char val;
    Node *left;
    Node *right;
    Node() : val(' '), left(nullptr), right(nullptr) {}
    Node(char x) : val(x), left(nullptr), right(nullptr) {}
    Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int cnt[26];
    void dfs(Node* node , int add) {
        if(node == NULL)
            return;
        char c = node->val;
        if(c >= 'a' && c <= 'z')
            cnt[c-'a'] += add;
        dfs(node->left,add);
        dfs(node->right,add);
    }
    bool checkEquivalence(Node* root1, Node* root2) {
        memset(cnt,0,sizeof(cnt));
        dfs(root1,+1);
        dfs(root2,-1);
        for( int i = 0 ; i < 26 ; i++ )
            if(cnt[i])
                return false;
        return true;
    }
};