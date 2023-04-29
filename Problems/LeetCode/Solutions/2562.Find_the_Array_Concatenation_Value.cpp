class Solution {
public:
    long long findTheArrayConcVal(vector<int>& v) {
        long long ans = 0;
        int n = v.size();
        for( int i = 0 , j = n-1 ; i <= j ; i++ , j-- ) {
            if(i == j)
                ans += v[i];
            else {
                string s = to_string(v[i]);
                string t = to_string(v[j]);
                ans += stoi(s+t);
            }
        }
        return ans;
    }
};
