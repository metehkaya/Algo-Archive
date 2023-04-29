class Solution {
public:
    int flipLights(int n, int k) {
        set<vector<bool>> ans;
        for( int mask = 0 ; mask < 16 ; mask++ ) {
            int cnt = 0;
            vector<bool> var(n,false);
            for( int i = 0 ; i < 4 ; i++ )
                if(mask & (1<<i))
                    cnt++;
            if(cnt <= k && cnt%2 == k%2) {
                if(mask & 1)
                    for( int i = 0 ; i < n ; i++ )
                        var[i] = !var[i];
                if(mask & 2)
                    for( int i = 0 ; i < n ; i += 2 )
                        var[i] = !var[i];
                if(mask & 4)
                    for( int i = 1 ; i < n ; i += 2 )
                        var[i] = !var[i];
                if(mask & 8)
                    for( int i = 0 ; i < n ; i += 3 )
                        var[i] = !var[i];
                ans.insert(var);
            }
        }
        return ans.size();
    }
};