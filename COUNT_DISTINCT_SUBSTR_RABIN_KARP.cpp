#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 9;
const int D = 256;

int cnt = 0;
unordered_map<ll, ll> d;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("VAO.INP", "r", stdin);
    //freopen("RA.OUT", "w", stdout);
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        int suma = 0;
        int prev = 0;

        for (int j = i; j < s.size(); j++)
        {
            prev = (prev * D + s[j]) % MOD;
            if (d.find(prev) == d.end())
                cnt++;
            d[prev] = 1;
        }
    }

    cout << cnt;
    return 0;
}
