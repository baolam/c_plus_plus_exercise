#include <bits/stdc++.h>
#define maxn 16

using namespace std;
typedef long long ll;

ll n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> subset;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                subset.push_back(j);
        }
        for (int i = 0; i < subset.size(); i++)
            cout << subset[i] << ' ';
        cout << '\n';
    }
    return 0;
}
