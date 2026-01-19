#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;

    int x;
    int count = 0;
    for (int j = 1; j * j <= n; j++)
    {
        }
    sort(a.begin(), a.end());
    if (k > a.size())
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << a[k - 1] << endl;
    }

    return 0;
}