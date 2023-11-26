class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int len = min(s1.length(),min(s2.length(),s3.length()));
        int l = 0;
        while(l < len and s1[l] == s2[l] and s1[l] == s3[l])
            l++;
        return l == 0 ? -1 : s1.length()+s2.length()+s3.length()-3*l;
    }
};

