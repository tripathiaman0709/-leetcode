class Solution {
public:
    bool haveConflict(vector<string>& e1, vector<string>& e2) {
        string s1=e1[0];
        string s2=e1[1];

        int lt1=(((s1[0]-48)*10 + (s1[1]-48)) * 60) + ((s1[3]-48)*10 + (s1[4]-48));
        int rt1=(((s2[0]-48)*10 + (s2[1]-48)) * 60) + ((s2[3]-48)*10 + (s2[4]-48));

        string s3=e2[0];
        string s4=e2[1];

        int lt2=(((s3[0]-48)*10 + (s3[1]-48)) * 60) + ((s3[3]-48)*10 + (s3[4]-48));
        int rt2=(((s4[0]-48)*10 + (s4[1]-48)) * 60) + ((s4[3]-48)*10 + (s4[4]-48));

        //non-overlapping condition

        if((rt1<lt2) || (lt1>rt2)){
            return false;
        }

        return true;

    }
};