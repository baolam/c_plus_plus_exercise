#include <bits/stdc++.h>
#define N 52

using namespace std;
typedef long long ll;

vector<ll> primes;
vector<ll> solutions;
ll n, res = LONG_MAX;
ll a[N], cfg[N];

bool _checked[N];
bool cprime(ll x);
bool checked(ll x);
void analyze(ll x);
void ql(ll i);

/// Xây dựng chiến lược tìm x
int main()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 2; i <= 50; i++) {
        _checked[i] = false;
        cfg[i] = 0;
        if (cprime(i)) primes.push_back(i);
    }
    /// Xây dựng danh sách số nguyên tố
    for (ll i = 1; i <= n; i++)
        analyze(a[i]);
    /*
    for (ll i = 0; i < solutions.size(); i++)
        cout << solutions[i] << ' ';
    cout << endl;
    */
    ql(0);
    cout << res;
    return 0;
}

bool checked(ll x)
{
    for (ll i = 1; i <= n; i++)
    {
        if (__gcd(a[i], x) == 1)
            return false;
    }
    return true;
}

bool cprime(ll x)
{
    if (x == 2) return true;
    for (ll j = 2; j <= sqrt(x); j++)
    {
        if (x % j == 0)
            return false;
    }
    return true;
}

void analyze(ll x)
{
    ll i = 0;
    while (x != 1)
    {
        if (x % primes[i] == 0)
        {
            if (_checked[primes[i]] == false)
            {
                _checked[primes[i]] = true;
                solutions.push_back(primes[i]);
            }
            x /= primes[i];
        } else i++;
    }
}

void ql(ll i)
{
    for (ll j = 0; j <= 1; j++)
    {
        cfg[i] = j;
        if (i == solutions.size() - 1)
        {
            ll x = 1;
            for (ll _k = 0; _k <= i; _k++) {
                if (cfg[_k] == 1) x *= solutions[_k];
            }
            //cout << x << endl;
            if (x != 1 && checked(x)) res = min(res, x);
        } else ql(i + 1);
    }
}
