class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0 , n = garbage.size();
        string key = "MPG";
        for( int t = 0 ; t < 3 ; t++ ) {
            int last = -1;
            for( int i = 0 ; i < n ; i++ ) {
                string s = garbage[i];
                int len = s.length() , cnt = 0;
                for( int j = 0 ; j < len ; j++ )
                    if(s[j] == key[t])
                        cnt++;
                ans += cnt;
                if(cnt)
                    last = i;
            }
            for( int i = 0 ; i < last ; i++ )
                ans += travel[i];
        }
        return ans;
    }
};
