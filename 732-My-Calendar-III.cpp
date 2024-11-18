class MyCalendarThree {
public:
    map<int,int>mpp;
    int maxi=0;
    MyCalendarThree() {
    }
    
    int book(int s, int e) {
        mpp[s]++;
        mpp[e]--;
        int sum=0;        
        for(auto it:mpp){
            sum+=it.second;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */