class Solution {
public:
    int maximizeGreatness(vector<int>& v) {
        int n = v.size() , ans = 0;
        sort(v.begin(),v.end());
        for( int i = 0 , j = 0 ; i < n and j < n ; i++ ) {
            while(j < n and v[j] <= v[i])
                j++;
            if(j < n)
                j++ , ans++;
        }
        return ans;
    }
};
