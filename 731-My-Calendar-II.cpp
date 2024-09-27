class MyCalendarTwo {
public:

    vector<pair<int,int>>second;
    vector<pair<int,int>>first;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto it:second){
            int pehla=it.first;
            int doosra=it.second;
            if(max(pehla,start)<min(doosra,end)){
                return false;
            }
        }
        for(auto it:first){
            int pehla=it.first;
            int doosra=it.second;
            
            second.push_back({max(start,pehla),min(end,doosra)});
        }

        first.push_back({start,end});
        return true;
    }
};