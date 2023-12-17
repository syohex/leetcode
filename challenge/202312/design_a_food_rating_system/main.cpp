#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

struct Data {
    int rating;
    std::string name;
};

struct Compare {
    bool operator()(const Data &a, const Data &b) {
        if (a.rating == b.rating) {
            return a.name > b.name;
        }

        return a.rating < b.rating;
    }
};

class FoodRatings {
  public:
    using ScoreQueue = std::priority_queue<Data, std::vector<Data>, Compare>;

    FoodRatings(const std::vector<std::string> &foods, const std::vector<std::string> &cuisines, const std::vector<int> &ratings) {
        for (size_t i = 0; i < foods.size(); ++i) {
            cuisine_table_[foods[i]] = cuisines[i];
            food_rating_[foods[i]] = ratings[i];
            score_table_[cuisines[i]].push({ratings[i], foods[i]});
        }
    }

    void changeRating(const std::string &food, int newRating) {
        food_rating_[food] = newRating;
        const std::string &cuisine = cuisine_table_[food];
        auto &q = score_table_[cuisine];
        q.push({newRating, food});
    }

    std::string highestRated(const std::string &cuisine) {
        auto &q = score_table_[cuisine];
        auto high = q.top();

        while (food_rating_[high.name] != high.rating) {
            q.pop();
            high = q.top();
        }
        
        return high.name;
    }

    std::map<std::string, ScoreQueue> score_table_;
    std::map<std::string, std::string> cuisine_table_;
    std::map<std::string, int> food_rating_;
};

int main() {
    {
        std::vector<std::string> foods{"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
        std::vector<std::string> cuisines{"korean", "japanese", "japanese", "greek", "japanese", "korean"};
        std::vector<int> ratings{9, 12, 8, 15, 14, 7};

        FoodRatings f(foods, cuisines, ratings);
        assert(f.highestRated("korean") == "kimchi");
        assert(f.highestRated("japanese") == "ramen");
        f.changeRating("sushi", 16);
        assert(f.highestRated("japanese") == "sushi");
        f.changeRating("ramen", 16);
        assert(f.highestRated("japanese") == "ramen");
    }
    return 0;
}
