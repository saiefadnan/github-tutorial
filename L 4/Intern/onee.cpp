#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    int x, y, z;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, count=0;
        int y;
        cin >> x;

        for (int j = 1; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                if (j * j == x)
                {
                    count++;
                }
                else
                {
                    count += 2;
                }
            }
        }
        // It's a change 

        cout << count << endl;
    }

    return 0;
}