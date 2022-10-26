class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    
    SeatManager(int n) {
        pq = priority_queue<int,vector<int>,greater<int>>();
        for(int i=1; i<=n; i++){
            pq.push(i);
        }
    }
    
    int reserve() {
        if(pq.empty()) return -1;
        int ans = pq.top();
        pq.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */