class Solution {
public:
    string triangleType(vector<int>& v) {
        sort(v.begin(),v.end());

        int a=v[0];
        int b=v[1];
        int c=v[2];

        //finding if a triangle is even possible or not
        if(a+b<=c){
            return "none";
        }

        int count=0;
        if(a==b){
            count++;
        }
        if(b==c){
            count++;
        }
        if(c==a){
            count++;
        }

        if(count==3){
            return "equilateral";
        }
        else if(count==1){
            return "isosceles";
        }
        else{
            return "scalene";
        }
    }
};