typedef pair<int,int> pi;

class Solution {
public:
    bool canCross(vector<int>& ar) {
        queue<pi> Q;
        map<int,int> mp;
        map<int,int>::iterator it;
        int n = ar.size();
        bool mark[n+1][n+1];
        memset(mark,false,sizeof(mark));
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < n ; i++ )
            mp[ar[i]] = i;
        mark[0][0] = true;
        Q.push(pi(0,0));
        while(!Q.empty()) {
            pi temp = Q.front();
            Q.pop();
            int pos = temp.first;
            int k = temp.second;
            if(pos == n-1)
                return true;
            for( int i = k-1 ; i <= k+1 ; i++ )
                if(i > 0) {
                    it = mp.find(ar[pos]+i);
                    if(it == mp.end())
                        continue;
                    int idx = it->second;
                    if(!mark[idx][i]) {
                        Q.push(pi(idx,i));
                        mark[idx][i] = true;
                    }
                }
        }
        return false;
    }
};