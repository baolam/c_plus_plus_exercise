#include <bits/stdc++.h>
#define N 1000002

using namespace std;
typedef long long ll;
typedef vector< ll > V;

V primes;
bool checked[N];
ll n, res = LONG_MIN;
ll a[N], f[N];

void erathoses();

int main()
{
    f[0] = 0;

    /// Nhập liệu
    /// Xây dựng mảng cộng dồn
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
        checked[i] = true;
    }

    /// Xây dựng số nguyên tố
    /// Tìm kết quả thỏa mãn
    erathoses();

    /// Test
    /***
    for (ll i = 0; i < primes.size(); i++)
        cout << primes[i] << ' ';
    cout << endl;
    ***/

    for (ll i = 2; i <= n; i++)
    {
        if (checked[i])
        {
            res = max(res, f[i]-f[i - 1]);
            for (ll j = 0; j < primes.size(); j++)
                res = max(res, f[i]-f[primes[j] - 1]);
            primes.push_back(i);
        }
    }

    cout << res;
    return 0;
}

void erathoses()
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (checked[i])
        {
            for (ll j = i * i; j <= n; j += i)
                checked[j] = false;
        }
    }
}
