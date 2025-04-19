class Solution {
public:
    int uniqueXorTriplets(vector<int>& v) {
        //trying super brute force approach
        // unordered_set<int>st;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         for(int k=j;k<n;k++){
        //             int x=v[i]^v[j]^v[k];
        //             st.insert(x);
        //         }
        //     }
        // }
        // return st.size();

        //time complexity - O(n^3*logn)

        //n toh honge hi
        //trying to find a possible value of that is out of the range of 1 to n
        //as we know that xor of two numbers cannot generate a number bigger than the number itself

        int n = v.size();

        if(n < 3) return n;

        // Find the Most Significant Bit
        int cnt = 0;
        int temp = n;
        while(temp > 0){
            temp >>= 1;
            cnt++;
        }
        
        return pow(2, cnt);
    }
};