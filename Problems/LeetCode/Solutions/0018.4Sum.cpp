class Solution {
public:
    set<vector<int>> vs;
    map<int,vector<int>> mp;
    vector<vector<int>> ans;
    vector<vector<int>> fourSum(vector<int>& ar, int target) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        map<int,vector<int>>::iterator it;
        for( int i = n-2 ; i >= 0 ; i-- ) {
            mp[ar[i+1]].push_back(i+1);
            for( int j = i-1 ; j >= 0 ; j-- )
                for( int k = j-1 ; k >= 0 ; k-- ) {
                    it = mp.find(target-ar[i]-ar[j]-ar[k]);
                    if(it != mp.end()) {
                        vector<int> indices = it->second;
                        int sz = indices.size();
                        for( int s = 0 ; s < sz ; s++ ) {
                            vector<int> v(4);
                            v[0] = ar[i] , v[1] = ar[j] , v[2] = ar[k] , v[3] = ar[indices[s]];
                            if(vs.find(v) == vs.end()) {
                                vs.insert(v);
                                ans.push_back(v);
                            }
                        }
                    }
                }
        }
        return ans;
    }
};