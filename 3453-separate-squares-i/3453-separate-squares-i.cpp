class Solution{
public:
    double separateSquares(vector<vector<int>>& squares){
        double lo = 1e18, hi = -1e18;

        for(auto &s : squares){
            lo = min(lo, (double)s[1]);
            hi = max(hi, (double)s[1] + s[2]);
        }

        auto diff = [&](double Y){
            double above = 0, below = 0;
            for(auto &s : squares){
                double y = s[1], l = s[2], top = y + l;
                if(Y <= y){
                    above += l * l;
                }else if(Y >= top){
                    below += l * l;
                }else{
                    below += (Y - y) * l;
                    above += (top - Y) * l;
                }
            }
            return above - below;
        };

        for(int i = 0; i < 80; i++){  
            double mid = (lo + hi) / 2;
            if(diff(mid) > 0) lo = mid;
            else hi = mid;
        }
        return lo;
    }
};