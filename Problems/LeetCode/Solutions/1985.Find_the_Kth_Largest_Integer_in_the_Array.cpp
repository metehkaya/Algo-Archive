class Solution {
public:
    string kthLargestNumber(vector<string>& ar, int k) {
        int n = ar.size();
        sort(ar.begin() , ar.end() , [&](string& a , string& b) {
            int len1 = a.length();
            int len2 = b.length();
            if(len1 != len2)
                return len1 < len2;
            return a < b;
        });
        return ar[n-k];
    }
};