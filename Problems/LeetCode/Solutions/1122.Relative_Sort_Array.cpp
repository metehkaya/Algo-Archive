class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> hashh;
        map<int,int>::iterator iter;
        for( int i = 0 ; i < arr1.size() ; i++ ) {
            int val = arr1[i];
            iter = hashh.find(val);
            if(iter == hashh.end())
                hashh.insert( make_pair(val,1) );
            else
                iter->second++;
        }
        vector<int>ans;
        for( int i = 0 ; i < arr2.size() ; i++ ) {
            int val = arr2[i];
            iter = hashh.find(val);
            if(iter != hashh.end()) {
                int cnt = iter->second;
                for( int j = 0 ; j < cnt ; j++ )
                    ans.push_back(val);
                hashh.erase(iter);
            }
        }
        for( iter = hashh.begin() ; iter != hashh.end() ; iter++ ) {
            int val = iter->first;
            int cnt = iter->second;
            for( int j = 0 ; j < cnt ; j++ )
                ans.push_back(val);
        }
        return ans;
    }
};