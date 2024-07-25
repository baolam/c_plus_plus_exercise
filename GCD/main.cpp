#include <bits/stdc++.h>
#define N 52

using namespace std;
typedef long long ll;

ll n, res = LONG_MAX;
ll a[N], cfg[N];
vector<ll> primes;

bool cprime(ll x);
void bprimes();
void ql(ll i);
ll mprime(ll x);
ll handling();

int main()
{
    bprimes();

    /**
    for (ll i = 0; i < primes.size(); i++)
        cout << primes[i] << ' ';
    cout << endl;
    */

    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];

    ql(0);
    cout << res;
    return 0;
}

void bprimes()
{
    for (ll i = 2; i <= 50; i++)
    {
        if (cprime(i))
            primes.push_back(i);
    }
}

bool cprime(ll x)
{
    if (x == 2)
        return true;
    for (ll j = 2; j <= sqrt(x); j++)
    {
        if (x % j == 0)
            return false;
    }
    return true;
}

void ql(ll i)
{
    for (ll j = 0; j <= 1; j++)
    {
        cfg[i] = j;
        if (i == primes.size() - 1)
        {
            ll r = handling();
            if (r != -1)
                res = min(res, r);
        } else ql(i + 1);
    }
}

ll handling()
{
    ll k = 1;
    for (ll i = 0; i < primes.size(); i++)
        k += primes[i] * cfg[i];
    for (ll i = 1; i <= n; i++)
    {
        if (__gcd(a[i], k) == 1)
            return -1;
    }
    return k;
}
