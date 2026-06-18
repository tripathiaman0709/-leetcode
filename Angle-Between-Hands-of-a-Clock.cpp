1class Solution {
2public:
3    double angleClock(int h, int m) {
4        //there are total 60 minutes
5        //spread around 360 degrees
6        //so each degree covers 360/60 = 6 degree for minute hand
7        //there are 12 seperations for hour hand spread across 360 degrees
8        //so each hour passing is 30 degree change in hour hand
9        //and each minute passed contributes to hour hand will be
10        //in 60 minutes it changes by 30 degeree
11        //so each minute contributes 0.5 degree to hour hand
12        h%=12;
13        double minute=(double)6*m;
14        double hour=(double)30*h;
15        hour+=(m)*(0.50);
16        fmod(minute,360.0);
17        fmod(hour,360.0);
18        double angle1=360;
19        double angle2=360;
20        angle1=abs(hour-minute);
21        angle2=abs(minute-hour);
22        double angle3=360;
23        double angle;
24        if(angle1<angle2){
25            angle=angle1;
26        }else{
27            angle=angle2;
28        }
29        angle3=360-angle;
30
31        return min(angle3,angle);
32    }
33};