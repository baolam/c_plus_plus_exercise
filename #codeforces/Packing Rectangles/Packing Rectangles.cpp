#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int w, h, n;

bool f(int x)
{
    int tmpw = x / w;
    int tmph = x / h;
    return tmpw * tmph >= n;
}

int searchR()
{
    int r = 1;
    while (!f(r))
        r *= 2;
    return r;
}

int bSearch()
{
    int l = 1;
    int r = searchR();
    while (l < r - 1)
    {
        int m = (l + r) / 2;
        if (!f(m))
            l = m;
        else
            r = m;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> w >> h >> n;
    cout << bSearch() << '\n';
    return 0;
}
