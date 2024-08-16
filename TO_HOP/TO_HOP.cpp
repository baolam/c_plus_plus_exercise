#include <bits/stdc++.h>
#define maxn 1003

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
int n, k;
int f[maxn][maxn];

int combine(int n, int k)
{
    if (n == k || k == 0) return 0;
    if (k > n) return 0;
    if (f[n][k] != -1) return f[n][k];
    f[n][k] = (combine(n-1, k-1) + combine(n-1, k)) % MOD;
    return f[n][k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(f, -1, sizeof(f));

    int t;
    cin >> t;
    while(t--)
    {
        int x1, x2;
        cin >> x1 >> x2;
        cout << combine(x1, x2) << '\n';
    }
    return 0;
}
