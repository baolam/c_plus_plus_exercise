#include <bits/stdc++.h>
#define maxn 1000002

using namespace std;
typedef long long ll;

int n, a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int votes = 0, candiate = -1;
    for (int i = 1; i <= n; i++)
    {
        if (votes == 0)
        {
            candiate = a[i];
            votes = 1;
        }
        else if (candiate == a[i])
            votes++;
        else votes--;
    }

    /// Vòng lặp còn lại để kiểm tra
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (candiate == a[i]) c++;
    }

    if (c >= n / 2)
        cout << candiate;
    else cout << "NOT FOUND!";
    return 0;
}
