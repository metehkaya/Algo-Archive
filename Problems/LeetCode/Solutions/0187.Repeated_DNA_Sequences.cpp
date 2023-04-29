class Solution {
public:
    const string ACGT = "ACGT";
    int char2int(char c) {
        for( int i = 0 ; i < 4 ; i++ )
            if(ACGT[i] == c)
                return i;
        return -1;
    }
    char int2char(int num) {
        return ACGT[num];
    }
    vector<string> findRepeatedDnaSequences(string s) {
        map<int,int> cnt;
        int n = s.length();
        for( int i = 0 ; i <= n-10 ; i++ ) {
            int val = 0;
            for( int j = i ; j < i+10 ; j++ )
                val = 4*val + char2int(s[j]);
            cnt[val]++;
        }
        vector<string> ans;
        map<int,int>::iterator iter;
        for( iter = cnt.begin() ; iter != cnt.end() ; iter++ )
            if(iter->second > 1) {
                string s = "";
                int val = iter->first;
                for( int i = 0 ; i < 10 ; i++ ) {
                    s.push_back(int2char(val%4));
                    val /= 4;
                }
                reverse(s.begin(),s.end());
                ans.push_back(s);
            }
        return ans;
    }
};