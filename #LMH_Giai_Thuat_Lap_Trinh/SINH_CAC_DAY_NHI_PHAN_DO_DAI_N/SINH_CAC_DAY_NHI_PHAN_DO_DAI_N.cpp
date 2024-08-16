#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 30;
int a[MAXN];
int n;

int main()
{
    memset(a, 0, sizeof(a));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("BSTR.INP", "r", stdin);
    freopen("BSTR.OUT", "w", stdout);
    cin >> n;
    int i = n;
    do
    {
        for (int i = 1; i <= n; i++)
            cout << a[i];
        cout << '\n';
        i = n;
        while (i > 0 && a[i] == 1)
            i--;
        a[i] = 1;
        if (i > 0)
        {
            for (int j = i + 1; j <= n; j++)
                a[j] = 0;
        }
    } while (i != 0);
    return 0;
}
