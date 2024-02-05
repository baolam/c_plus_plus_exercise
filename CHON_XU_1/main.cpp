/// Lời giải chọn xu 2

#include <bits/stdc++.h>
#define maxn 102
#define maxa 1000006

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
int a[maxa];
int f[maxa], n, S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> S;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[0] = 1;
    for (int s = 0; s <= S; s++)
    {
        for (int i = 1; i <= n; i++)
        {
            //f[i][s] = f[i-1][s];
            if (s >= a[i])
                f[s] = (f[s] + f[s - a[i]) % MOD;
        }
    }
    cout << f[S];
    return 0;
}
