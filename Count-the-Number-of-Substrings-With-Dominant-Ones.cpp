class Solution {
public:
    int numberOfSubstrings(string v) {
        int n=v.size();
        vector<int>one(n,0);

        int o=0;

        for(int i=0;i<n;i++){
            if(v[i]=='1'){
                o++;
            }
            one[i]=o;
        }

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int totalone=0;
                if(i>0){
                    totalone=one[j]-one[i-1];
                }else{
                    totalone=one[j];
                }
                int totalzero=(j-i+1)-totalone;

                if(totalone<totalzero*totalzero){
                    j+=(totalzero*totalzero-totalone)-1;
                    //skipping unwanted part
                }else if(totalone==totalzero*totalzero){
                    count++;
                }else{
                    count++;
                    int next=j+sqrt(totalone)-totalzero;

                    if(next>=n){
                        count+=(n-j-1);
                        break;
                    }else{
                        count+=(sqrt(totalone)-totalzero);
                    }
                    j=next;
                }
            }
        }

        return count;
    }
};