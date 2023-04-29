typedef pair<int,int> pi;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& ar) {
        vector<int> ans;
        int n = ar.size();
        map<int,int> cnt;
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        priority_queue<pi> heap;
        for( auto it = cnt.begin() ; it != cnt.end() ; it++ )
            heap.push( pi( it->second , it->first ) );
        pi op = heap.top();
        heap.pop();
        ans.push_back(op.second);
        while(!heap.empty()) {
            pi np = heap.top();
            heap.pop();
            ans.push_back(np.second);
            if(op.first > 1)
                heap.push( pi( op.first-1 , op.second ) );
            op = np;
        }
        return ans;
    }
};