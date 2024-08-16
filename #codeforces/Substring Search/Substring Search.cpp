#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

namespace SuffixArray {
    const int MAXN = 1 << 21;
    string S;
    int pos[MAXN], sa[MAXN], tmp[MAXN];
    int gap, N;

    bool suffCmp(int i, int j)
    {
        if (pos[i] != pos[j])
            return pos[i] < pos[j];
        i += gap; j += gap;
        return i < N && j < N ? pos[i] < pos[j] : i > j;
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
            if (tmp[N - 1] == N - 1) break;
        }
    }
};

using namespace SuffixArray;
int n;
string p;

int matching(int m)
{
    for (int i = 0; i < p.size(); i++)
    {
        if (S[(sa[m] + i) % N] < p[i])
            return 0;
        if (S[(sa[m] + i) % N] > p[i])
            return 2;
    }
    return 1;
}

void solve()
{
    cin >> p;
    int l = 0, r = N - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int code = matching(m);
        if (code == 1)
        {
            cout << "Yes" << '\n';
            return;
        }
        if (code == 0)
            l = m + 1;
        else r = m - 1;
    }
    cout << "No" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> S;
    S += '#';
    buildSA();
    cin >> n;
    while (n)
    {
        solve();
        n--;
    }
    return 0;
}
