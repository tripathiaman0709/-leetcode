class NumArray {
public:
    int n;
    vector<int>pre;

    int fun(int l,int r,vector<int>&pre){
        if(l==0){
            return pre[r];
        }
        return pre[r]-pre[l-1];
    }

    NumArray(vector<int>& nums) {
        //as array immutable hai
        //toh koi update nhi hoga koi bhi index
        //so prefix sum me koi dikkat nhi hogi

        n=nums.size();

        pre.resize(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }

    }
    
    int sumRange(int left, int right) {
        return fun(left,right,pre);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */