class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        string s = "" , t = "";
        int n = w1.size();
        for( int i = 0 ; i < n ; i++ )
            s += w1[i];
        n = w2.size();
        for( int i = 0 ; i < n ; i++ )
            t += w2[i];
        return s == t;
    }
};