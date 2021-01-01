typedef pair<int,int> pi;

class Solution {
public:
    int nthUglyNumber(int n) {
        int p[3] = {2,3,5};
        priority_queue<pi,vector<pi>,greater<pi>> heap;
        heap.push(pi(1,0));
        for( int i = 0 ; i < n-1 ; i++ ) {
            pi temp = heap.top();
            heap.pop();
            int val = temp.first;
            int ind = temp.second;
            for( int i = ind ; i <= 2 ; i++ )
                if(val <= INT_MAX / p[i])
                    heap.push(pi(val*p[i],i));
        }
        return heap.top().first;
    }
};
