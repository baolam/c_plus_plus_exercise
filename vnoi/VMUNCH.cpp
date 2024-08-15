#include <bits/stdc++.h>
#define x first
#define y second
#define maxR 102
#define maxC 102

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int X[4] = {-1, 1, 0, 0};
const int Y[4] = {0, 0, -1, 1};

int R, C;
int ans = 0;
int matrix[maxR][maxC];
ii bessie;

bool check(int u, int v)
{
    return ! ((u < 1 || u > R) || (v < 1 || v > C));
}

void dfs(int u, int v, int pos)
{
    /// u là hàng, v là cột
    /// pos là vị trí

    if (u < 1 || u > R) return;
    if (v < 1 || v > C) return;
    if (matrix[u][v] == 1) return;
    if (matrix[u][v] == 2)
    {
        ans = max(ans, pos);
        return;
    }

    cout << u << ' ' << v << '\n';

    matrix[u][v] = 1;
    for (int _i = 0; _i < 4; _i++)
    {
        for (int _j = 0; _j < 4; _j++)
        {
            int i = X[_i] + u;
            int j = Y[_j] + v;
            //cout << i << ' ' << j << '\n';
            dfs(i, j, pos+1);
        }
    }
    //matrix[u][v] = 0;
 }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(matrix, 0, sizeof(matrix));

    /// Qui ước: 0 tượng trưng cho cỏ
    /// Qui ước: 1 tượng trưng cho đá
    /// Qui ước: 2 tượng trưng cho hai tọa độ mục tiêu

    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        char x;
        for (int j = 1; j <= C; j++)
        {
            cin >> x;
            if (x == '*') matrix[i][j] = 1;
            else if (x == 'B') matrix[i][j] = 2;
            else if (x == 'C') bessie.x = i, bessie.y = j, matrix[i][j] = 0;
        }
    }

    dfs(bessie.x, bessie.y, 1);

    cout << ans;
    return 0;
}
