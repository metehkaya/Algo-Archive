class Solution {
public:
    unordered_map<string,int> hashh;
    unordered_map<string,int>::iterator mit;
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if(n == 1)
            return s1[0] == s2[0];
        string sAll = s1+s2;
        mit = hashh.find(sAll);
        if(mit != hashh.end())
            return (*mit).second;
        bool fine = false;
        for( int k = 1 ; k < n ; k++ ) {
            if(isScramble(s1.substr(0,k) , s2.substr(0,k)) && isScramble(s1.substr(k,n-k) , s2.substr(k,n-k))) {
                fine = true;
                break;
            }
            if(isScramble(s1.substr(0,k) , s2.substr(n-k,k)) && isScramble(s1.substr(k,n-k) , s2.substr(0,n-k))) {
                fine = true;
                break;
            }
        }
        return hashh[sAll] = fine;
    }
};
