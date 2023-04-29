class Solution {
public:
    bool checkFile(string str) {
        int len = str.length();
        for( int i = 1 ; i < len-1 ; i++ )
            if(str[i] == '.')
                return true;
        return false;
    }
    int lengthLongestPath(string s) {
        int len = s.length();
        int index;
        for( index = 0 ; index < len ; index++ )
            if( s[index] == '\n' )
                break;
        int ans = 0;
        bool isFile = checkFile(s.substr(0,index));
        if(isFile)
            ans = index;
        if(index == len)
            return ans;
        vector<int> sum;
        sum.push_back(index);
        while(index < len) {
            int cnt = 0;
            index += 1;
            while(s[index] == '\t')
                index++,cnt++;
            sum.resize(cnt);
            int index2;
            for( index2 = index ; index2 < len ; index2++ )
                if(s[index2] == '\n')
                    break;
            string word = s.substr(index,index2-index);
            isFile = checkFile(word);
            int wordLength = index2 - index;
            if(isFile) {
                if(cnt > 0)
                    ans = max(ans, sum[cnt-1] + wordLength + cnt);
                else
                    ans = max(ans, wordLength);
            }
            else {
                if(cnt > 0)
                    sum.push_back(sum[cnt-1] + wordLength);
                else
                    sum.push_back(wordLength);
            }
            index = index2;
        }
        return ans;
    }
};