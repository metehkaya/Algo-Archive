typedef long long LL;

class Solution {
public:
    const int mod = (int) 1e9+7;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        map<int,LL> mpbuy,mpsell;
        map<int,LL>::iterator it;
        int n = orders.size();
        for( int i = 0 ; i < n ; i++ ) {
            if(orders[i][2] == 0) {
                mpbuy[orders[i][0]] += orders[i][1];
                while(!mpsell.empty()) {
                    it = mpsell.begin();
                    if((*it).first <= orders[i][0]) {
                        int psell = (*it).first;
                        LL asell = (*it).second;
                        int pbuy = orders[i][0];
                        LL abuy = mpbuy[pbuy];
                        mpbuy.erase(pbuy);
                        mpsell.erase(psell);
                        LL mn = min(asell,abuy);
                        asell -= mn;
                        abuy -= mn;
                        if(asell)
                            mpsell[psell] = asell;
                        if(abuy)
                            mpbuy[pbuy] = abuy;
                        else
                            break;
                    }
                    else
                        break;
                }
            }
            else {
                mpsell[orders[i][0]] += orders[i][1];
                while(!mpbuy.empty()) {
                    it = mpbuy.end();
                    it--;
                    if((*it).first >= orders[i][0]) {
                        int pbuy = (*it).first;
                        LL abuy = (*it).second;
                        int psell = orders[i][0];
                        LL asell = mpsell[psell];
                        mpbuy.erase(pbuy);
                        mpsell.erase(psell);
                        LL mn = min(asell,abuy);
                        asell -= mn;
                        abuy -= mn;
                        if(abuy)
                            mpbuy[pbuy] = abuy;
                        if(asell)
                            mpsell[psell] = asell;
                        else
                            break;
                    }
                    else
                        break;
                }
            }
        }
        LL ans = 0;
        for(auto it : mpbuy)
            ans += it.second;
        for(auto it : mpsell)
            ans += it.second;
        return ans%mod;
    }
};