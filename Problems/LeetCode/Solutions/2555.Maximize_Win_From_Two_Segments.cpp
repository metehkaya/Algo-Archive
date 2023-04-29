class Solution {
public:
    int maximizeWin(vector<int>& v , int k) {
        int n = v.size() , ans = 0;
        vector<int> to;
        multiset<int> s;
        for( int l = 0 , r = 1 ; l < n ; l++ ) {
            while(r < n and v[r]-v[l] <= k)
                r++;
            ans = max(ans,r-l);
            to.push_back(r-l);
            s.insert(r-l);
        }
        for( int r = 0 , l = 0 ; r < n ; r++ ) {
            auto it = s.find(to[r]);
            s.erase(it);
            while(v[r]-v[l] > k)
                l++;
            int sum = r-l+1;
            if(!s.empty()) {
                it = s.end();
                it--;
                sum += (*it);
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};
