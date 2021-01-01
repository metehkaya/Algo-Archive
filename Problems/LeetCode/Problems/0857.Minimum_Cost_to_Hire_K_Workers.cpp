class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        int n = q.size();
        vector<pair<double,int>> vec;
        for( int i = 0 ; i < n ; i++ )
            vec.push_back( make_pair( 1.0*w[i]/q[i] , q[i] ) );
        sort(vec.begin(), vec.end());
        int qSum = 0;
        priority_queue<int> heap;
        for( int i = 0 ; i < k ; i++ ) {
            qSum += vec[i].second;
            heap.push(vec[i].second);
        }
        double ans = qSum * vec[k-1].first;
        for( int i = k ; i < n ; i++ ) {
            heap.push(vec[i].second);
            qSum += vec[i].second;
            qSum -= heap.top();
            heap.pop();
            ans = min(ans, qSum * vec[i].first);
        }
        return ans;
    }
};