class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;

        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }
        string ans="";
        while(!pq.empty()){
            int currfreq=pq.top().first;
            char currchar=pq.top().second;
            pq.pop();

            if(ans.size()>=2 && ans[ans.size()-1]==currchar && ans[ans.size()-2]==currchar){
                if(pq.empty()){
                    break;
                }
                //now choosing next element;
                int nextfreq=pq.top().first;
                char nextchar=pq.top().second;
                pq.pop();

                ans.push_back(nextchar);
                nextfreq--;
                if(nextfreq>0){
                    pq.push({nextfreq,nextchar});
                }
            }else{
                currfreq--;
                ans.push_back(currchar);
            }

            if(currfreq>0){
                pq.push({currfreq,currchar});
            }
        }
        return ans;
    }
};