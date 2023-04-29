class Solution {
public:
    int N,n;
    vector<string> ar;
    set<string> myset;
    string findDifferentBinaryString(vector<string>& nums) {
        ar = nums;
        n = ar.size();
        N = (1<<n);
        string ans = "";
        for( int i = 0 ; i < n ; i++ )
            myset.insert(ar[i]);
        for( int mask = 0 ; mask < N ; mask++ ) {
            string s = "";
            for( int i = 0 ; i < n ; i++ ) {
                int val = (1<<i);
                if(mask & val)
                    s.push_back('1');
                else
                    s.push_back('0');
            }
            if(myset.find(s) == myset.end()) {
                ans = s;
                break;
            }
        }
        return ans;
    }
};