class Solution {
public:
    string repeatLimitedString(string s, int k) {
        int n=s.size();
        //using priority queue
        //max heap
        vector<int>fre(26,0);
        for(int i=0;i<n;i++){
            fre[s[i]-'a']++;
        }        
        priority_queue<char>pq;
        for(int i=0;i<26;i++){
            if(fre[i]>0){
                pq.push('a'+i);
            }
        }
        string ans="";
        while(!pq.empty()){
            char ch=pq.top();
            pq.pop();
            int fr=min(k,fre[ch-'a']);
            fre[ch-'a']-=fr;
            ans.append(fr,ch);

            if(fre[ch-'a']>0 && !pq.empty()){
                char pch=pq.top();
                pq.pop();

                if(fre[pch-'a']>0){
                    fre[pch-'a']--;
                    ans+=pch;
                }
                if(fre[pch-'a']>0){
                    pq.push(pch);
                }

                pq.push(ch);
            }
            
        }
        return ans;
    }
};