class FoodRatings {
public:
    int n;
    map<string,int> food2rating;
    map<string,string> food2cuisine;
    map<string,set<pair<int,string>>> vals;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        n = foods.size();
        for( int i = 0 ; i < n ; i++ ) {
            food2rating[foods[i]] = ratings[i];
            food2cuisine[foods[i]] = cuisines[i];
            vals[cuisines[i]].insert(make_pair(-ratings[i],foods[i]));
        }
    }
    void changeRating(string food, int newRating) {
        int old = food2rating[food];
        string c = food2cuisine[food];
        vals[c].erase(make_pair(-old,food));
        vals[c].insert(make_pair(-newRating,food));
        food2rating[food] = newRating;
    }
    string highestRated(string cuisine) {
        set<pair<int,string>>::iterator sit = vals[cuisine].begin();
        return (*sit).second;
    }
};
