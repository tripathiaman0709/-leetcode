class Solution {
public:
    int findClosest(int x, int y, int z) {
        int disx=abs(z-x);
        int disy=abs(z-y);

        if(disx>disy){
            return 2;
        }else if(disx<disy){
            return 1;
        }else{
            return 0;
        }
    }
};