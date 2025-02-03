class Solution {
public:
    string firstStep(int num) {
        string s = to_string(num);
        int zeros = 4 - s.length();
        string prefix = "";
        while(zeros--)
            prefix.push_back('0');
        return prefix+s;
    }
    int generateKey(int num1, int num2, int num3) {
        string s1 = firstStep(num1);
        string s2 = firstStep(num2);
        string s3 = firstStep(num3);
        string s = "";
        for( int i = 0 ; i < 4 ; i++ )
            s.push_back(min(s1[i],min(s2[i],s3[i])));
        return stoi(s);
    }
};