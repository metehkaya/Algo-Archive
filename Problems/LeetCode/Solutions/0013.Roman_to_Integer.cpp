class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string,int> hashh;
        unordered_map<string,int>::iterator iter;
        int n = s.length();
        hashh.insert( make_pair("I",1) );
        hashh.insert( make_pair("V",5) );
        hashh.insert( make_pair("X",10) );
        hashh.insert( make_pair("L",50) );
        hashh.insert( make_pair("C",100) );
        hashh.insert( make_pair("D",500) );
        hashh.insert( make_pair("M",1000) );
        hashh.insert( make_pair("IV",4) );
        hashh.insert( make_pair("IX",9) );
        hashh.insert( make_pair("XL",40) );
        hashh.insert( make_pair("XC",90) );
        hashh.insert( make_pair("CD",400) );
        hashh.insert( make_pair("CM",900) );
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            bool found = false;
            if(i+1 < n) {
                string str = s.substr(i,2);
                iter = hashh.find(str);
                if(iter != hashh.end()) {
                    found = true;
                    i++;
                    ans += iter->second;
                }
            }
            if(!found) {
                string str = s.substr(i,1);
                iter = hashh.find(str);
                ans += iter->second;
            }
        }
        return ans;
    }
};