1class Solution {
2public:
3    int minOperations(string s) {
4        int n = s.size() ; 
5
6        string t = s; 
7        sort( t.begin(), t.end() ) ; 
8        if( t == s ) return 0 ; 
9
10        if( n == 2 ) return -1 ; 
11
12        string t1 = s, t2 = s ; 
13        sort( t1.begin() + 1, t1.end() ) ;
14        sort( t2.begin(), t2.end() - 1 ) ; 
15        if( t == t1 || t == t2 ) return 1 ; 
16
17        char mini = s[0], maxi = s[0] ;
18        map< char, int> M ; 
19        for( char ch : s ) {
20            M[ch]++ ;
21            mini = min(mini, ch ) ;
22            maxi = max(maxi, ch ) ; 
23        }
24
25        if( maxi == s[0] && mini == s[n-1] && M[mini] == 1 && M[maxi] == 1 ) return 3 ;
26        return 2 ; 
27    }
28};