class Solution {
public:
    string kthDistinct(vector<string>& ar, int k) {
        int n = ar.size();
        map<string,int> cnt;
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]] = cnt[ar[i]]+1;
        for( int i = 0 ; i < n ; i++ )
            if(cnt[ar[i]] == 1)
                if(--k == 0)
                    return ar[i];
        return "";
    }
};
