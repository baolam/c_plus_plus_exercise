#include <bits/stdc++.h>
#define maxn 1000001

using namespace std;
//typedef long long ll;

struct Value {
    int st; int en;
    //int area;
};

int n;
int cs[maxn];
Value a[maxn];

bool Compare(Value x, Value y)
{
    if (x.st == y.st)
        return x.en <= y.en;
    return x.st > y.st;
}

bool isIn(Value x, Value y)
{
    /// y nằm trong x
    return y.st >= x.st && y.en <= x.en;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    freopen("RA.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].st >> a[i].en;
        //a[i].area = a[i].en - a[i].st;
    }
    sort(a+1, a+1+n, Compare);
    int k = 1;
    cs[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!isIn(a[i], a[cs[1]]))
            cs[1] = i;
        else
        {
            if (isIn(a[i], a[cs[k]]))
            {
                k++;
                cs[k] = i;
            }
            else
            {
                int l = 1, r = k;
                while (l < r)
                {
                    int m = l + (r - l) / 2;
                    if (isIn(a[i], a[cs[m]]))
                        l = m + 1;
                    else r = m;
                }
                cs[l] = i;
            }
        }
    }
    cout << k << '\n';
    for (int i = 1; i <= k; i++)
    {
        cout << a[cs[i]].st << ',' << a[cs[i]].en << '\n';
    }
    return 0;
}
