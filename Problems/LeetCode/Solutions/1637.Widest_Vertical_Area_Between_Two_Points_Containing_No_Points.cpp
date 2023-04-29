class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& ar) {
        int n = ar.size();
        set<int> s;
        for( int i = 0 ; i < n ; i++ )
            s.insert(ar[i][0]);
        set<int>::iterator it1,it2;
        it1 = s.begin();
        it2 = it1;
        it2++;
        int ans = 0;
        while(it2 != s.end()) {
            ans = max(ans,(*it2)-(*it1));
            it1++;
            it2++;
        }
        return ans;
    }
};