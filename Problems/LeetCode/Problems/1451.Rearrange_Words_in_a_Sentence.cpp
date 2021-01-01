#define fi first
#define se second
typedef pair<int,int> pi;
typedef pair<pi,string> pis;

class Solution {
public:
    string makeUpper(string& str) {
        if(str[0] >= 'a' && str[0] <= 'z')
            str[0] += 'A' - 'a';
        return str;
    }
    string makeLower(string& str) {
        if(str[0] >= 'A' && str[0] <= 'Z')
            str[0] += 'a' - 'A';
        return str;
    }
    string arrangeWords(string text) {
        vector<pis> v;
        int n = text.length();
        string curr = "";
        for( int i = 0 ; i <= n ; i++ ) {
            if( i == n || text[i] == ' ' ) {
                pis d = pis( pi( curr.length() , i ) , curr );
                v.push_back(d);
                curr = "";
            }
            else
                curr.push_back( text[i] );
        }
        sort( v.begin() , v.end() );
        string ans = "";
        for( int i = 0 ; i < v.size() ; i++ ) {
            if(i)
                ans += " " + makeLower(v[i].second);
            else
                ans = makeUpper(v[i].second);
        }
        return ans;
    }
};