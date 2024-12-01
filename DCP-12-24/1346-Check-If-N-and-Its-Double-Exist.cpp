class Solution {
public:
    bool checkIfExist(vector<int>& a) {
        int n=a.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                count++;
            }
        }
        if(count>=2){
            return true;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j || a[i]==0 || a[j]==0){
                    continue;
                }else{
                    if(a[j]%a[i]==0 && a[j]/a[i]==2){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};