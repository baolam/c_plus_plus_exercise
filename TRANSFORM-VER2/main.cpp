#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll q;
ll a, b;

bool check(ll x);

/***
    Chiến lược tiếp cận dựa vào b
**/
int main()
{
    cin >> q;
    for (ll i = 1; i <= q; i++)
    {
        cin >> a >> b;
        if (a > b)
            cout << "NO" << '\n';
        else {
            if (check(b))
                cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}

bool check(ll x)
{
    if (x == a)
        return true;
    if (x < a)
        return false;
    if (x % 2 == 0)
    {
        return check(x / 2);
    } else if (x % 10 == 1)
        return check(x / 10);
    return false;
}

/**
bool check_depend_stack(ll x)
{
    stack < ll > s;
    s.push(x);
    while(true)
    {
        ll k = s.top();
        if (k == a)
            return true;

    }
}
**/
