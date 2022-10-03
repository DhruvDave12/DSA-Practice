#include <bits/stdc++.h>
using namespace std;

class Heap {
    public:
    vector<int> vec;
    int N;

    Heap(vector<int> &arr){
        this->vec = arr;
        this->N = arr.size();    
    }

    void heapify(int i){
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        if(l < N && vec[l] > vec[largest]){
            largest = l;
        }
        if(r < N && vec[r] > vec[largest]){
            largest = r;
        }
        if(largest != i){
            swap(vec[i],vec[largest]);
            heapify(largest);
        }
    }

    vector<int> buildHeap(){
        int lastNonLeafNodeIndex = (N/2)-1;

        for(int i=lastNonLeafNodeIndex; i>=0; i--){
            heapify(i);
        }

        return vec;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> vec = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    Heap hp(vec);

    vec = hp.buildHeap();

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }

    return 0;
}