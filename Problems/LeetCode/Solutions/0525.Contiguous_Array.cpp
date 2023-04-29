class Solution {
public:
    int findMaxLength(vector<int>& ar) {
        unordered_map<int,int> hashh;
        unordered_map<int,int>::iterator mit;
        int n = ar.size() , ans = 0 , sum = 0;
        hashh[0] = 0;
        for( int i = 1 ; i <= n ; i++ ) {
            if(ar[i-1] == 0)
                sum--;
            else
                sum++;
            mit = hashh.find(sum);
            if(mit == hashh.end())
                hashh[sum] = i;
            else
                ans = max( ans , i - (*mit).second );
        }
        return ans;
    }
};