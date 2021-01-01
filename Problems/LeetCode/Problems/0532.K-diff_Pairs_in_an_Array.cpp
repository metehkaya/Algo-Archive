class Solution {
public:
    int findPairs(vector<int>& ar, int k) {
        int n = ar.size() , ans = 0;
        set<int> nums,add;
        set<int>::iterator it;
        for( int i = 0 ; i < n ; i++ ) {
            it = nums.find(ar[i]-k);
            if(it != nums.end()) {
                it = add.find(ar[i]-k);
                if(it == add.end()) {
                    ans++;
                    add.insert(ar[i]-k);
                }
            }
            if(k > 0) {
                it = nums.find(ar[i]+k);
                if(it != nums.end()) {
                    it = add.find(ar[i]);
                    if(it == add.end()) {
                        ans++;
                        add.insert(ar[i]);
                    }
                }
            }
            nums.insert(ar[i]);
        }
        return ans;
    }
};