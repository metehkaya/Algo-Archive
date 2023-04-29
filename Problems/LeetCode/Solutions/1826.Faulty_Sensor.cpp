class Solution {
public:
    bool is_defective(vector<int>& sensor1, vector<int>& sensor2) {
        int n = sensor1.size();
        for( int k = 0 ; k < n ; k++ )
            if(sensor2[n-1] != sensor1[k]) {
                vector<int> v;
                for( int i = 0 ; i < n ; i++ )
                    if(i != k)
                        v.push_back(sensor1[i]);
                bool ok = true;
                for( int i = 0 ; i < n-1 ; i++ )
                    if(v[i] != sensor2[i])
                        ok = false;
                if(ok)
                    return true;
            }
        return false;
    }
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        bool one = is_defective(sensor2,sensor1);
        bool two = is_defective(sensor1,sensor2);
        if((one and two) or (!one and !two))
            return -1;
        else if(one and !two)
            return 1;
        else
            return 2;
    }
};
