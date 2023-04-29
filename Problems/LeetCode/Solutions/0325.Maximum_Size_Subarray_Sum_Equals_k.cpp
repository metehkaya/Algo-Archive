class Solution {
public:
    int maxSubArrayLen(vector<int>& ar, int k) {
        unordered_map<int,int> hashh;
        unordered_map<int,int>::iterator iter;
        int n = ar.size();
        int sum = 0 , ans = 0;
        hashh.insert( make_pair(0,0) );
        for( int i = 0 ; i < n ; i++ ) {
            sum += ar[i];
            iter = hashh.find(sum-k);
            if(iter != hashh.end())
                ans = max(ans, i+1 - iter->second);
            iter = hashh.find(sum);
            if(iter == hashh.end())
                hashh.insert( make_pair(sum,i+1) );
        }
        return ans;
    }
};