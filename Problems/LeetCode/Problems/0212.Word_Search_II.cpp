class Solution {
public:
    const int DIR[4][2] = {{+1,0},{-1,0},{0,+1},{0,-1}};
    struct Node {
        Node* next[26];
        bool isWord;
        bool found;
        Node() {
            isWord = found = false;
            memset(next, 0, sizeof(next));
        }
    };
    void initTree(Node* node, string& word, int index) {
        if(index == word.length()) {
            node->isWord = true;
            return;
        }
        int c = word[index]-'a';
        if(node->next[c] == NULL)
            node->next[c] = new Node();
        initTree(node->next[c],word,index+1);
    }
    void dfs(Node* node, int r, int c, vector<vector<char>>& board, vector<string>& ans, vector<vector<bool>>& mark, string& curr) {
        if(node->isWord && !node->found) {
            ans.push_back(curr);
            node->found = true;
        }
        for( int i = 0 ; i < 4 ; i++ ) {
            int r2 = r + DIR[i][0];
            int c2 = c + DIR[i][1];
            if(r2 < 0 || r2 >= board.size() || c2 < 0 || c2 >= board[0].size())
                continue;
            int cc = board[r2][c2] - 'a';
            if(mark[r2][c2] || node->next[cc] == NULL)
                continue;
            mark[r2][c2] = true;
            curr.push_back((char)('a'+cc));
            dfs(node->next[cc],r2,c2,board,ans,mark,curr);
            curr.pop_back();
            mark[r2][c2] = false;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        Node* root = new Node();
        for( int i = 0 ; i < words.size() ; i++ )
            initTree(root, words[i], 0);
        vector<string> ans;
        string curr = "";
        vector<vector<bool>> mark(n, vector<bool>(m,0));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ) {
                int c = board[i][j] - 'a';
                if(root->next[c] != NULL) {
                    mark[i][j] = true;
                    curr.push_back((char)('a'+c));
                    dfs(root->next[c],i,j,board,ans,mark,curr);
                    curr.pop_back();
                    mark[i][j] = false;
                }
            }
        return ans;
    }
};