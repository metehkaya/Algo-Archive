class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& v, int k) {
        int n = v.size();
        vector<int> non_inc(n);
        vector<int> non_dec(n);
        for( int i = 0 , j = 1 ; i < n ; i = j ) {
            j = i+1;
            while(j < n && v[j] >= v[j-1])
                j++;
            for( int k = i ; k < j ; k++ )
                non_dec[k] = j-1;
        }
        for( int i = 0 , j = 1 ; i < n ; i = j ) {
            j = i+1;
            while(j < n && v[j] <= v[j-1])
                j++;
            for( int k = i ; k < j ; k++ )
                non_inc[k] = i;
        }
        vector<int> ans;
        for( int i = k ; i < n-k ; i++ ) {
            int cond = 0;
            if(non_dec[i]-i >= k)
                cond++;
            if(i-non_inc[i] >= k)
                cond++;
            if(cond == 2)
                ans.push_back(i);
        }
        return ans;
    }
};
