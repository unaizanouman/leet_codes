class Solution{
    struct Event{
        long long y,x1,x2;
        int type;
        bool operator<(Event const& o) const{
            return y < o.y;
        }
    };

    vector<long long> xs;
    vector<int> cnt;
    vector<long long> seglen;

    void pull(int idx,int l,int r){
        if(cnt[idx] > 0){
            seglen[idx] = xs[r] - xs[l];
        }else if(l+1 == r){
            seglen[idx] = 0;
        }else{
            seglen[idx] = seglen[idx*2] + seglen[idx*2+1];
        }
    }

    void update(int idx,int l,int r,int ql,int qr,int v){
        if(qr <= l || r <= ql) return;
        if(ql <= l && r <= qr){
            cnt[idx] += v;
            pull(idx,l,r);
            return;
        }
        int m = (l+r)/2;
        update(idx*2,l,m,ql,qr,v);
        update(idx*2+1,m,r,ql,qr,v);
        pull(idx,l,r);
    }

public:
    double separateSquares(vector<vector<int>>& squares){
        vector<Event> events;
        xs.clear();

        for(auto &s: squares){
            long long x=s[0], y=s[1], l=s[2];
            events.push_back({y, x, x+l, +1});
            events.push_back({y+l, x, x+l, -1});
            xs.push_back(x);
            xs.push_back(x+l);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(events.begin(), events.end());

        int n = xs.size();
        cnt.assign(4*n,0);
        seglen.assign(4*n,0);

        struct Strip{ double y, h, w, pref; };
        vector<Strip> strips;

        long long prevY = events[0].y;
        double area = 0;
        int i = 0;

        while(i < events.size()){
            long long y = events[i].y;
            if(y > prevY){
                double h = y - prevY;
                double w = seglen[1];
                area += w * h;
                strips.push_back({(double)prevY, h, w, area});
                prevY = y;
            }
            while(i < events.size() && events[i].y == y){
                int l = lower_bound(xs.begin(), xs.end(), events[i].x1) - xs.begin();
                int r = lower_bound(xs.begin(), xs.end(), events[i].x2) - xs.begin();
                update(1,0,n,l,r,events[i].type);
                i++;
            }
        }

        double half = area / 2.0;
        double prevArea = 0;

        for(auto &s: strips){
            if(s.pref >= half){
                double need = half - prevArea;
                return s.y + need / s.w;
            }
            prevArea = s.pref;
        }

        return 0.0;
    }
};