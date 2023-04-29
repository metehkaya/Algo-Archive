class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size() , head = 0;
        for( int i = 0 , curr = 0 ; i < n ; i++ ) {
            curr += gas[i]-cost[i];
            if(curr < 0) {
                curr = 0;
                head = (i+1)%n;
            }
        }
        for( int i = 0 , curr = 0 ; i < n ; i++ ) {
            int idx = (head+i) % n;
            curr += gas[idx]-cost[idx];
            if(curr < 0)
                return -1;
        }
        return head;
    }
};