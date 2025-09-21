class MovieRentingSystem {
    struct Entry {
        int shop, movie, price;
        bool operator<(const Entry& o) const {
            if (price != o.price) return price < o.price;
            if (shop != o.shop) return shop < o.shop;
            return movie < o.movie;
        }
    };
    map<pair<int,int>,int> priceMap;
    unordered_map<int,set<Entry>> available;
    set<Entry> rented;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto&e: entries) {
            priceMap[{e[0],e[1]}]=e[2];
            available[e[1]].insert({e[0],e[1],e[2]});
        }
    }
    vector<int> search(int movie) {
        vector<int> res;
        auto it=available.find(movie);
        if(it!=available.end()) {
            for(auto&e:it->second){
                res.push_back(e.shop);
                if(res.size()==5) break;
            }
        }
        return res;
    }
    void rent(int shop,int movie) {
        int price=priceMap[{shop,movie}];
        available[movie].erase({shop,movie,price});
        rented.insert({shop,movie,price});
    }
    void drop(int shop,int movie) {
        int price=priceMap[{shop,movie}];
        rented.erase({shop,movie,price});
        available[movie].insert({shop,movie,price});
    }
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for(auto&e:rented){
            res.push_back({e.shop,e.movie});
            if(res.size()==5) break;
        }
        return res;
    }
};
