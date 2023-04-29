class Solution {
public:
    vector<int> pivotArray(vector<int>& ar, int pivot) {
        vector<int> vless,vsame,vgreater;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            if(ar[i] < pivot)
                vless.push_back(ar[i]);
            else if(ar[i] > pivot)
                vgreater.push_back(ar[i]);
            else
                vsame.push_back(ar[i]);
        }
        vector<int> ans;
        ans.insert(ans.end(), vless.begin(), vless.end());
        ans.insert(ans.end(), vsame.begin(), vsame.end());
        ans.insert(ans.end(), vgreater.begin(), vgreater.end());
        return ans;
    }
};
