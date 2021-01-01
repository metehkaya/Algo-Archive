class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> latestTime;
        sort(A.begin(), A.end());
        do {
            int h = A[0] * 10 + A[1];
            int m = A[2] * 10 + A[3];
            if(h >= 0 && h < 24 && m >= 0 && m < 60)
                latestTime = A;
        } while(next_permutation(A.begin(), A.end()));
        string ans = "";
        if( latestTime.empty() )
            return ans;
        ans.push_back('0' + latestTime[0]);
        ans.push_back('0' + latestTime[1]);
        ans.push_back(':');
        ans.push_back('0' + latestTime[2]);
        ans.push_back('0' + latestTime[3]);
        return ans;
    }
};