class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n3 = arr3.size();
        vector<int> ans;
        for( int i=0,j=0,k=0 ; i<n1 && j<n2 && k<n3 ; ) {
            int mx = max( arr1[i] , max( arr2[j] , arr3[k] ) );
            if( arr1[i] == mx && arr2[j] == mx && arr3[k] == mx ) {
                ans.push_back(mx);
                i++,j++,k++;
            }
            else {
                if(arr1[i] < mx) i++;
                if(arr2[j] < mx) j++;
                if(arr3[k] < mx) k++;
            }
        }
        return ans;
    }
};