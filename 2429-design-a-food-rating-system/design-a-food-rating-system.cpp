class FoodRatings {
    // cuisine -> ordered set of (-rating, name)
    unordered_map<string, multiset<pair<int,string>>> byCuisine;
    // food -> {cuisine, rating}
    unordered_map<string, pair<string,int>> info;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = (int)foods.size();
        for (int i = 0; i < n; ++i) {
            info[foods[i]] = {cuisines[i], ratings[i]};
            byCuisine[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        auto &pr = info[food];           // {cuisine, oldRating}
        string cuisine = pr.first;
        int oldRating = pr.second;

        auto &s = byCuisine[cuisine];
        auto it = s.find({-oldRating, food});
        if (it != s.end()) s.erase(it);

        s.insert({-newRating, food});
        pr.second = newRating;
    }

    string highestRated(string cuisine) {
        return byCuisine[cuisine].begin()->second;
    }
};