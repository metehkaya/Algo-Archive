class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ar) {
        vector<int> v,ans;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            if(ar[i] > 0)
                v.push_back(ar[i]);
            else {
                int val = -ar[i];
                while(!v.empty() && v.back() < val)
                    v.pop_back();
                if(v.empty())
                    ans.push_back(ar[i]);
                else if(v.back() == val)
                    v.pop_back();
            }
        }
        for( int i = 0 ; i < v.size() ; i++ )
            ans.push_back(v[i]);
        return ans;
    }
};