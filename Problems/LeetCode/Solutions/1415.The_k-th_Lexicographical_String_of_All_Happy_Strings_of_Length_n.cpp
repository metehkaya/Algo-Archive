class Solution {
public:
    string getHappyString(int n, int k) {
        int mx = 3;
        for( int i = 1 ; i < n ; i++ )
            mx *= 2;
        if(mx < k)
            return "";
        string str = "a";
        while(k > mx/3) {
            str[0]++;
            k -= mx/3;
        }
        k--;
        for( int i = 1 ; i < n ; i++ ) {
            vector<char> v;
            for( int j = 0 ; j < 3 ; j++ ) {
                char c = 'a' + j;
                if(c != str[i-1])
                    v.push_back(c);
            }
            if( k & (1 << (n-i-1)) )
                str.push_back(v[1]);
            else
                str.push_back(v[0]);
        }
        return str;
    }
};