class Solution {
public:
    int maxRepOpt1(string str) {
        int n = str.length() , ans = 0;
        vector<int> s,e;
        vector<int> cnt(26,0);
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && str[i] == str[j])
                j++;
            s.push_back(i);
            e.push_back(j-1);
            int c = str[i]-'a';
            cnt[c] += j-i;
            ans = max(ans,j-i);
        }
        n = s.size();
        for( int k = 0 ; k < n ; k++ ) {
            int i = s[k] , j = e[k];
            int c = str[i] - 'a';
            int len = j-i+1;
            if(len < cnt[c])
                ans = max(ans,len+1);
            if(i == j && k > 0 && k < n-1 && str[i-1] == str[j+1]) {
                int c2 = str[i-1]-'a';
                int len2 = e[k-1]-s[k-1]+1 + e[k+1]-s[k+1]+1;
                if(len2 < cnt[c2])
                    ans = max(ans,len2+1);
                else
                    ans = max(ans,len2);
            }
        }
        return ans;
    }
};