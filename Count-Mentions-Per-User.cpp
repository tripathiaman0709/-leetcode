1class Solution {
2public:
3    void applyMessageEvent(vector<string>event, vector<int>&mentionCount, vector<int>&offlineTime){
4
5        int timestamp = stoi(event[1]);
6
7        vector<string> ids;
8
9        stringstream ss(event[2]);
10
11        string token;
12        while(ss >> token){
13            ids.push_back(token);
14        }
15
16        //Process all IDs
17        for(string id : ids) {
18            if(id == "ALL") {
19                for(int i = 0; i<mentionCount.size(); i++) {
20                    mentionCount[i]++;
21                }
22            } else if(id == "HERE") {
23                for(int i = 0; i < mentionCount.size(); i++){
24                    if(offlineTime[i] == 0 || offlineTime[i] + 60 <= timestamp){
25                        mentionCount[i]++;
26                    }
27                }
28            } else {
29                mentionCount[stoi(id.substr(2))]++; //fetch id value i.e. x from idx (id0, id1 etc)
30            }
31        }
32
33    }
34
35    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
36        vector<int>mentionCount(numberOfUsers);
37        vector<int>offlineTime(numberOfUsers);
38
39        auto lambda=[](vector<string>& vec1, vector<string>& vec2) {
40            int t1 = stoi(vec1[1]);
41            int t2 = stoi(vec2[1]);
42
43            if(t1 == t2) {
44                return vec1[0][1] > vec2[0][1]; //comparing 'O' of "OFFLINE" with 'M' of "MESSAGE"
45                //OFFLINE should come first
46            }
47
48            return t1 < t2;
49        };
50
51        sort(events.begin(), events.end(), lambda);
52
53        for(vector<string>event: events){
54            if(event[0] == "MESSAGE") {
55                applyMessageEvent(event, mentionCount, offlineTime);
56            }
57            else if(event[0] == "OFFLINE") {
58                int timestamp = stoi(event[1]);
59                int id = stoi(event[2]);
60                offlineTime[id] = timestamp;
61            }
62        }
63
64        return mentionCount;
65    }
66};