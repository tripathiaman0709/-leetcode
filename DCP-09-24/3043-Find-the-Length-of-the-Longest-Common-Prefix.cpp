class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        //putting elements in the hashset
        vector<int>a;
        vector<int>b;
        unordered_set<string>hash;
        if(arr1.size()>arr2.size()){
            a=arr2;
            b=arr1;
        }else{
            a=arr1;
            b=arr2;
        }

        for(int i=0;i<a.size();i++){
            int num=a[i];
            while(num){
                hash.insert(to_string(num));
                num/=10;
            }
        }
        int maxi=0;
        for(int i=0;i<b.size();i++){
            int num=b[i];
            while(num && hash.count(to_string(num))==0){
                num/=10;
            }
            if(num){
                string s=to_string(num);
                int size=s.size();
                maxi=max(maxi,size);
            }
        }
        return maxi;
    }
};