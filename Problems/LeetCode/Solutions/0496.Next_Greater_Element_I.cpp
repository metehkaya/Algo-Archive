class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        stack<int>st;
        vector<int>ans;
        unordered_map<int,int>hashh;
        for( int i = 0 ; i < m ; i++ ) {
            if(st.empty())
                st.push(arr2[i]);
            else {
                while(!st.empty() && st.top() < arr2[i]) {
                    hashh.insert( make_pair( st.top() , arr2[i] ) );
                    st.pop();
                }
                st.push(arr2[i]);
            }
        }
        unordered_map<int,int>::iterator iter;
        for( int i = 0 ; i < n ; i++ ) {
            iter = hashh.find(arr1[i]);
            if( iter == hashh.end() )
                ans.push_back(-1);
            else
                ans.push_back(iter->second);
        }
        return ans;
    }
};