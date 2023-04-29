typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    const int MAXT = (int) 1e5+1;
    int maxEvents(vii& ar) {
        int n = ar.size() , ans = 0;
        vii ends(MAXT);
        for( int i = 0 ; i < n ; i++ )
            ends[ar[i][0]].push_back(ar[i][1]);
        priority_queue<int,vector<int>,greater<int>> heap;
        for( int t = 1 ; t < MAXT ; t++ ) {
            for( int i = 0 ; i < ends[t].size() ; i++ )
                heap.push(ends[t][i]);
            while(!heap.empty() && heap.top() < t)
                heap.pop();
            if(!heap.empty()) {
                ans++;
                heap.pop();
            }
        }
        return ans;
    }
};