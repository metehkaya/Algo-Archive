class Solution {
public:
    int getGroupID(string& word, map<string,int>& wordID, vector<string>& words, int& n) {
        map<string,int>::iterator it = wordID.find(word);
        if(it == wordID.end()) {
            wordID[word] = n++;
            words.push_back(word);
        }
        return wordID[word];
    }
    void dfs(int u, int g, vector<vector<int>>& adj, vector<int>& groupID) {
        groupID[u] = g;
        for( int i = 0 ; i < adj[u].size() ; i++ ) {
            int v = adj[u][i];
            if(groupID[v] == -1)
                dfs(v,g,adj,groupID);
        }
    }
    void f(int index, int last, vector<string>& input, map<string,int>& wordID, vector<int>& groupID, vector<vector<string>>& groupWords, string& curr, vector<string>& ans) {
        if(index == last) {
            ans.push_back(curr);
            return;
        }
        string word = input[index];
        map<string,int>::iterator it = wordID.find(word);
        if(it == wordID.end()) {
            string add = (index == 0) ? "" : " ";
            add += word;
            int len = add.length();
            curr += add;
            f(index+1,last,input,wordID,groupID,groupWords,curr,ans);
            for( int i = 0 ; i < add.length() ; i++ )
                curr.pop_back();
        }
        else {
            int g = groupID[it->second];
            for( int w = 0 ; w < groupWords[g].size() ; w++ ) {
                string add = (index == 0) ? "" : " ";
                word = groupWords[g][w];
                add += word;
                int len = add.length();
                curr += add;
                f(index+1,last,input,wordID,groupID,groupWords,curr,ans);
                for( int i = 0 ; i < add.length() ; i++ )
                    curr.pop_back();
            }
        }
    }
    vector<string> generateSentences(vector<vector<string>>& ar, string text) {
        int n = 0 , g = 0;
        vector<string> words;
        map<string,int> wordID;
        vector<vector<int>> adj;
        for( int i = 0 ; i < ar.size() ; i++ ) {
            int w1 = getGroupID(ar[i][0],wordID,words,n);
            int w2 = getGroupID(ar[i][1],wordID,words,n);
            adj.resize(n);
            adj[w1].push_back(w2);
            adj[w2].push_back(w1);
        }
        vector<int> groupID(n,-1);
        for( int i = 0 ; i < n ; i++ )
            if(groupID[i] == -1) {
                dfs(i,g,adj,groupID);
                g++;
            }
        vector<vector<string>> groupWords(g);
        for( int i = 0 ; i < n ; i++ )
            groupWords[groupID[i]].push_back(words[i]);
        for( int i = 0 ; i < g ; i++ )
            sort( groupWords[i].begin() , groupWords[i].end() );
        vector<string> input;
        string curr = "";
        for( int i = 0 ; i < text.length() ; i++ ) {
            if(text[i] == ' ') {
                input.push_back(curr);
                curr = "";
            }
            else {
                curr.push_back(text[i]);
                if(i == text.length() - 1)
                    input.push_back(curr);
            }
        }
        vector<string> ans;
        string currWord = "";
        f(0,input.size(),input,wordID,groupID,groupWords,currWord,ans);
        return ans;
    }
};