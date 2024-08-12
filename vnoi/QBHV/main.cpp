#include <bits/stdc++.h>
#define N 10

using namespace std;
typedef long long ll;

ll pos[N];
char char_code[N];
bool ticked[N];

void permute(ll i);

string s, prev_str;
vector<string> res;
int main()
{
    prev_str = "";
    cin >> s;
    prev_str = s;
    for (int i = 0; i < s.length(); i++)
        char_code[i + 1] = s[i];
    for (int i = 1; i <= s.length(); i++)
        pos[i] = i;
    permute(1);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\n';
    return 0;
}

void permute(ll i)
{
    for (int j = 1; j <= s.length(); j++)
    {
        if (! ticked[j])
        {
            ticked[j] = true;
            pos[i] = j;
            if (i == s.length())
            {
                // Handle
                // Test
                string c = "";
                for (int k = 1; k <= i; k++)
                    c += char_code[pos[k]];
                res.push_back(c);

            } else permute(i + 1);
            ticked[j] = false;
        }
    }
}
