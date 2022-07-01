#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> queueA;
    queue<int> queueB;

    MyStack() {
        while(!queueA.empty()){
            queueA.pop();
        }
        while(!queueB.empty()){
            queueB.pop();
        }
    }

    void push(int x) {
        while(!queueA.empty()){
            int temp = queueA.front();
            queueB.push(temp);
            queueA.pop();
        }
        queueA.push(x);
        while(!queueB.empty()){
            int temp = queueB.front();
            queueA.push(temp);
            queueB.pop();
        }
    }
    
    int pop() {
        if(queueA.empty()){
            return -1;
        }
        int temp = queueA.front();
        queueA.pop();
        return temp;
    }
    
    int top() {
        if(queueA.empty()){
            return -1;
        }
        return queueA.front();
    }
    
    bool empty() {
        if(queueA.empty()){
            return true;
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}