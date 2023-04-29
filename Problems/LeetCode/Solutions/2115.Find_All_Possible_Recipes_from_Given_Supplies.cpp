class Solution {
public:
    int n;
    vector<string> words;
    map<string,int> hashh;
    void addHash(string& s) {
        map<string,int>::iterator it = hashh.find(s);
        if(it == hashh.end()) {
            hashh[s] = n++;
            words.push_back(s);
        }
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        for( int i = 0 ; i < recipes.size() ; i++ )
            addHash(recipes[i]);
        for( int i = 0 ; i < supplies.size() ; i++ )
            addHash(supplies[i]);
        for( int i = 0 ; i < ingredients.size() ; i++ )
            for( int j = 0 ; j < ingredients[i].size() ; j++ )
                addHash(ingredients[i][j]);
        vector<int> adj[n];
        vector<int> cnt(n,0);
        vector<bool> mark(n,false);
        vector<string> ans;
        set<int> recipeIndices;
        for( int i = 0 ; i < recipes.size() ; i++ )
            recipeIndices.insert(hashh[recipes[i]]);
        for( int i = 0 ; i < ingredients.size() ; i++ )
            for( int j = 0 ; j < ingredients[i].size() ; j++ ) {
                cnt[hashh[recipes[i]]]++;
                adj[hashh[ingredients[i][j]]].push_back(hashh[recipes[i]]);
            }
        queue<int> q;
        for( int i = 0 ; i < supplies.size() ; i++ ) {
            q.push(hashh[supplies[i]]);
            mark[hashh[supplies[i]]] = true;
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(recipeIndices.count(u))
                ans.push_back(words[u]);
            int deg = adj[u].size();
            for( int i = 0 ; i < deg ; i++ ) {
                int v = adj[u][i];
                if(--cnt[v] == 0 && !mark[v]) {
                    mark[v] = true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
