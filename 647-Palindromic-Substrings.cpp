class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        //saari lengths ke liye check karenge 
        //pehle 1 length vale saare hi palindrome honge
        //then 2 length vale so simply check kr lenge if s[i+1]==s[j]
        //then baaki ke liye generic tareeke se

        int count=0;
        vector<vector<bool>>v(n,vector<bool>(n,false));

        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(i==j){
                    v[i][j]=true;
                }else if(i+1==j){
                    v[i][j]=(s[i]==s[j]);
                }else{
                    v[i][j]=(s[i]==s[j] && v[i+1][j-1]);
                }
                if(v[i][j]){
                count++;
            }
            }
        }
        return count;
    }
};