class Solution {
public:
    bool checkConstraints(vector<int>& nums, int d, int x, int y) {

        int n = nums.size();

        // two 2-bit bitmasks
        // prev[0] = 1 if using x to replace the wildcard satisfies the constraint
        // prev[1] = 1 if using y to replace the wildcard satisfies the constraint
        // same for post
        int prev = 0, post = 0;

        for (int i = 1; i < n-1; ++i) {
            // skip regular positions because we only focus on wildcards to check constraints
            if (nums[i] != -1) continue;

            // case: {a, ?, b}
            if (nums[i-1] != -1 && nums[i+1] != -1) {
                if (!((abs(nums[i-1]-x) <= d && abs(nums[i+1]-x) <= d)
                    || (abs(nums[i-1]-y) <= d && abs(nums[i+1]-y) <= d)))
                    return false;
            }
            
            // case: {a, ?, ?}
            // set prev bits
            if (nums[i-1] != -1 && nums[i+1] == -1) {
                if (abs(nums[i-1]-x) <= d )
                    prev = prev | 1;
                if (abs(nums[i-1]-y) <= d)
                    prev = prev | (1 << 1);
                if (prev == 0) {
                    return false;
                }
            }

            // case: {?, ?, a}
            // set post bits
            if (nums[i-1] == -1 && nums[i+1] != -1) {
                if (abs(nums[i+1]-x) <= d)
                    post = post | 1;
                if (abs(nums[i+1]-y) <= d)
                    post = post | (1 << 1);
                if (post == 0)
                    return false;

                // if prev==01 && post==10, or prev=10 && post==01
                // this means I have used both x and y as replacements in the consecutive wildcard sequence
                // in this case I must check if |x-y| satisifies the constraint
                // in all other cases, I could use just either x or y (but not both) in the sequence
                // so I don't need to check this global constraint
                if ((prev ^ post) == 3) {
                    if (abs(x-y) > d)
                        return false;
                }

                // reset bitmasks after the current consecutive wildcard sequence is finished
                prev = 0;
                post = 0;
            }
        }

        return true;
    }

    int minDifference(vector<int>& nums) {

        // first we check if either the first or the last element is a wildcard
        // that is also neighboring a regular number
        // we reduce these edge cases to a regular case by appending the neighboring regular number
        // so e.g. {?, a} becomes {a, ?, a}, and {a, ?} becomes {a, ?, a}
        // this won't have any effect on the result
        // but it simplies the edges cases so that we don't have to take special care in subroutines
        // note that nums size might be changed so be careful here
        if (nums[0] == -1 && nums[1] != -1)
            nums.insert(nums.begin(), nums[1]);
        if (nums[nums.size()-1] == -1 && nums[nums.size()-2] != -1)
            nums.push_back(nums[nums.size()-2]);
        int n = nums.size();

        // preprocess the array to identify the subarray of elements neighboring a wildcard
        // we need to find the min and max of this subarray to form the initial bound on
        // the maximal adjacent different, d
        int min_a = INT_MAX, max_a = -1;
        int low_d = 0;
        for (int i = 0; i < n-1; ++i) {
            if (nums[i] != -1 && nums[i+1] == -1) {
                min_a = min(min_a, nums[i]);
                max_a = max(max_a, nums[i]);
            }
            if (nums[i] == -1 && nums[i+1] != -1) {
                min_a = min(min_a, nums[i+1]);
                max_a = max(max_a, nums[i+1]);
            }
            
            // if we find two adjacent regular numbers, calculate their difference
            // the max of these regular differences is the lower-bound on d regardless of replacements
            if (nums[i] != -1 && nums[i+1] != -1) {
                low_d = max(low_d, abs(nums[i+1]-nums[i]));
            }

            // consecutive widlcards do not require preprocessing
        }

        // edge case #1: when there are no critical positions
        // in these cases min_a and max_a are not updated from initial values
        // 1) all elements are regular numbers 
        // 2) all elements are wildcards
        // in both cases we return low_d i.e. the lower-bound on d found on all regular numbers
        // in the latter case low_d = initial value 0
        if (min_a == INT_MAX && max_a == -1) 
            return low_d;
        
        // edge case #2: min_a == max_a
        // 1) exactly one critical position
        // 2) all critical positions have identical elements
        // in both cases, the critical position's adjacent difference can be made zero by picking
        // the right (x,y), so the global d comes down to just low_d
        if (min_a == max_a)
            return low_d;
        
        // the bound on d is [low_d, max_a - min_a]
        // we do a binary search on this range to find the lowest possible d
        // the constraint is checked by making sure there exists an assignment of (x,y) to obtain this d
        int low = max(low_d, 1);
        int high = max_a - min_a;
        int d = max(low_d, high);
        while (low <= high ){
            int mid = low + (high - low) / 2;
            // cout << mid << " | ";

            // for a given d, the optimal choice of (x, y) is that
            // x = min_a + d, y = max_a -d
            // if constraints are satisfied, we can reduce d by going to the lower half
            // this process guarantees we find the smallest possible d that satisfies the constraint
            if (checkConstraints(nums, mid, min_a+mid, max_a-mid)) {
                d = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }

        return d;
    }
};