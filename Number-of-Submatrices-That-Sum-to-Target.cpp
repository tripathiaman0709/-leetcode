class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& grid, int t) {
        int n=grid.size();
        int m=grid[0].size();

        // //firstly trying brute force approach
        // int count=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         for(int endr=i;endr<n;endr++){
        //             for(int endc=j;endc<m;endc++){
        //                 //calculating sum;
        //                 int sum=0;

        //                 for(int k=i;k<=endr;k++){
        //                     for(int h=j;h<=endc;h++){

        //                         sum+=grid[k][h];
        //                     }
        //                 }

        //                 if(sum==t){
        //                     count++;
        //                 }
        //             }
        //         }
        //     }
        // }


        int count=0;
        //now applying the same approach like we did in subarray target question
        //by using prefix calculation
        //to save on time complexity

        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                grid[i][j]+=grid[i][j-1];
            }
        }

        for(int col=0;col<m;col++){
           
            for(int j=col;j<m;j++){       

                unordered_map<int,int>mpp;
                mpp[0]++;
                int sum=0;     

                for(int i=0;i<n;i++){
                    sum+=grid[i][j];
                    if(col>0){
                        sum-=grid[i][col-1];
                    }
                    if(mpp.count(sum-t)){
                        count+=mpp[sum-t];
                    }
                    mpp[sum]++;
                }
        }

            
        }
        

        return count;
    }
};