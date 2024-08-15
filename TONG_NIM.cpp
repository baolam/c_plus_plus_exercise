#include <bits/stdc++.h>
#define maxn 10

using namespace std;
typedef long long ll;

int g[maxn][maxn], c[101];

int main()
{
    memset(g, 0, sizeof(g));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i <= 9; i++)
        g[i][0] = i, g[0][i] = i;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            memset(c, 0, sizeof(c));
            for (int k = 0; k <= i - 1; k++)
                c[g[k][j]] = 1;
            for (int k = 0; k <= j - 1; k++)
                c[g[i][k]] = 1;
            int k = 0;
            while(c[k] == 1)
            {
                k++;
            }
            g[i][j] = k;
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
            cout << g[i][j] << "    ";
        cout << '\n';
    }
    return 0;
}
