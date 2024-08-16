#include <bits/stdc++.h>
#define strong first
#define reward second

using namespace std;
typedef long long ll;
typedef pair < ll, ll > II;
typedef vector < II > VII;

ll n, S;
VII bosses;

bool rule(II x, II y);

int main()
{
    cin >> n >> S;

    ll p, q;
    for (ll i = 1; i <= n; i++)
    {
        cin >> p >> q;
        bosses.push_back({ p, q });
    }

    sort(bosses.begin(), bosses.end(), rule);
    /*
    for (ll i = 0; i < bosses.size(); i++)
    {
        cout << bosses[i].strong << " " << bosses[i].reward << endl;
    }
    */

    if (S < bosses[0].strong)
        cout << 0;
    else {
        ll c = 0;
        for (ll i = 0; i < bosses.size(); i++)
        {
            if (bosses[i].strong <= S) {
                S += bosses[i].reward;
                c += 1;
            }
            else break;
        }
        cout << c;
    }
    return 0;
}

bool rule(II x, II y)
{
    if (x.strong == y.strong)
        return x.reward >= y.reward;
    return x.strong < y.strong;
}
