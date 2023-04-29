class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& v) {
        int n = v.size() , ans = 0;
        sort(v.begin(),v.end());
        int i = 0 , j = n/2;
        while(i < n/2 and j < n) {
            if(2*v[i] <= v[j])
                ans++,i++,j++;
            else
                j++;
        }
        return 2*ans;
    }
};
