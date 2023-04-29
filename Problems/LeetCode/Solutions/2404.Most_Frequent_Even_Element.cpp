class Solution {
public:
    int mostFrequentEven(vector<int>& v) {
        int n = v.size() , ans = -1 , freq = 0;
        sort(v.begin(),v.end());
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && v[i] == v[j])
                j++;
            if(v[i]%2 == 0 && j-i > freq) {
                ans = v[i];
                freq = j-i;
            }
        }
        return ans;
    }
};
