class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,int>hashh;
        unordered_map<int,int>::iterator iter;
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ ) {
            iter = hashh.find(target-arr[i]);
            if(iter != hashh.end()) {
                ans.push_back(iter->second);
                ans.push_back(i);
                break;
            }
            hashh.insert(make_pair(arr[i],i));
        }
        return ans;
    }
};