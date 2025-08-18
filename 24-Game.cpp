class Solution {
public:
    double delta=0.1;
    bool solve(vector<double>&v){
        if(v.size()==1){
            if(abs(v[0]-24)<=delta){
                return true;
            }else{
                return false;
            }
        }

        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                if(i==j){
                    continue;
                }
                vector<double>temp;
                for(int k=0;k<v.size();k++){
                    if(k!=i && k!=j){
                        temp.push_back(v[k]);
                    }
                }

                double a=v[i];
                double b=v[j];

                vector<double>op={a+b,a*b,a-b,b-a};
                if(b>0){
                    op.push_back(a/b);
                }
                if(a>0){
                    op.push_back(b/a);
                }

                for(auto it:op){
                    //do
                    temp.push_back(it);
                    //explore
                    if(solve(temp)==true){
                        return true;
                    }
                    //undo
                    temp.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& vec) {
        //converting all the numbers into doubles
        vector<double>v(4);

        for(int i=0;i<4;i++){
            v[i]=(vec[i]*1.0);
        }

        return solve(v);
    }
};