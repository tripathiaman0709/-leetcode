1class Solution {
2public:
3    bool canBeEqual(string s1, string s2) {
4        string one=s1;
5        string two=s1;
6        string three=s1;
7
8        swap(one[0],one[2]);
9        swap(two[1],two[3]);
10
11        swap(three[0],three[2]);
12        swap(three[1],three[3]);
13
14        if(s2==one || s2==two || s2==three || s1==s2){
15            return true;
16        }
17
18        return false; 
19        
20    }
21};