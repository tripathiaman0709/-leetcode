class Solution {
public:
    int maximumSwap(int num) {
        //making  suffix array containing maximum element to its right

        string s=to_string(num);
        int n=s.size();
        int maxi=0;
        vector<int>v(n,0);
        for(int i=n-1;i>=0;i--){
            maxi=max(s[i]-'0',maxi);
            v[i]=maxi;
        }
        for(int i=0;i<n;i++){
            if(s[i]-'0'<v[i]){
                for(int j=n-1;j>=0;j--){
                    if(s[j]-'0'==v[i]){
                        swap(s[i],s[j]);
                        int ans=stoi(s);
                        return ans;
                    }
                }
            }
        }
        int ans=stoi(s);
        return ans;
    }
};