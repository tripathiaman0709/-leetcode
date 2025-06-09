class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& v) {
        int n=v.size();
        vector<int>ans(n,0);
        // for(int i=0;i<n-1;i++){
        //     int x=v[i];
        //     int maxi=-1;
        //     int p=0;
        //     int count=0;
        //     for(int j=i+1;j<n;j++){
        //         maxi=max(maxi,v[j]);
        //         if(v[j]>x){
        //             count++;
        //             p=1;
        //             ans[i]=count;
        //             break;
        //         }
        //         else if(v[j]<x && v[j]>=maxi){
        //             count++;
        //         }
        //     }
        //     if(p==0){
        //         ans[i]=count;
        //     }
        // }

        //using stack

        stack<int>st;
        int i=n-1;

        while(i>=0){
            int count=0;
            if(st.empty()){
                ans[i]=count;
            }
            while(!st.empty() && st.top()<v[i]){
                count++;
                st.pop();
            }
            if(!st.empty()){
                count++;
            }
            ans[i]=count;
            st.push(v[i]);
            i--;
        }
        return ans;
    }
};