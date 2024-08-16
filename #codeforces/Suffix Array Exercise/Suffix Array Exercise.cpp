#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<char, int> II;
typedef pair < pair < int, int >, int > _II;

const int N = 1e5 + 3;
int p[N], c[N];
II a[N];
_II b[N];
string s;

bool _check(int i, bool initalize)
{
    if (initalize)
        return a[i].x == a[i - 1].x;
    return b[i].x == b[i - 1].x;
}

void update(bool initalize)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (initalize)  p[i] = a[i].y;
        else p[i] = b[i].y;
    }
    c[p[0]] = 0;
    for (int i = 1; i < s.size(); i++) {
        if (_check(i, initalize))
            c[p[i]] = c[p[i - 1]];
        else c[p[i]] = c[p[i - 1]] + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    s += '$';
    for (int i = 0; i < s.size(); i++) {
        a[i] = { s[i], i };
    }
    sort(a.begin(), a.end());
    update(true);

    int k = 1;
    while ((1 << k) < n)
    {
        for (int i = 0; i < s.size(); i++) {
            b[i] = {  }
        }
        k++;
    }
    return 0;
}
