class Solution {
public:
    int st[3005];
    double check(vector<double>& a , vector<double>& b , vector<double>& c) {
        double x1 = a[0] , y1 = a[1];
        double x2 = b[0] , y2 = b[1];
        double x3 = c[0] , y3 = c[1];
        double dx1 = x3-x1 , dy1 = y3-y1;
        double dx2 = x2-x1 , dy2 = y2-y1;
        return dx1*dy2 - dx2*dy1;
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& ar) {
        int n = ar.size();
        int idx = 0;
        for( int i = 1 ; i < n ; i++ )
            if(ar[i][1] < ar[idx][1] || (ar[i][1] == ar[idx][1] && ar[i][0] < ar[idx][0]))
                idx = i;
        swap(ar[0],ar[idx]);
        vector<vector<double>> arr;
        arr.push_back({(double)ar[0][0],(double)ar[0][1]});
        for( int i = 1 ; i < n ; i++ ) {
            double dx = ar[i][0]-ar[0][0];
            double dy = ar[i][1]-ar[0][1];
            vector<double> v;
            v.push_back(ar[i][0]);
            v.push_back(ar[i][1]);
            v.push_back(atan2(dy,dx));
            v.push_back(dx*dx+dy*dy);
            arr.push_back(v);
        }
        vector<vector<double>>::iterator iter = arr.begin();
        iter++;
        sort(arr.begin()+1 , arr.end() , [&](vector<double>& a , vector<double>& b) {
            if(a[2] != b[2])
                return a[2] < b[2];
            return a[3] < b[3];
        });
        int cnt = 0;
        st[cnt++] = 0;
        for( int i = 1 ; i < n ; i++ ) {
            if(cnt == 1)
                st[cnt++] = i;
            else {
                while(cnt >= 2 && check(arr[st[cnt-2]],arr[st[cnt-1]],arr[i]) > 0)
                    cnt--;
                st[cnt++] = i;
            }
        }
        vector<vector<int>> ans;
        for( int i = 0 ; i < n ; i++ ) {
            bool ok = false;
            for( int j = 0 ; j < cnt ; j++ )
                if(arr[i][0] == arr[st[j]][0] && arr[i][1] == arr[st[j]][1])
                    ok = true;
            for( int j = 0 ; j < cnt ; j++ ) {
                int k = (j+1)%cnt;
                if(check(arr[st[j]],arr[st[k]],arr[i]) == 0)
                    ok = true;
            }
            if(ok)
                ans.push_back({(int)arr[i][0],(int)arr[i][1]});
        }
        return ans;
    }
};