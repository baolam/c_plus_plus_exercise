#include <bits/stdc++.h>
#define N 1000002

using namespace std;
typedef long long ll;
string text, pattern;

ll f[N];

void build(string pattern)
{
    f[0] = -1;
    for (ll i = 1; i < pattern.size(); i++)
    {
        ll j = f[i - 1];
        while(true)
        {
            if (pattern[i] == pattern[j+1])
            {
                f[i] = j + 1;
                break;
            }
            if (j < 0) {
                f[i] = -1;
                break;
            }
            j = f[j];
        }
    }
}

void kmp(string text, string pattern)
{
    int i = 0, j = -1;
    while(true)
    {
        if (i == text.size())
            return;
        if (text[i] == pattern[j + 1])
        {
            i++; j++;
            if (j >= pattern.size() - 1)
            {
                cout << i + 1 - pattern.size() << ' ';
                j = f[j];
            }
        }
        else if (j >= 0) j = f[j];
        else i++;
    }
}

int main()
{
    cin >> text >> pattern;
    build(pattern);
    kmp(text, pattern);
    return 0;
}
