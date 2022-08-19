// #include <bits/stdc++.h>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node *next;

//     node(int val)
//     {
//         data = val;
//         next = NULL;
//     }
// };

// void insertAtTail(node *&head, int val)
// {
//     node *n = new node(val);
//     if (head == NULL)
//     {
//         head = n;
//         return;
//     }

//     node *temp = head;

//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }

//     temp->next = n;
// }

// void deleteMAfterN(node *&head, int m, int n)
// {

//     node *temp = head;
//     int a, b;

//     while (temp != NULL)
//     {
//         a = m - 1;
//         while (a && temp != NULL)
//         {
//             temp = temp->next;
//             a--;
//         }

//         b = n;

//         while(b && temp != NULL)
//         {
//             node* toDelete = temp-> next;
//             if(temp-> next != NULL)
//             temp-> next = temp-> next-> next;
//             delete toDelete;
//             b--;
//         }

//         temp = temp-> next;
//     }
// }

// void display(node *&head)
// {
//     node *temp = head;

//     while (temp != NULL)
//     {
//         cout << temp->data << "->";
//         temp = temp->next;
//     }

//     cout << "NULL" << endl;
// }

// int main()
// {

//     node *head = NULL;
//     insertAtTail(head, 10);
//     insertAtTail(head, 20);
//     insertAtTail(head, 30);
//     insertAtTail(head, 40);
//     insertAtTail(head, 50);
//     insertAtTail(head, 60);
//     display(head);

//     // display(newHead);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int mnx = INT_MAX;
map<int, int> mp;
class node
{

public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool checker(node *root1, node *root2)
{
    if (!root1 && !root2)
    {
        return true;
    }

    if (!root1 || !root2)
    {
        return false;
    }

    if (root1->data == root2->data && checker(root1->left, root2->left) && checker(root1->right, root2->right))
    {
        return true;
    }
    else
        return false;

    // checker(root1-> left, root2-> left);
    // checker(root1-> right, root2-> right);

    // return false;
}

void mainq(node *root1, node *root2, bool &ans)
{
    if (root1 == NULL)
    {
        return;
    }

    if (root1->data == root2->data)
    {
        ans = checker(root1, root2);
        if (ans)
            return;
    }

    mainq(root1->left, root2, ans);
    mainq(root1->right, root2, ans);
}

// void tilt(node* root)
// {
//     if(root == NULL || (!root-> right && !root-> left))
//     return;

// }

int main()
{

    // node *root = new node(4);
    // root->right = new node(9);
    // root->left = new node(2);
    // root->right->right = new node(7);
    // root->right->left = new node(3);
    // root->left->left = new node(3);
    // root->left->right = new node(5);
    // root-> left-> right-> left = new node(13);

    // node* ans = ques(root);
    // cout<<ans->right-> data<<endl;

    // tilt(root, 0);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" ";
    // }

    // cout<<v.size()<<endl;

    // node* newRoot = myInvert(root);
    // cout << newRoot->left->data << " ";

    // cout<<sumReplace(root)<<endl;

    node *root1 = new node(3);
    root1->left = new node(4);
    root1->right = new node(5);
    root1->left->left = new node(1);
    root1->left->right = new node(2);

    node *root2 = new node(4);
    root2->left = new node(1);
    root2->right = new node(2);

    //   mainq(root1, root2);

    bool ans = false;
    mainq(root1, root2, ans);

    if (ans)
    {
        cout << "YES"
             << "\n";
    }
    else
        cout << "NO"
             << "\n";

    return 0;
}