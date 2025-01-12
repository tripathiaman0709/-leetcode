class Solution {
public:
    bool canBeValid(string s, string l) {
        //trying easy and simpler way
        //two way traversal
        //from left to right
        //and from right to right
        // int n=s.size();
        // if(n%2){
        //     return false;
        // }
        // int count1=0;
        // for(int i=0;i<n;i++){
        //     if(l[i]=='0'){
        //         count1++;
        //     }
        //     else if(s[i]=='('){
        //         count1++;
        //     }
        //     else if(s[i]==')'){
        //         count1--;
        //     }
        //     if(count1<0){
        //         return false;
        //     }
        // }
        // int count2=0;
        // for(int i=n-1;i>=0;i--){
        //     if(l[i]=='0'){
        //         count2++;
        //     }
        //     else if(s[i]==')'){
        //         count2++;
        //     }else if(s[i]=='('){
        //         count2--;
        //     }
        //     if(count2<0){
        //         return false;
        //     }
        // }
        // return true;

        //now trying the stack way
        //storing the indexes where the open brackets occur
        stack<int>open;
        stack<int>openclose;

        int n=s.size();
        for(int i=0;i<n;i++){
            if(l[i]=='0'){
                openclose.push(i);
            }else if(s[i]=='('){
                open.push(i);
            }else{
                //we got ')'
                if(!open.empty()){
                    open.pop();
                }else if(!openclose.empty()){
                    openclose.pop();
                }else{
                    return false;
                }
            }
        }
        while(!open.empty() && !openclose.empty() && open.top()<openclose.top()){
            open.pop();
            openclose.pop();
        }
        if(!open.empty()){
            return false;
        }
        if(openclose.size()%2){
            return false;
        }

        return true;
    }
};