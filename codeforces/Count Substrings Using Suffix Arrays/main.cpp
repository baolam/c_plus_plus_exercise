#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

namespace SuffixArray {
    const int MAXN = 1 << 21;
    int pos[MAXN], sa[MAXN], tmp[MAXN];
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

    void testSA()
    {
        for (int i = 0; i < N; i++)
            cout << sa[i] << ' ';
        cout << '\n';
    }
};

using namespace SuffixArray;
int t;
string p;

int matching(int m)
{
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] < S[(sa[m] + i) % N]) // p < S
            return -1;
        if (p[i] > S[(sa[m] + i) % N]) // p > S
            return 1;
    }
    return 0;
}

int leftest()
{
    int l = 0, r = N - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int code = matching(m);
        if ((m == 0 || matching(m - 1) == 1) && code == 0)
            return m;
        if (code == -1) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int rightest()
{
    int l = 0, r = N - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int code = matching(m);
        if ((m == N - 1 || matching(m + 1) == -1) && code == 0)
            return m;
        if (code == -1) l = m + 1;
        else r = m - 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> S;
    buildSA();
    cin >> t;
    while (t)
    {
        cin >> p;
        cout << leftest() << ' ' << rightest() << '\n';
        t--;
    }
    return 0;
}
