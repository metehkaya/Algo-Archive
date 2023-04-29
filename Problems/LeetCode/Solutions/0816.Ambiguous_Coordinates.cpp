class Solution {
public:
    bool isValid(string str, int dec) {
        if(dec && str[str.size()-1] == '0')
            return false;
        if(str.size() != 1 && dec != 1 && str[0] == '0')
            return false;
        return true;
    }
    vector<string> ambiguousCoordinates(string s) {
    vector<string> ans;
    for( int i = 2 ; i < s.size()-1 ; i++ ) {
        string xStr = s.substr(1,i-1);
        string yStr = s.substr(i,s.size()-1-i);
        vector<string> xPoss;
        for( int j = 0 ; j < xStr.size() ; j++ )
            if(isValid(xStr,j))
                xPoss.push_back(xStr.substr(0,j) + (j ? "." : "") + xStr.substr(j));
        for(int j = 0; j < yStr.size(); j++)
            if(isValid(yStr, j)) {
                string y = yStr.substr(0,j) + (j ? "." : "") + yStr.substr(j);
                for(auto x : xPoss)
                    ans.push_back("(" + x + ", " + y + ")");
            }
        }
        return ans;
    }
};