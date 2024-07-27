#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t, n;

int solve()
{
    int sum = 0, optim_x = 0;
    for (int x = 2; x <= n; x++)
    {
        int k = n / x;
        int tmp = x * k * (k + 1) / 2;
        if (sum < tmp)
        {
            sum = tmp;
            optim_x = x;
        }
    }
    return optim_x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t)
    {
        cin >> n;
        cout << solve() << '\n';
        t--;
    }
    return 0;
}
