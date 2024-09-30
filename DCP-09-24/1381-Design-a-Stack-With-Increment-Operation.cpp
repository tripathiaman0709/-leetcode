class CustomStack {
public:
    vector<int>st;
    vector<int>v;
    int n;
    CustomStack(int maxsize) {
        n=maxsize;
    }
    
    void push(int x) {
        if(st.size()<n){
            st.push_back(x);
            v.push_back(0);
        }

    }
    
    int pop() {
        //main
        if(st.size()==0){
            return -1;
        }
        int ind=st.size()-1;
        if(ind>0){
            v[ind-1]+=v[ind];
        }

        int topval=st[ind]+v[ind];
        st.pop_back();
        v.pop_back();
        
        return topval;  
    }
    
    void increment(int k, int val) {
        int x=st.size()-1;
        int y=k-1;
        int ind=min(x,y);
        if(ind>=0){
            v[ind]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */