#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

ll p[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
ll somu[10];
ll n, res = LONG_LONG_MAX;
ll inf = LONG_LONG_MAX;

ll _pow(ll sm, ll nums)
{
    ll x = 1;
    for (ll i = 1; i <= nums; i++)
    {
        x *= sm;
        if (x > inf)
            return inf;
    }
    return x;
}

/**
void ql(ll pos, ll z)
{
    for (ll i = 2; i <= z; i++)
    {
        if (z % i == 0)
        {
            somu[pos] = i - 1;
            z /= i;
            if (z == 1)
            {
                /// Hoàn thành một bộ số mũ
                ll k = 1;
                /**
                for (ll j = 0; j <= 9; j++)
                {
                    cout << '(' << p[j] << ',' << somu[j] << ')' << '\n';
                }
                cout << endl;
                /
                for (ll j = 0; j <= 9; j++)
                {
                    if (somu[j] != 0)
                        k *= pow(p[j], somu[j]);
                    cout << k << ' ' << res << endl;
                    if (k > res)
                        break;
                }
                res = min(res, k);

            } else ql(pos + 1, z);
            z *= i;
            somu[pos] = 0;
        }
    }
}
*/

void ql(ll pos, ll z, ll m)
{
    for (ll i = 2; i <= z; i++)
    {
        if (z % i == 0)
        {
            ll temp = _pow(p[pos], i - 1);
            if (temp >= res) break;
            m *= temp;
            //m *= pow(p[pos], i - 1);

            if (m >= res)
                break;
            z /= i;
            if (z == 1) res = m;
            else ql(pos + 1, z, m);
            z *= i;
            m /= temp;
            //m /= pow(p[pos], i - 1);
        }
    }
}

int main()
{
    for (ll i = 0; i <= 9; i++) somu[i] = 0;

    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    ql(0, n, 1);

    cout << res << '\n';
    return 0;
}
