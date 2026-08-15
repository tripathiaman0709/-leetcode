class Solution {
public:
    double minPrice(vector<int>& p, vector<int>& d) {
        //i believe the biggest discount should be applied to the most valuable items
        //so it becomes a simple sorting problem

        double sum=0.0;

        sort(p.rbegin(),p.rend());
        sort(d.rbegin(),d.rend());

        // if(d.size()<p.size()){
        //     for(int i=0;i<p.size()-d.size();i++){
        //         d.push_back(0);
        //     }
        // }


        for(int i=0;i<p.size();i++){
            if(i>=d.size()){
                sum+=p[i];
            }else{
                double val=(p[i]*(100.0-d[i]))/100.0;
                sum+=val;
            }
        }

        return sum;
    }
};