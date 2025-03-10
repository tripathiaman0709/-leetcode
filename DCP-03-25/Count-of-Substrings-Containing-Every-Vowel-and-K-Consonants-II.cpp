class Solution {
public:

    bool isvow(char ch){
        return(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u');
    }

    long long countOfSubstrings(string s, int k) {
        //not a very easy question 
        //as a very good sliding window question

        int n=s.size();
        vector<int>nextconsonant(n,n);
        int last=n;
        for(int i=n-1;i>=0;i--){
            char ch=s[i];
            nextconsonant[i]=last;
            if(!isvow(ch)){
                last=i;
            }
        }

        int i=0;
        int j=0;
        int conso=0;
        long long ans=0;
        unordered_map<char,int>mpp;
        while(j<n){
            char ch=s[j];
            if(isvow(ch)){
                mpp[ch]++;
            }else{
                conso++;
            }

            while(i<n && conso>k){
                char ch=s[i];
                if(isvow(ch)){
                    mpp[ch]--;
                    if(mpp[ch]==0){
                        mpp.erase(ch);
                    }
                }else{
                    conso--;
                }
                i++;
            }

            while(i<n && mpp.size()==5 && conso==k){
                int ind=nextconsonant[j];
                ans+=ind-j;
                char ch=s[i];
                if(isvow(ch)){
                    mpp[ch]--;
                    if(mpp[ch]==0){
                        mpp.erase(ch);
                    }
                }else{
                    conso--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};