class Solution {
public:
    vector<int> findOriginalArray(vector<int>& ar) {
        int n = ar.size();
        multiset<int> myset;
        multiset<int>::iterator it;
        for( int i = 0 ; i < n ; i++ )
            myset.insert(ar[i]);
        vector<int> ans,empty;
        while(!myset.empty()) {
            it = myset.begin();
            int x = (*it);
            myset.erase(it);
            it = myset.lower_bound(2*x);
            if(it == myset.end() || (*it) != 2*x)
                return empty;
            myset.erase(it);
            ans.push_back(x);
        }
        return ans;
    }
};