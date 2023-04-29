class Solution {
public:
    map<int,int> cnt;
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        for( int i = 0 ; i < n ; i++ )
            cnt[nums2[i]]++;
        vector<int> ans;
        n = nums1.size();
        map<int,int>::iterator it;
        for( int i = 0 ; i < n ; i++ ) {
            int x = nums1[i];
            it = cnt.find(x);
            if(it != cnt.end()) {
                ans.push_back(x);
                if(--it->second == 0)
                    cnt.erase(it);
            }
        }
        return ans;
    }
};