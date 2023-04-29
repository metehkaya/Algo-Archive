class Solution {
public:
    static const int maxn = 1000;
    bool mark[maxn];
    set<int> todo[maxn];
    set<int> done[maxn];
    vector<int> movesToStamp(string t, string s) {
        int n = s.length();
        int m = t.length();
        queue<int> Q;
        vector<int> ans;
        for( int i = 0 ; i <= n-m ; i++ ) {
            for( int j = 0 ; j < m ; j++ )
                if(t[j] == s[i+j])
                    done[i].insert(i+j);
                else
                    todo[i].insert(i+j);
            if(todo[i].empty()) {
                ans.push_back(i);
                for( int j = i ; j < i+m ; j++ )
                    if(!mark[j]) {
                        mark[j] = true;
                        Q.push(j);
                    }
            }
        }
        while(!Q.empty()) {
            int i = Q.front();
            Q.pop();
            for( int j = max(i-m+1,0) ; j <= min(n-m,i) ; j++ )
                if(todo[j].find(i) != todo[j].end()) {
                    todo[j].erase(i);
                    if(todo[j].empty()) {
                        ans.push_back(j);
                        for(int idx : done[j])
                            if(!mark[idx]) {
                                mark[idx] = true;
                                Q.push(idx);
                            }
                    }
                }
        }
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i]) {
                ans.clear();
                return ans;
            }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};