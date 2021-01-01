class Solution {
public:
    bool canBeEqual(vector<int>& a, vector<int>& b) {
        int n = a.size();
        map<int,int> hashh;
        for( int i = 0 ; i < n ; i++ )
            hashh[a[i]]++;
        for( int i = 0 ; i < n ; i++ ) {
            int val = b[i];
            if(hashh[val] == 0)
                return false;
            hashh[val]--;
        }
        return true;
    }
};