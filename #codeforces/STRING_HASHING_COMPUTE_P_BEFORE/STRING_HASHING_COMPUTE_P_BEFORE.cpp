#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int M = 1e9 + 9;
const int P = 31;
const int N = 1e6;

int n, m;
int p[N], p_inverse[N];

int hashFunc(string x)
{
    int hash_vl = 0;
    for (int i = 0; i < x.size(); i++)
    {
        hash_vl += (x[i] - 'a' + 1) * p[i];
        hash_vl %= m;
    }
    return hash_vl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    p[0] = 1;
    for (int i = 1; i < n; i++)
        p[i] = (p[i - 1] * P) % M;
    return 0;
}
