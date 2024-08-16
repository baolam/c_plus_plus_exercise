#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll j = 0; j < m; j++) cin >> b[j];

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            i++;
        else {
            cout << i << ' ';
            ++j;
        }
    }

    while (j < m)
    {
        cout << i << ' ';
        ++j;
    }
    return 0;
}
