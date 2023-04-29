class Solution {
public:
    bool isConsecutive(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        for( int i = 1 ; i < n ; i++ )
            if(v[i] != v[i-1]+1)
                return false;
        return true;
    }
};
