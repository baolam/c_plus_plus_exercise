#include <bits/stdc++.h>

using namespace std;
typedef int ll;

const ll L = 4, M = 15;
string CODE = "0123456789ABCDEF";
bool stop = false;
int a[5];

void hien()
{
    for (int i = 1; i <= L; i++)
        cout << CODE[a[i]];
    cout << '\n';
    int vl = 0;
    for (int i = 1; i <= L; i++)
        vl = a[i] + (M + 1) * vl;
    if (vl == 20000)
        stop = true;
}

void tao(int L)
{
    a[L]++;
    if (a[L] > M)
    {
        a[L] = 0;
        if (L > 1)
            tao(L - 1);
    }
}

int main()
{
    memset(a, 0, sizeof(a));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (! stop)
    {
        tao(4);
        hien();
    }
    return 0;
}
