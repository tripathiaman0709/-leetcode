class Solution {
public:
struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second;  
            return a.first > b.first; 
        }
    };
    
    string clearStars(string s) {
        int n=s.size();
        string ans="";

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                // jo pop visit kar diya
                vis[pq.top().second]=1;
                pq.pop();
                
                // ye star ko visit kar rha, vo to answer ka hissa hoga hi nhi
                vis[i]=1;
            }else{
                // ascii ka kamal
                pq.push({s[i],i});
            }
        }
        
        for(int i=0;i<n;i++){
            // jo visit nhi vo answer me jayega
            if(vis[i]==0){
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};