1// 1-based indexed segment tree defined recursively
2static constexpr int N=1<<17; // 2*bit_ceil(5*10^4)
3int segMin[N], segMax[N]; 
4
5struct segTree {
6    unsigned n;
7    vector<int>& A;
8    segTree(vector<int>& A) : n(A.size()), A(A) {
9        build(1, 0, n-1); 
10    }
11    void build(int idx, int l, int r) {
12        if (l==r) {
13            segMin[idx]=segMax[idx]=A[l]; 
14            return;
15        }
16        const int m=(l+r)>>1;
17        const int L=2*idx, R=L+1;
18        build(L, l, m);
19        build(R, m+1, r);
20        
21        segMax[idx] = max(segMax[L], segMax[R]);
22        segMin[idx] = min(segMin[L], segMin[R]);
23    }
24    // Range Query Max for [ql, qr]
25    int qMax(int idx, int l, int r, int ql, int qr) {
26        if (ql>r || qr<l) return INT_MIN; // Identity for max
27        if (ql<=l && r <= qr) return segMax[idx];
28        const int m=(l+r)>>1;
29        return max(qMax(2*idx, l, m, ql, qr), qMax(2*idx+1, m+1, r, ql, qr));
30    }
31    // Range Query Min for [ql, qr]
32    int qMin(int idx, int l, int r, int ql, int qr) {
33        if (ql>r || qr<l) return INT_MAX; // Identity for min
34        if (ql<=l && r <= qr) return segMin[idx]; 
35        const int m=(l+r)>>1;
36        return min(qMin(2*idx, l, m, ql, qr), qMin(2*idx+1, m+1, r, ql, qr));
37    }
38};
39
40using int3=pair<int, pair<int, int>>;
41using ll=long long;
42class Solution {
43public:
44    static long long maxTotalValue(vector<int>& nums, int k) {
45        const int n=nums.size();
46        auto [it0, itM]=minmax_element(nums.begin(), nums.end());
47        int v0=*itM-*it0;
48        auto [l0, r0]=minmax(it0-nums.begin(), itM-nums.begin());
49        ll ways=(ll)(l0+1)*(n-r0);// when l<=l0 and r>=r0  val(nums[l..r])=v0
50        if (ways>=k) return (ll)k*v0;
51        ll total=ways*v0;
52        k-=ways;
53        
54        segTree tree(nums);
55        priority_queue<int3> pq;
56        
57        // [l, n-1] where l>l0
58        for(int l=l0+1; l<n; l++){
59            const int val=tree.qMax(1,0,n-1,l,n-1)-tree.qMin(1,0,n-1,l,n-1);
60            pq.push({val, {l, n-1}});
61        }
62        // [l, r0-1] where l<=l0
63        for(int l=0; l<=l0; l++){
64            const int val=tree.qMax(1,0,n-1,l,r0-1)-tree.qMin(1,0,n-1,l,r0-1);
65            pq.push({val, {l, r0-1}});
66        }
67       
68        while(k--){
69            auto [x, lr]=pq.top(); pq.pop();
70            auto [l, r]=lr;
71            if (x==0) break;
72            total+=x;
73            if (r>l) pq.push({tree.qMax(1,0,n-1,l,r-1)-tree.qMin(1,0,n-1,l, r-1), {l, r-1}});
74        }
75        return total;
76    }
77};