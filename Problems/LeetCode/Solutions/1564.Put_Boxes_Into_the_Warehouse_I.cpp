class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = boxes.size();
        int m = warehouse.size();
        vector<int> ar;
        for( int i = 0 , mn = INT_MAX ; i < m ; i++ ) {
            mn = min(mn,warehouse[i]);
            ar.push_back(mn);
        }
        sort(ar.begin(),ar.end());
        sort(boxes.begin(),boxes.end());
        int l = 1 , r = min(n,m) , ans = 0;
        while(l <= r) {
            int k = (l+r) >> 1;
            bool ok = true;
            for( int i = 0 ; i < k ; i++ )
                if(boxes[i] > ar[m-k+i])
                    ok = false;
            if(ok)
                ans = k , l = k+1;
            else
                r = k-1;
        }
        return ans;
    }
};