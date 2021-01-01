class Solution {
public:
    void sortColors(vector<int>& ar) {
        int cnt[3] = {0};
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        for( int i = 0 , index = 0 ; i < 3 ; i++ ) {
            for( int j = 0 ; j < cnt[i] ; j++ )
                ar[index+j] = i;
            index += cnt[i];
        }
    }
};