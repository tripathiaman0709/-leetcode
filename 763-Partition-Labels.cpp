class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>ans;
        int end=0;
        int size=0;

        vector<int>hash(26,0);
        for(int i=0;i<n;i++){
            hash[s[i]-'a']=i;
            //storing the last occurence index of each character in the string
        }

        for(int i=0;i<n;i++){
            size++;
            end=max(end,hash[s[i]-'a']);

            if(i==end){
                ans.push_back(size);
                size=0;
            }
        }
        return ans;        
    }
};