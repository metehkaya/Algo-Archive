class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& ar, int m) {
        map<int,int> cnt;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        vector<int> v;
        for( auto it = cnt.begin() ; it != cnt.end() ; it++ )
            v.push_back(it->second);
        sort(v.begin() , v.end());
        int k = v.size();
        int index = 0 , total = 0;
        while(index < k && total + v[index] <= m)
            total += v[index++];
        return k-index;
    }
};