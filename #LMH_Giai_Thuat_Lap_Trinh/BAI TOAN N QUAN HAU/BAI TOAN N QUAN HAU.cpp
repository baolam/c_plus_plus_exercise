#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 12;
int n;
int x[MAXN];
bool d[MAXN], db_tn[2 * MAXN - 2 + 1]; // Cột dọc
unordered_map<int, bool> tb_dn;

void Print()
{
    for (int i = 1; i <= n; i++)
        cout << '(' << i << ',' << x[i] << ')' << ' ';
    cout << '\n';
}

void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (d[j] && tb_dn[i - j] && db_tn[i + j])
        {
            x[i] = j;
            if (i == n) Print();
            else
            {
                d[j] = false; tb_dn[i - j] = false; db_tn[i + j] = false;
                Try(i + 1);
                d[j] = true; tb_dn[i - j] = true; db_tn[i + j] = true;
            }
        }
    }
}

int main()
{
    memset(d, true, sizeof(d));
    memset(db_tn, true, sizeof(db_tn));
    for (int i = 1 - MAXN; i <= MAXN - 1; i++)
        tb_dn[i] = true;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("QUEENS.INP", "r", stdin);
    freopen("QUEENS.OUT", "w", stdout);
    cin >> n;
    Try(1);
    return 0;
}
