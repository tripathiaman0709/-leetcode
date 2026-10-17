class Solution {
public:

    int fun(int x){
        int sum=0;
        while(x){
            sum+=x%10;
            x/=10;
        }

        return sum;
    }

    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first){
            return a.second<b.second;
        }

        return a.first<b.first;
    }

    int minSwaps(vector<int>& v) {
        int n=v.size();
        vector<pair<int,int>>vp;
        
        for(int i=0;i<n;i++){
            int x=v[i];
            int sum=fun(x);

            vp.push_back({sum,x});
        }


        //now custom sorting

        sort(vp.begin(),vp.end(),cmp);
        vector<int>target;

        for(auto it:vp){
            target.push_back(it.second);
        }
        //using maps

        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
            mpp[v[i]]=i;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(v[i]==target[i]){
                continue;
            }
            swap(v[i],v[mpp[target[i]]]);

            mpp[v[mpp[target[i]]]]=mpp[target[i]];
            mpp[v[i]]=i;

            count++;
        }
        return count;
    }
};