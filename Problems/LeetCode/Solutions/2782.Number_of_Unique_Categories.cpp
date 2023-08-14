class CategoryHandler {
public:
    CategoryHandler(vector<int> categories);
    bool haveSameCategory(int a, int b);
};

class Solution {
public:
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        int ans = 1;
        vector<int> category_2_id;
        category_2_id.push_back(0);
        for( int i = 1 ; i < n ; i++ ) {
            bool found = false;
            for( int c = 0 ; c < ans ; c++ ) {
                int id = category_2_id[c];
                if(categoryHandler->haveSameCategory(i, id)) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                ans++;
                category_2_id.push_back(i);
            }
        }
        return ans;
    }
};
