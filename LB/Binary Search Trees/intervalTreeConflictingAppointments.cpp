#include <bits/stdc++.h>
using namespace std;

class Interval
{
public:
    int low;
    int high;

    Interval(int low, int high)
    {
        this->high = high;
        this->low = low;
    }
};

class ITNode
{
public:
    Interval *i;
    int max;
    ITNode *left;
    ITNode *right;

    ITNode(Interval *it, int max)
    {
        this->i = it;
        this->max = max;
        this->left = NULL;
        this->right = NULL;
    }
};

class IntervalTree
{
    bool isOverlapping(Interval *i1, Interval *i2)
    {
        if (i1->low < i2->high && i2->low < i1->high)
        {
            return true;
        }
        return false;
    }

public:
    // Insertion is done like BST all with low less will go in left and others in right
    ITNode *insert(ITNode *root, Interval *it)
    {
        if (!root)
        {
            root = new ITNode(it, INT_MIN);
            return root;
        }
        int low = root->i->low;
        if (it->low < low)
        {
            root->left = insert(root->left, it);
        }
        else
        {
            root->right = insert(root->right, it);
        }

        if (root->max < it->high)
        {
            root->max = it->high;
        }
        return root;
    }

    Interval *getOverlappingPair(ITNode *root, Interval *it)
    {
        if (!root)
            return NULL;

        if (isOverlapping(root->i, it))
        {
            return root->i;
        }

        if (root->left && root->left->max >= it->low)
        {
            // means here the overlapping pair will exist
            return getOverlappingPair(root->left, it);
        }
        return getOverlappingPair(root->right, it);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ITNode* root = NULL;
    IntervalTree tree;

    vector<pair<int,int>> vec = {{1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    Interval* it = new Interval(vec[0].first, vec[0].second);
    
    root = tree.insert(root, it);

    for(int i=1; i<vec.size(); i++){
        // first we search for a conflicting pair
        Interval* it = new Interval(vec[i].first, vec[i].second);
        Interval* ans = tree.getOverlappingPair(root, it);
        if(ans){
            cout<<"["<<it->low<<", "<<it->high<<"] "<<"Overlaps with: ["<<ans->low<<", "<<ans->high<<"]"<<"\n";
        } else {
            cout<<"["<<it->low<<", "<<it->high<<"] "<<"Overlaps with none"<<"\n";
        }
        root = tree.insert(root, it);
    }
    // get all overlapping pairs now


    return 0;
}