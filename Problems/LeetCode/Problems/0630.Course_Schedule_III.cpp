class Solution {
public:
    static bool comp(vector<int>& a , vector<int>& b) {
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& ar) {
        sort(ar.begin() , ar.end() , comp);
        priority_queue<int> heap;
        int n = ar.size();
        int ans = 0 , t = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(t <= ar[i][1]-ar[i][0]) {
                ans++;
                t += ar[i][0];
                heap.push(ar[i][0]);
            }
            else if(!heap.empty() && heap.top() > ar[i][0]) {
                t -= heap.top() - ar[i][0];
                heap.pop();
                heap.push(ar[i][0]);
            }
        }
        return ans;
    }
};