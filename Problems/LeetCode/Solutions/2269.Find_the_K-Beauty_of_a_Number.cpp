class Solution {
public:
    int divisorSubstrings(int num, int k) {
        vector<int> v;
        int n = num;
        while(n) {
            v.push_back(n%10);
            n /= 10;
        }
        int ans = 0;
        reverse(v.begin(), v.end());
        int sz = v.size();
        for( int i = 0 ; i <= sz-k ; i++ ) {
            int val = 0;
            for( int j = i ; j < i+k ; j++ )
                val = 10*val + v[j];
            if(val > 0 && num % val == 0)
                ans++;
        }
        return ans;
    }
};
