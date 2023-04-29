class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        sort(basket1.begin(),basket1.end());
        sort(basket2.begin(),basket2.end());
        int mn = min(basket1[0], basket2[0]);
        map<int,int> mp;
        for( int x : basket1 )
            mp[x]++;
        for( int x : basket2 )
            mp[x]--;
        vector<int> v_less,v_greater;
        for(auto it : mp) {
            int key = it.first;
            int val = it.second;
            if(abs(val) % 2)
                return -1;
            val /= 2;
            if(val < 0) {
                val = -val;
                while(val--)
                    v_less.push_back(key);
            }
            else if(val > 0)
                while(val--)
                    v_greater.push_back(key);
        }
        long long ans = 0;
        int sz = v_less.size();
        for( int i = 0 ; i < sz ; i++ )
            ans += min(min(v_less[i],v_greater[sz-1-i]), 2*mn);
        return ans;
    }
};
