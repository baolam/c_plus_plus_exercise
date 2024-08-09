#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 3;
int tmp[MAXN], pos[MAXN], sa[MAXN], lcp[MAXN];
int gap, N;
int n;
string S, s, p;

bool sufCmp(int i, int j)
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
        sort(sa, sa+N, sufCmp);
        for (int i = 0; i < N - 1; i++)
            tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
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

int belongTo(int x)
{
    return 0 <= x && x < n ? 1 : 2;
}

void showDetailSuffix()
{
    for (int i = 0; i < N; i++)
        cout << lcp[i] << ' ' << belongTo(sa[i]) << ' ' << S.substr(sa[i], N) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s >> p;
    n = s.size();
    S = s + '#' + p;
    buildSA();
    buildLCP();
    showDetailSuffix();
    /*
    int ans = 0, st = 0;
    for (int i = 1; i < N; i++)
    {
        if (belongTo(sa[i]) != belongTo(sa[i - 1]) && ans < lcp[i])
            ans = lcp[i], st = sa[i];
    }
    cout << S.substr(st, ans);
    */
    return 0;
}
