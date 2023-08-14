class Solution {
public:
    int countCompleteSubarrays(vector<int>& v) {
        set<int> s(v.begin(), v.end());
        int n = v.size() , k = s.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            s.clear();
            int j = i;
            while(j < n and (int)s.size() < k)
                s.insert(v[j++]);
            if(s.size() == k)
                ans += n-j+1;
        }
        return ans;
    }
};
