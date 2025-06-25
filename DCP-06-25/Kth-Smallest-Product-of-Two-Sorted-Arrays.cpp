class Solution {
public:

    long long fun(vector<int>& v1, vector<int>& v2, long long mid){
        int n = v1.size();
        int m = v2.size();
        long long count = 0;

        for (int i = 0; i < n; i++) {
            long long a = v1[i];

            if (a > 0) {
                // We want number of v2[j] such that a * v2[j] <= mid
                // => v2[j] <= mid / a
                long long val =floor((double)mid/a);
                count += upper_bound(v2.begin(), v2.end(), val) - v2.begin();
            } else if (a < 0) {
                // We want a * v2[j] <= mid => v2[j] >= ceil(mid / a)
                long long val = ceil((double)mid/a); 
                count += v2.end() - lower_bound(v2.begin(), v2.end(), val);
            } else {
                // a == 0
                // All products are 0, so if mid >= 0, all m products are valid
                if (mid >= 0) count += m;
            }
        }

        return count;
    }

    long long kthSmallestProduct(vector<int>& v1, vector<int>& v2, long long k) {
        long long n=v1.size();
        long long m=v2.size();

        // priority_queue<long long,vector<long long>,greater<long long>> pq;
        // for(int i=0;i<n;i++){
        //     long long x=v1[i];
        //     for(int j=0;j<m;j++){
        //         long long y=v2[j];

        //         long long num=x*y;

        //         pq.push(num);
        //     }
        // } 
        // long long ans=-1;
        // while(k){
        //     ans=pq.top();
        //     pq.pop();
        //     k--;
        // }

        // return ans;

        //as both arrays are sorted 
        //so we can use binary search somewhere
        //using binary search on answer

        long long low=-1e11;
        long long high=1e11;

        long long ans=-1;

        while(low<=high){
            long long mid=low+(high-low)/2;

            if(fun(v1,v2,mid)>=k){
                ans=mid;
                high=mid-1;
                //aur chota dhoodne ki koshsih
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};