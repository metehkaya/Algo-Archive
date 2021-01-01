class Solution {
public:
    int findLHS(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        map<int,int> cnt;
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        for(auto it : cnt) {
            int x1 = it.first , x2 = it.second;
            int y1 = x1+1 , y2 = 0;
            if(cnt.find(y1) != cnt.end()) {
                y2 = cnt[y1];
                ans = max(ans,x2+y2);
            }
        }
        return ans;
    }
};