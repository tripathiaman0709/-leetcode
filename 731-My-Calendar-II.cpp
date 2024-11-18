class MyCalendarTwo {
public:

    map<int,int>mpp;
    MyCalendarTwo() {
    }
    
    bool book(int s, int e) {
        mpp[s]++;
        mpp[e]--;

        int sum=0;
        for(auto it:mpp){
            sum+=it.second;

            if(sum>2){
                mpp[s]--;
                mpp[e]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */