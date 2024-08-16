#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

namespace SuffixArray
{
    const int MAXN = 1 << 21;
    int pos[MAXN], tmp[MAXN], sa[MAXN];
    int gap, N;
    string S;

    bool suffCmp(int i, int j)
    {
        if (pos[i] != pos[j])
            return pos[i] < pos[j];
        i += gap; j += gap;
        return (i < N && j < N) ? pos[i] < pos[j] : i > j;
    }

    void buildSA()
    {
        N = S.size();
        for (int i = 0; i < N; i++)
            sa[i] = i, pos[i] = S[i];
        for (gap = 1 ;; gap *= 2)
        {
            sort(sa, sa+N, suffCmp);
            for (int i = 0; i < N - 1; i++)
                tmp[i + 1] = tmp[i] + suffCmp(sa[i], sa[i + 1]);
            for (int i = 0; i < N; i++)
                pos[sa[i]] = tmp[i];
            if (tmp[N - 1] == N - 1)
                break;
        }
    }
};

using namespace SuffixArray;
int t;
string p;

int matching(int m)
{
    // Compare between p and s
    // s < p --> return -1
    // p = s --> return 0
    // s > p --> return 1
    for (int i = 0; i < p.size(); i++)
    {
        if (S[(sa[m] + i) % N] < p[i])
            return -1;
        else if (S[(sa[m] + i) % N] > p[i])
            return 1;
    }
    return 0;
}

int firstAboveorEqual()
{
    // Min i: a[i] >= x --> belong to r
    // Try to maintain: a[l] < x && a[r] >= x <--> s < p && s >= p
    int l = -1, r = N;
    while (l < r - 1)
    {
        int m = (l + r) / 2;
        if (matching(m) == -1) l = m;
        else r = m;
    }
    return r;
}

int lastLessOrEqual()
{
    // Max i: a[i] <= x --> belong to l
    // Try to maintain: a[l] <= x && a[r] > x <--> s <= p && s > p
    int l = -1, r = N;
    while (l < r - 1)
    {
        int m = (l + r) / 2;
        if (matching(m) == -1 || matching(m) == 0)
            l = m;
        else r = m;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("VAO.INP", "r", stdin);
    //freopen("RA.OUT", "w", stdout);
    cin >> S;
    S += '#';
    buildSA();
    //for (int i = 0; i < N; i++)
        //cout << sa[i] << ' ' << S.substr(sa[i], N) << '\n';
    cin >> t;
    while (t)
    {
        cin >> p;
        int cd = firstAboveorEqual();
        int ct = lastLessOrEqual();
        if (ct < cd)
            cout << 0 << '\n';
        else cout << ct - cd + 1 << '\n';
        t--;
    }
    return 0;
}
