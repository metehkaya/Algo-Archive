class Solution {
public:
    static const int maxn = 100003;
    bool forb[maxn];
    bool check(string& s , string& t) {
        int n = s.length();
        int m = t.length();
        for( int i = 0 , id = 0 ; i < m ; i++ , id++ ) {
            while(id < n && (s[id] != t[i] || forb[id]))
                id++;
            if(id == n)
                return false;
        }
        return true;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int ans = 0;
        int left = 1;
        int right = removable.size();
        while(left <= right) {
            int mid = (left+right)>>1;
            memset(forb,false,sizeof(forb));
            for( int i = 0 ; i < mid ; i++ )
                forb[removable[i]] = true;
            if(check(s,p))
                ans = mid , left = mid+1;
            else
                right = mid-1;
        }
        return ans;
    }
};