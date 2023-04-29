class Solution {
public:
    void calcVer(string& s, vector<string>& ver) {
        string curr = "";
        for( int i = 0 ; i < s.length() ; i++ ) {
            if(s[i] == '.') {
                if(curr != "") {
                    ver.push_back(curr);
                    curr = "";
                }
            }
            else
                curr.push_back(s[i]);
        }
        if(curr != "")
            ver.push_back(curr);
    }
    int compStrs(string& s1, string& t1) {
        string s2="",t2="";
        for( int i = s1.length() ; i < t1.length() ; i++ )
            s2.push_back('0');
        for( int i = t1.length() ; i < s1.length() ; i++ )
            t2.push_back('0');
        s2 = s2 + s1;
        t2 = t2 + t1;
        if(s2 < t2)
            return -1;
        else if(s2 > t2)
            return +1;
        return 0;
    }
    int compareVersion(string ver1, string ver2) {
        vector<string>v1,v2;
        calcVer(ver1,v1);
        calcVer(ver2,v2);
        for( int i = v1.size() ; i < v2.size() ; i++ )
            v1.push_back("0");
        for( int i = v2.size() ; i < v1.size() ; i++ )
            v2.push_back("0");
        for( int i = 0 ; i < v1.size() ; i++ ) {
            int val = compStrs(v1[i], v2[i]);
            if(val != 0)
                return val;
        }
        return 0;
    }
};