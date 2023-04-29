class Solution {
public:
    struct cmp1 {
        bool operator()(vector<int>& a , vector<int>& b) {
            if(a[1] != b[1])
                return a[1] > b[1];
            return a[0] < b[0];
        }
    };
    struct cmp2 {
        bool operator()(vector<int>& a , vector<int>& b) {
            if(a[1] != b[1])
                return a[1] > b[1];
            return a[0] > b[0];
        }
    };
    vector<int> pourWater(vector<int>& h, int volume, int k) {
        int n = h.size();
        priority_queue<vector<int>,vector<vector<int>>,cmp1> heap1;
        priority_queue<vector<int>,vector<vector<int>>,cmp2> heap2;
        int i = k-1 , j = k+1;
        while(volume--) {
            while(i >= 0 and h[i] <= h[i+1])
                heap1.push({i,h[i--]});
            while(j < n and h[j] <= h[j-1])
                heap2.push({j,h[j++]});
            if(!heap1.empty() and heap1.top()[1] < h[k]) {
                auto v = heap1.top();
                heap1.pop();
                v[1]++ , h[v[0]]++;
                heap1.push(v);
            }
            else if(!heap2.empty() and heap2.top()[1] < h[k]) {
                auto v = heap2.top();
                heap2.pop();
                v[1]++ , h[v[0]]++;
                heap2.push(v);
            }
            else
                h[k]++;
        }
        return h;
    }
};
