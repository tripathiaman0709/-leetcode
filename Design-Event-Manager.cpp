1class EventManager {
2public:
3    unordered_map<int,int> mpp;
4    set<pair<int,int>> st;
5
6    EventManager(vector<vector<int>>& v) {
7        for(auto &e : v){
8            int id = e[0], p = e[1];
9            mpp[id] = p;
10            st.insert({p, -id});
11        }
12    }
13    
14    void updatePriority(int id, int np) {
15        int old = mpp[id];
16        st.erase({old, -id});
17        mpp[id] = np;
18        st.insert({np, -id});
19    }
20    
21    int pollHighest() {
22        if(st.empty()) return -1;
23
24        auto it = prev(st.end());
25        int id = -it->second;
26
27        st.erase(it);
28        mpp.erase(id);
29
30        return id;
31    }
32};