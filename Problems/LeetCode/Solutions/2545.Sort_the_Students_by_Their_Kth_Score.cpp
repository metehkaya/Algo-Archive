class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        vector<vector<int>> v,ans;
        for( int i = 0 ; i < n ; i++ )
            v.push_back({-score[i][k],i});
        sort(v.begin(),v.end());
        for( int i = 0 ; i < n ; i++ )
            ans.push_back(score[v[i][1]]);
        return ans;
    }
};
