#include <bits/stdc++.h>
using namespace std;

class Interval {
    public:
    int low;
    int high;

    Interval(int low, int high){
        this->high = high;
        this->low = low;
    }
};

class ITNode {
    public:
    Interval *i;
    int max;
    ITNode* left;
    ITNode* right;

    ITNode(Interval* it, int max){
        this->i = it;
        this->max = max;
        this->left = NULL;
        this->right = NULL;
    }
};

class IntervalTree {
    bool isOverlapping (Interval *i1, Interval *i2){
        if(i1->low < i2->high && i2->low < i1->high){
            return true;
        }
        return false;
    }

    public:
    // Insertion is done like BST all with low less will go in left and others in right
    ITNode* insert(ITNode* root, Interval *it){
        if(!root) {
            root = new ITNode(it, INT_MIN);
            return root;
        }
        int low = root->i->low;
        if(it->low < low){
            root->left = insert(root->left, it);
        }
        else{
            root->right = insert(root->right, it);
        }

        if(root->max < it->high){
            root->max = it->high;
        }
        return root;
    }

    Interval* getOverlappingPair(ITNode* root, Interval* it){
        if(!root) return NULL;

        if(isOverlapping(root->i, it)){
            return root->i;
        }

        if(root->left && root->left->max >= it->low){
            // means here the overlapping pair will exist
            return getOverlappingPair(root->left, it);
        }
        return getOverlappingPair(root->right, it);
    }
};

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    IntervalTree iTree;

    ITNode* root = NULL;
    int x;
    
    cout<<"Enter the number of intervals: "<<"\n";
    cin>>x;

    for(int i=0; i<x; i++){
        int low, high;
        cin>>low>>high;
        Interval *it = new Interval(low, high);
        root = iTree.insert(root, it);
    }

    cout<<"Please enter the interval you want to check: "<<"\n";
    int low,high;
    cin>>low>>high;
    Interval*it = new Interval(low, high);

    Interval* ans = iTree.getOverlappingPair(root, it);

    if(ans){
        cout<<"Overlaps with: ["<<ans->low<<", "<<ans->high<<"]";
    } else {
        cout<<"This interval doesnt overlap";
    }
    return 0;
}