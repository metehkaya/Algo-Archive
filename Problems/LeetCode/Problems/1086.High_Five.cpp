class Solution {
public:
    const int MAX_ID = 1001;
    vector<vector<int>> highFive(vector<vector<int>>& ar) {
        vector<vector<int>> scores(MAX_ID);
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            scores[ar[i][0]].push_back(ar[i][1]);
        vector<vector<int>> ans;
        for( int i = 1 ; i < MAX_ID ; i++ )
            if(!scores[i].empty()) {
                sort(scores[i].begin() , scores[i].end());
                int sz = scores[i].size();
                int sum = 0;
                for( int j = sz-5 ; j < sz ; j++ )
                    sum += scores[i][j];
                vector<int> v(2);
                v[0] = i;
                v[1] = sum/5;
                ans.push_back(v);
            }
        return ans;
    }
};