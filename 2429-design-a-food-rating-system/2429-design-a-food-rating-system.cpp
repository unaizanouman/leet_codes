class FoodRatings {
public:
    // Maps for quick lookups
    unordered_map<string, string> foodToCuisine;  // food -> cuisine
    unordered_map<string, int> foodToRating;      // food -> rating
    unordered_map<string, set<pair<int, string>>> cuisineToFoods; // cuisine -> sorted foods

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineToFoods[cuisines[i]].insert({-ratings[i], foods[i]});
            // negative rating because set sorts ascending → so highest rating first
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];

        // Remove old rating
        cuisineToFoods[cuisine].erase({-oldRating, food});

        // Insert new rating
        cuisineToFoods[cuisine].insert({-newRating, food});
        foodToRating[food] = newRating;
    }

    string highestRated(string cuisine) {
        // Begin of set = highest rating, then lexicographically smallest
        return cuisineToFoods[cuisine].begin()->second;
    }
};
