class Solution {
public:
    int findFinalValue(vector<int>& ar, int ans) {
        while(true) {
            bool found = false;
            for(int x : ar)
                if(x == ans)
                    found = true;
            if(!found)
                break;
            ans *= 2;
        }
        return ans;
    }
};
