#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

namespace SuffixArray
{
    const int MAXN = 1 << 21;
    int pos[MAXN], sa[MAXN], tmp[MAXN], lcp[MAXN];
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

    void buildLCP()
    {
        for (int i = 0, k = 0; i < N; i++)
        {
            if (pos[i] != N - 1)
            {
                for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k]; )
                    k++;
                lcp[pos[i]] = k;
                k = max(k - 1, 0);
            }
        }
    }

    void show()
    {
        for (int i = 0; i < N; i++)
            cout << sa[i] << ' ';
        cout << '\n';
        for (int i = 0; i < N - 1; i++)
            cout << lcp[i] << ' ';
        cout << '\n';
    }
};

using namespace SuffixArray;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> S;
    S += '#';
    buildSA();
    buildLCP();
    //show();
    ll sum = 0;
    for (int i = 1; i < N; i++)
        sum += (N - sa[i]) - lcp[i - 1] - 1;
    cout << sum;
    return 0;
}
