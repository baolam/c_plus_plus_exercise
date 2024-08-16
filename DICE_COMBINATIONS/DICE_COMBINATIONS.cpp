#include <bits/stdc++.h>
#define MOD 1000000007
#define maxn 1000006

using namespace std;
typedef long long ll;
int f[maxn], n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    f[0] = 1;
    for (int s = 1; s <= n; ++s)
    {
        for (int j = 1; j <= 6; ++j)
        {
            if (j <= s)
                f[s] = (f[s] + f[s - j]) % MOD;
        }
    }

    cout << f[n];
    return 0;
}
