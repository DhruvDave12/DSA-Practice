#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    vector<pair<int,int>> vec;
    MyCalendar() {
        vec.clear();
    }
    bool isOverlapping(int start1, int end1, int start2, int end2){
        if(start1 < end2 && start2 < end1){
            return true;
        }   
        return false;
    }

    bool book(int start, int end) {
        if(vec.size() == 0) {
            vec.push_back({start, end});
            return true;
        }

        for(int i=vec.size()-1; i>=0; i--){
            if(isOverlapping(vec[i].first, vec[i].second, start, end)){
                return false;
            }
        }
        vec.push_back({start,end});
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}