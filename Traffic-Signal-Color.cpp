1class Solution {
2public:
3    string trafficSignal(int k) {
4        if(k==0){
5            return "Green";
6        }else if(k==30){
7            return "Orange";
8        }else if(k>30 && k<=90){
9            return "Red";
10        }else{
11            return "Invalid";
12        }
13    }
14};