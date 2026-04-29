1class RandomizedSet {
2	// Average Time O(1) & Auxiliary Space O(N)
3private:
4    vector<int> a; // array vector
5    unordered_map<int,int> m; // Unordered Map does searching, insertion & deletion of element in average O(1) time
6public:
7    /** Initialize your data structure here. */
8    RandomizedSet() {
9    // No need to initialise a & m as they are initialised automatically
10	// to 0 as and when their container size increases.
11    }
12    
13    /** Inserts a value to the array vector. Returns true if the array did not already contain the specified element. */
14    bool insert(int val) {
15        if(m.find(val)!=m.end())
16	        // If val is not already present in the map, find() function  
17	        // returns an iterator(m.end()) pointing to the successive memory location  
18            // from the last element of the map. Otherwise, find() returns an iterator 
19            // pointing to val which was already present in the map.  
20            return false;
21        else{
22            a.push_back(val);  // insert val at the end of the array
23            m[val]=a.size()-1; // unordered_map[key]=value stores the array element and 
24			                   // its index as key=array element & value=array element index
25            return true;
26        }
27    }
28    
29    /** Removes a value from the array vector. Returns true if the array contained the specified element. */
30    bool remove(int val) {
31        if(m.find(val)==m.end()) // val not present in the array vector
32            return false;
33        else{
34	        // val present in the array vector
35	        // For example: a=[8,4,3,2], m={[8,0],[4,1],[3,2],[2,3]}, val=4, last=2
36	        // After a[m[val]]=a.back(); a=[8,2,3,2], m={[8,0],[4,1],[3,2],[2,3]}
37	        // After a.pop_back(); a=[8,2,3], m={[8,0],[4,1],[3,2],[2,3]}
38	        // After m[last]=m[val]; a=[8,2,3], m={[8,0],[4,1],[3,2],[2,1]}
39	        // After m.erase(val); a=[8,2,3], m={[8,0],[3,2],[2,1]}
40            int last=a.back();  // back() fetches last element of the array vector
41            a[m[val]]=a.back(); // m[val] locates the index of val in the array vector.
42				                // Then we copy array last element value to the val location in the array
43            a.pop_back();	    // Delete the last element of the array 
44            m[last]=m[val];	    // In hashmap, assign index of val in array to the index of the last element   
45            m.erase(val);	    // Delete the val entry from map
46            return true;
47        }
48    }
49    
50    /** Get a random element from the array vector */
51    int getRandom() {
52	    // rand() function gives random value in the range of 0 to RAND_MAX(whose value is 32767). x%y gives 
53 	    // remainder when x is divided by y and this remainder is in the range of 0 to y-1.
54	    // rand()%a.size() gives random value in the range of (0 to a.size()-1).
55	    // a[rand()%a.size()] will give random value of array in the range of a[0] to a[a.size()-1].
56        return a[rand()%a.size()];
57    }
58};