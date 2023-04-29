class Solution {
public:
    bool checkSubarraySum(vector<int>& ar, int k) {
        int n = ar.size() , sum = 0;
        set<int> var;
        int todo = 0;
        for( int i = 0 ; i < n ; i++ ) {
            sum = (sum + ar[i]) % k;
            if(var.find(sum) != var.end())
                return true;
            var.insert(todo);
            todo = sum;
        }
        return false;
    }
};