class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26,0);
        for(char ch : word)
            v[ch-'a']++;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int ans = 0;
        for( int i = 0 ; i < 26 ; i++ ) {
            int k = i/8+1;
            ans += k*v[i];
        }
        return ans;
    }
};
