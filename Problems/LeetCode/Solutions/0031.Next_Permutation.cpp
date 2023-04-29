class Solution {
public:
    void nextPermutation(vector<int>& ar) {
        int n = ar.size();
        bool found = false;
        for( int i = n-2 ; i >= 0 ; i-- )
            if(ar[i] < ar[i+1]) {
                found = true;
                int bigger = i+1;
                for( int j = i+1 ; j < n ; j++ )
                    if(ar[j] > ar[i] && ar[j] < ar[bigger])
                        bigger = j;
                swap(ar[i],ar[bigger]);
                sort(ar.begin()+i+1,ar.end());
                break;
            }
        if(!found)
            sort(ar.begin(),ar.end());
    }
};