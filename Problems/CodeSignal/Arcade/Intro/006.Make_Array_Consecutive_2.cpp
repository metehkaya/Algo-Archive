int solution(vector<int> v) {
    int n = v.size();
    int min_val = *(min_element(v.begin(), v.end()));
    int max_val = *(max_element(v.begin(), v.end()));
    return max_val-min_val+1 - n;
}
