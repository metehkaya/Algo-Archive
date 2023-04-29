class Solution {
public:
    int kEmptySlots(vector<int>& arr, int k) {
        int n = arr.size();
        set<int> myset;
        set<int>::iterator it;
        for( int i = 0 ; i < n ; i++ ) {
            int val = arr[i];
            myset.insert(val);
            it = myset.upper_bound(val);
            if(it != myset.end()) {
                int nxt = (*it);
                if(nxt-val == k+1)
                    return i+1;
            }
            it = myset.lower_bound(val);
            if(it != myset.begin()) {
                it--;
                int prv = (*it);
                if(val-prv == k+1)
                    return i+1;
            }
        }
        return -1;
    }
};