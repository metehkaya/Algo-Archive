class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        unordered_set<int> numSet;
        unordered_map<int,int> leftMost;
        unordered_map<int,int> rightMost;
        unordered_map<int,int>::iterator iter;
        for( int i = 0 ; i < n ; i++ ) {
            int val = arr[i];
            if(numSet.find(val) != numSet.end())
                continue;
            numSet.insert(val);
            int left,right;
            iter = rightMost.find(val+1);
            if(iter == rightMost.end())
                right = val;
            else
                right = iter->second;
            iter = leftMost.find(val-1);
            if(iter == leftMost.end())
                left = val;
            else
                left = iter->second;
            ans = max(ans, right-left+1);
            rightMost[left] = right;
            leftMost[right] = left;
        }
        return ans;
    }
};