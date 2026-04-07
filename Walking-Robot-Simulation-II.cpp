1class Robot {
2public:
3    int idx = 0;
4    bool moved = false;
5    vector<vector<int>> pos; //store all perimter/boundary cell positions
6       Robot(int width, int height) {
7        //Bottom Row (left to right) -> East(0);
8        for (int x = 0; x < width; x++) {
9            pos.push_back({x, 0, 0});
10        }
11
12        //Right Col (bottom to top) -> North(1);
13        for (int y = 1; y < height; y++) {
14            pos.push_back({width - 1, y, 1});
15        }
16
17        // Top row (right to left) -> West(2)
18        for (int x = width - 2; x >= 0; x--) {
19            pos.push_back({x, height - 1, 2});
20        }
21
22        // Left column (top to bottom) -> South(3)
23        for (int y = height - 2; y > 0; y--) {
24            pos.push_back({0, y, 3});
25        }
26
27        pos[0][2] = 3; 
28    }
29    
30    void step(int num) {
31        moved = true;
32        idx = (idx + num) % pos.size();
33    }
34    
35    vector<int> getPos() {
36        return {pos[idx][0], pos[idx][1]};
37    }
38    
39    string getDir() {
40        if(!moved)
41            return "East";
42        
43        int d = pos[idx][2];
44        if(d == 0) return "East";
45        else if(d == 1) return "North";
46        else if(d == 2) return "West";
47        return "South";
48    }
49};