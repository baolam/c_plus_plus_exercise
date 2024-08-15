#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

namespace SuffixArray
{
    const int MAXN = 1 << 21;
    string S;
    int N, gap;
    int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

    bool sufCmp(int i, int j)
    {
        if (pos[i] != pos[j])
            return pos[i] < pos[j];
        i += gap; j += gap;
        return (i < N && j < N) ? pos[i] < pos[j] : i > j;
    }

    void buildSA()
    {
        memset(tmp, 0, sizeof(tmp));
        S += '#';
        N = S.size();
        for (int i = 0; i < N; i++)
            sa[i] = i, pos[i] = S[i];
        for (gap = 1 ;; gap *= 2)
        {
            sort(sa, sa+N, sufCmp);
            for (int i = 0; i < N - 1; i++)
                tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
            for (int i = 0; i < N; i++)
                pos[sa[i]] = tmp[i];
            if (tmp[N - 1] == N - 1)
                break;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> SuffixArray::S;
    SuffixArray::buildSA();
    for (int i = 0; i < SuffixArray::N; i++)
        cout << SuffixArray::sa[i] << ' ';
    return 0;
}
