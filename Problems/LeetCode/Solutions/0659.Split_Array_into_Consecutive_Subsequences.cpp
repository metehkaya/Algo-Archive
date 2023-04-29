class Solution {
public:
    bool isPossible(vector<int>& ar) {
        int n = ar.size();
        map<int,priority_queue<int,vector<int>,greater<int>>> mp;
        map<int,priority_queue<int,vector<int>,greater<int>>>::iterator it;
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < n ; i++ ) {
            int x = ar[i];
            it = mp.find(x);
            if(it != mp.end() && !it->second.empty()) {
                int times = it->second.top();
                it->second.pop();
                mp[x+1].push(times+1);
            }
            else
                mp[x+1].push(1);
        }
        for( it = mp.begin() ; it != mp.end() ; it++ )
            while(!it->second.empty()) {
                int times = it->second.top();
                it->second.pop();
                if(times < 3)
                    return false;
            }
        return true;
    }
};