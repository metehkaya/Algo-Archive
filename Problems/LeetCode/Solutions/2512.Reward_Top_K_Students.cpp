class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        map<int,int> mp;
        for(int id : student_id)
            mp[id] = 0;
        set<string> positives,negatives;
        for(string s : positive_feedback)
            positives.insert(s);
        for(string s : negative_feedback)
            negatives.insert(s);
        int n = report.size();
        for( int i = 0 ; i < n ; i++ ) {
            string s = report[i];
            s.push_back(' ');
            string word = "";
            int len = s.length();
            for( int j = 0 ; j < len ; j++ ) {
                if(s[j] == ' ') {
                    if(positives.count(word))
                        mp[student_id[i]] += 3;
                    else if(negatives.count(word))
                        mp[student_id[i]] -= 1;
                    word = "";
                }
                else
                    word.push_back(s[j]);
            }
        }
        vector<vector<int>> scores;
        for(auto it : mp)
            scores.push_back({-it.second,it.first});
        sort(scores.begin(),scores.end());
        vector<int> ans;
        for( int i = 0 ; i < k ; i++ )
            ans.push_back(scores[i][1]);
        return ans;
    }
};
