/// Cho n xâu s[i], mỗi chuỗi không dài quá m kí tự. Tìm và phân loại các chuỗi bị lặp

#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int, int> II;

const int M = 1e9 + 9;
const int p = 31;

int n;
vector<string> s;

int compute_hash(string x)
{
    int hash_value = 0;
    int p_temp = 1;
    for (int i = 0; i < x.size(); i++)
    {
        hash_value += (x[i] - 'a' + 1) * p_temp % M;
        p_temp *= p % M;
    }
    return hash_value;
}

int group()
{
    vector<II> tmp;
    for (int i = 0; i < s.size(); i++)
        tmp.push_back({compute_hash(s[i]), i});
    sort(tmp.begin(), tmp.end());
    int cnt = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (i == 0 || tmp[i].x != tmp[i - 1].x)
            cnt++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    //freopen("RA.OUT", "w", stdout);
    cin >> n;
    string tmp;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        s.push_back(tmp);
    }
    cout << group();
    return 0;
}
