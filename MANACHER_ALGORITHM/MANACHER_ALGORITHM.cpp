#include <bits/stdc++.h>

using namespace std;
typedef int ll;

string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    //freopen("RA.OUT", "w", stdout);
    cin >> s;
    string tmp = "$";
    for (int i = 0; i < s.size(); i++)
    {
        tmp += '#';
        tmp += s[i];
    }
    tmp += '@';
    /// Cài đặt thuật toán manacher
    vector<int> p(tmp.size());
    int maxRight = 0;
    int center = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (i < maxRight)
            p[i] = min(maxRight - i, p[2 * center - i]);
        while (tmp[i - p[i] - 1] == tmp[i + p[i] + 1])
            p[i]++;
        if (i + p[i] > maxRight)
        {
            maxRight = i + p[i];
            center = i;
        }
    }
    return 0;
}
