#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 30;
int n;
int t[MAXN], x[MAXN];

void Print(int k)
{
    for (int i = 1; i <= k; i++)
        cout << x[i] << ' ';
    cout << '\n';
}

void Try(int i)
{
    for (int j = x[i - 1]; j <= (n - t[i - 1]) / 2; j++)
    {
        x[i] = j;
        t[i] = t[i - 1] + j;
        Try(i + 1);
    }
    x[i] = n - t[i - 1];
    Print(i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("ANALYSE.INP", "r", stdin);
    freopen("ANALYSE.OUT", "w", stdout);
    cin >> n;
    t[0] = 0; x[0] = 1;
    Try(1);
    return 0;
}
