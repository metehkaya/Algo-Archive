class Solution {
public:
    int expressiveWords(string s, vector<string>& t) {
        int n = t.size();
        int m = s.length();
        vector<pair<char,int>> cntS;
        vector<vector<pair<char,int>>> cntT;
        for( int i = 0 ; i < m ; i++ ) {
            if(i == 0 || s[i] != s[i-1])
                cntS.push_back( make_pair(s[i],1) );
            else
                cntS[cntS.size()-1].second++;
        }
        for( int w = 0 ; w < n ; w++ ) {
            int len = t[w].length();
            vector<pair<char,int>> cnt;
            for( int i = 0 ; i < len ; i++ ) {
                if(i == 0 || t[w][i] != t[w][i-1])
                    cnt.push_back( make_pair(t[w][i],1) );
                else
                    cnt[cnt.size()-1].second++;
            }
            cntT.push_back(cnt);
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(cntS.size() != cntT[i].size())
                continue;
            bool add = true;
            int sz = cntS.size();
            for( int j = 0 ; j < sz && add ; j++ )
                if( cntS[j].first != cntT[i][j].first || cntS[j].second < cntT[i][j].second || ( cntS[j].second == 2 && cntT[i][j].second == 1 ) )
                    add = false;
            ans += add;
        }
        return ans;
    }
};