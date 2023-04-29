class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size() , ans = 0;
        int currA = capacityA , currB = capacityB;
        int i,j;
        for( i = 0 , j = n-1 ; i < j ; i++ , j-- ) {
            if(currA < plants[i])
                currA = capacityA , ans++;
            if(currB < plants[j])
                currB = capacityB , ans++;
            currA -= plants[i];
            currB -= plants[j];
        }
        if(i == j && max(currA,currB) < plants[i])
            ans++;
        return ans;
    }
};
