class Solution {
public:
    bool isTransformable(string s, string t) {
        int n = s.length();
        queue<int> Q[10];
        vector<int> cnt(10,0);
        for( int i = 0 ; i < n ; i++ ) {
            cnt[s[i]-'0']++;
            cnt[t[i]-'0']--;
            Q[s[i]-'0'].push(i);
        }
        for( int i = 0 ; i < 10 ; i++ )
            if(cnt[i] != 0)
                return false;
        for( int i = 0 ; i < n ; i++ ) {
            int x = t[i]-'0';
            if(Q[x].empty())
                return false;
            int y = Q[x].front();
            Q[x].pop();
            for( int j = 0 ; j < x ; j++ )
                if(!Q[j].empty() && Q[j].front() < y)
                    return false;
        }
        return true;
    }
};