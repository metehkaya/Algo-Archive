class Solution {
public:
    char int2char(int num) {
        if(num <= 9)
            return '0'+num;
        return 'a'+(num-10);
    }
    int char2int(char c) {
        if(c >= '0' && c <= '9')
            return c-'0';
        return 10+(c-'a');
    }
    string similarRGB(string s) {
        int r = 16*char2int(s[1]) + char2int(s[2]);
        int g = 16*char2int(s[3]) + char2int(s[4]);
        int b = 16*char2int(s[5]) + char2int(s[6]);
        string ans = "";
        int minDist = INT_MAX;
        for( int i = 0 ; i < 16 ; i++ )
            for( int j = 0 ; j < 16 ; j++ )
                for( int k = 0 ; k < 16 ; k++ ) {
                    int x = 17*i , y = 17*j , z = 17*k;
                    int dist = 0;
                    dist += (r-x)*(r-x);
                    dist += (g-y)*(g-y);
                    dist += (b-z)*(b-z);
                    if(dist < minDist) {
                        minDist = dist;
                        ans = "#";
                        ans.push_back(int2char(i));
                        ans.push_back(int2char(i));
                        ans.push_back(int2char(j));
                        ans.push_back(int2char(j));
                        ans.push_back(int2char(k));
                        ans.push_back(int2char(k));
                    }
                }
        return ans;
    }
};