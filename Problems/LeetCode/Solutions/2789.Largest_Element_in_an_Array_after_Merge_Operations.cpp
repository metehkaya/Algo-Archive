class Solution {
public:
    long long maxArrayValue(vector<int>& v) {
        int n = v.size();
        long long ans = v[n-1];
        for( int i = n-2 ; i >= 0 ; i-- )
            if(v[i] <= ans)
                ans += v[i];
            else
                ans = v[i];
        return ans;
    }
};
