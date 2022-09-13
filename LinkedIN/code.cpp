#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // i can make even odd but not odd even

    vector<int> vec = {4, 10, 10, 6, 2};

    vector<pair<int, int>> vecc;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] % 2 == vec[i + 1] % 2)
        {
            vecc.push_back({vec[i], vec[i + 1]});
            i++;
        }
    }
   
    return 0;
}