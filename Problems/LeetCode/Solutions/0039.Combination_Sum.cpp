class Solution {
public:
    void add(int value, int prevNumber, vector<vector<int>>& ans, vector<int>& v, vector<vector<int>>& prev) {
        if(value == 0) {
            ans.push_back(v);
            return;
        }
        for( int i = 0 ; i < prev[value].size() ; i++ )
            if( prev[value][i] <= prevNumber ) {
                int x = prev[value][i];
                v.push_back(x);
                add(value-x,x,ans,v,prev);
                v.pop_back();
            }
    }
    vector<vector<int>> combinationSum(vector<int>& ar, int target) {
        vector<vector<int>> prev(target+1);
        sort(ar.begin(), ar.end());
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j <= target-ar[i] ; j++ )
                if( j == 0 || !prev[j].empty() )
                    prev[j+ar[i]].push_back(ar[i]);
        vector<vector<int>> ans;
        vector<int> v;
        add(target,target+1,ans,v,prev);
        return ans;
    }
};