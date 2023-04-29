#define fi first
#define se second
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

class Solution {
public:
    int n,m;
    bool mark[1000][1000];
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        n = nums1.size();
        m = nums2.size();
        priority_queue<pii> heap;
        mark[0][0] = true;
        heap.push(pii(-nums1[0]-nums2[0],pi(0,0)));
        while(!heap.empty() && k) {
            k--;
            pii p = heap.top();
            heap.pop();
            int i = p.se.fi;
            int j = p.se.se;
            vector<int> add(2);
            add[0] = nums1[i];
            add[1] = nums2[j];
            ans.push_back(add);
            if(i+1 < n && !mark[i+1][j]) {
                mark[i+1][j] = true;
                heap.push(pii(-nums1[i+1]-nums2[j],pi(i+1,j)));
            }
            if(j+1 < m && !mark[i][j+1]) {
                mark[i][j+1] = true;
                heap.push(pii(-nums1[i]-nums2[j+1],pi(i,j+1)));
            }
        }
        return ans;
    }
};