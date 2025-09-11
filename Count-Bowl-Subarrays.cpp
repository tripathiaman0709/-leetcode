class Solution {
public:
    long long bowlSubarrays(vector<int>& v) {
        // //wow 
        // //3rd question is medium
        // long long n=v.size();
        // long long count=0;
        // //brute force
        // for(long long i=0;i<n-2;i++){
        //     for(long long j=i+2;j<n;j++){
        //     long long mini=min(v[i],v[j]);
        //     long long maxi=0;
        //         for(long long k=i+1;k<j;k++){
        //             if(v[k]>maxi){
        //                 maxi=v[k];
        //             }
        //         }

        //         if(mini>maxi){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        
        int n=v.size();
        vector<int> left(n,-1);
        stack<int> st;
        int i=0;
        for(auto it:v){
            while(!st.empty() && v[st.top()]<it){
                st.pop();
            }
            if(!st.empty()){
                left[i]=st.top();
            }
            st.push(i);
            i++;
        }
        while(!st.empty()){
            st.pop();
        }
        vector<int> right(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && v[st.top()]<v[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top();
            }
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(left[i]!=-1 && right[i]!=n){
                ans++;
            }
        }
        return ans;
    }
};