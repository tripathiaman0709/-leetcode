class Solution {
public:

    void fun(int i,string &s,unordered_set<string>&st,int curcount,int & maxcount){
        //optimizing case --> but it won't change the worst case scenario
        if(curcount+s.size()-i<=maxcount){
            return;
        }
        if(i>=s.size()){
            maxcount=max(curcount,maxcount);
            return;
        }
        for(int j=i;j<s.size();j++){
            string s1=s.substr(i,j-i+1);//O(n)
            if(st.find(s1)==st.end()){
                //means new to stack ie-->not repetitive
                st.insert(s1);
                fun(j+1,s,st,curcount+1,maxcount);
                st.erase(s1);//undo step --> very important in backtracking
            }
        }
    }

    int maxUniqueSplit(string s) {
        //simple back tracking 
        //TC --> O(2^n * n^2)
        //one O(n) for trversing in the array and other O(n) for substr function
        //making total of O(n^2) with overall O(2^n) choices to either pick or not pick start 
        //of substring called i here

        int curcount=0;
        int maxcount=0;
        unordered_set<string>st;
        fun(0,s,st,curcount,maxcount);

        return maxcount;
    }
};