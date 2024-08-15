# Dãy số fibonaci
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll c = 0, f[100];

int fibo(ll n)
{
    if (n <= 1)
        return 1;
    if (f[n] != -1)
        return f[n];
    f[n] = fibo(n - 1) + fibo(n - 2);
    ++c;
    return f[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(f, -1, sizeof(f));

    cout << fibo(25) << ' ' << c;
    return 0;
}
