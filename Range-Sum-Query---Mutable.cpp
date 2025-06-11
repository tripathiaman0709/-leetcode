class NumArray {
public:
    int n;
    vector<int>segment;
    //segment tree ka basic question
    void buildSegmentTree(int i,int l,int r,vector<int>&nums,vector<int>&segment){
        //base case
        if(l==r){
            segment[i]=nums[l];//or nums[r]
            return;
        }
        int mid=l+(r-l)/2;
        buildSegmentTree(2*i+1,l,mid,nums,segment);
        buildSegmentTree(2*i+2,mid+1,r,nums,segment);

        segment[i]=segment[2*i+1]+segment[2*i+2];
    }


    void updateSegmentTree(int ind,int val,int i,int l,int r,vector<int>&segment){
        if(l==r){
            segment[i]=val;
            return;
        }

        int mid=l+(r-l)/2;

        if(ind<=mid){
            updateSegmentTree(ind,val,2*i+1,l,mid,segment);
        }else{
            updateSegmentTree(ind,val,2*i+2,mid+1,r,segment);
        }

        segment[i]=segment[2*i+1]+segment[2*i+2];
    }

    int fun(int start,int end,int l,int r,int i,vector<int>&segment){
        if(end<l || start>r){
            return 0; 
        } 

        if(l>=start && r<=end){
            return segment[i];
        }

        int mid=l+(r-l)/2;

        return fun(start,end,l,mid,2*i+1,segment)+fun(start,end,mid+1,r,2*i+2,segment);
    }
    

    NumArray(vector<int>& nums) {
        n=nums.size();
        segment.resize(4*n);
        //taking the size as 4n to be at a safer limit
        //and include all the nodes

        buildSegmentTree(0,0,n-1,nums,segment);
    }
    
    void update(int index, int val) {
        //updating an index with value val in the given array

        updateSegmentTree(index,val,0,0,n-1,segment);
    }
    
    int sumRange(int left, int right) {
        return fun(left,right,0,n-1,0,segment);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */