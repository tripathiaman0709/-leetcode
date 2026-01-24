1class AuctionSystem {
2public:
3    // (userId, itemId) -> bidAmount
4    map<pair<int, int>, int> bid;
5
6    // itemId -> set of (bidAmount, userId), ordered by bidAmount
7    map<int, set<pair<int, int>>> itemBids;
8
9    AuctionSystem() {}
10
11    void addBid(int userId, int itemId, int bidAmount) {
12        auto key = make_pair(userId, itemId);
13
14        // If bid already exists, remove old one
15        if (bid.count(key)) {
16            int oldAmount = bid[key];
17            itemBids[itemId].erase({oldAmount, userId});
18        }
19
20        // Insert new bid
21        bid[key] = bidAmount;
22        itemBids[itemId].insert({bidAmount, userId});
23    }
24
25    void updateBid(int userId, int itemId, int newAmount) {
26        addBid(userId, itemId, newAmount);
27    }
28
29    void removeBid(int userId, int itemId) {
30        auto key = make_pair(userId, itemId);
31        if (!bid.count(key)) return;
32
33        int amount = bid[key];
34        bid.erase(key);
35        itemBids[itemId].erase({amount, userId});
36    }
37
38    int getHighestBidder(int itemId) {
39        if (!itemBids.count(itemId) || itemBids[itemId].empty())
40            return -1;
41
42        // Highest bid = last element in ordered set
43        auto it = prev(itemBids[itemId].end());
44        return it->second; // userId
45    }
46};
47