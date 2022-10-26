class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        int ans = 0;
        
        while(!pq.empty()){
            if(pq.top() == 0) {
                pq.pop();
                continue;
            }
            int first = -1, second = -1;
            first = pq.top();
            pq.pop();
            if(pq.size() > 0 && pq.top() > 0){
                second = pq.top();   
            } else if(pq.size() > 0 && pq.top() == 0){
                pq.pop();
                continue;
            } else if(pq.size() == 0){
                continue;
            }
            pq.pop();
            if(first != -1 && second != -1) {
                ans++;
                pq.push(first-1);
                pq.push(second-1);
            }
        }
        
        return ans;
    }
};