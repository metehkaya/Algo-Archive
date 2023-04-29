class Solution {
public:
    int captureForts(vector<int>& v) {
        int n = v.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if(v[i] == 1) {
                int j = i+1;
                while(j < n and v[j] == 0)
                    j++;
                if(j < n and v[j] == -1)
                    ans = max(ans,j-i-1);
                j = i-1;
                while(j >= 0 and v[j] == 0)
                    j--;
                if(j >= 0 and v[j] == -1)
                    ans = max(ans,i-j-1);
            }
        return ans;
    }
};
