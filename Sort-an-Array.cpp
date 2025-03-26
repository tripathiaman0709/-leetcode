class Solution {
public:

    void mergesort(vector<int>&v, int l, int r){
        //base case to stop infinite recursion 
        if(l>=r){
            return;
        }
        int mid=l+(r-l)/2;//to prevent integer overflow
        mergesort(v,l,mid);
        mergesort(v,mid+1,r);

        merge(v,l,mid,r);
    }

    void merge(vector<int>&v,int l,int mid,int r){
        int k=l;
        int n=mid-l+1;
        int m=r-mid;

        vector<int>left(n);
        vector<int>right(m);

        for (int i = 0; i < n; i++) {
            left[i] = v[l + i];
        }
        for (int i = 0; i < m; i++) {
            right[i] = v[mid + 1 + i];
        }

        int i=0;
        int j=0;

        while(i<n && j<m){
            if(left[i]<=right[j]){
                v[k]=left[i];
                i++;
            }else{
                v[k]=right[j];
                j++;
            }
            k++;
        }
        while(i<n){
            v[k]=left[i];
            i++;
            k++;
        }
        while(j<m){
            v[k]=right[j];
            j++;
            k++;
        }
    }

    vector<int> sortArray(vector<int>& v) {
        //not writing the code withiin one line
        //but rather writing the full code of merge sort
        //the most efficient sorting algorithm with O(nlogn) time complexity even in the worst case as well
        //unlike quick sort whose complexity shoots upto O(n^2) in worst case scenario
        int n=v.size();
        mergesort(v,0,n-1);

        return v;
    }
};