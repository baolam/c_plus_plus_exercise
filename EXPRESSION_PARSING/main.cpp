#include <bits/stdc++.h>
#define maxn 10000

using namespace std;
typedef long long ll;

string s;
stack<int> st, op;

bool is_operator(char x)
{
    return x == '+' || x == '-' || x == '*' || x == '/';
}

int get_prior(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return -1;
}

int process_op(char x)
{
    int l = st.top(); st.pop();
    int r = st.top(); st.pop();
    if (x == '+')
        st.push(l + r);
    else if (x == '-')
        st.push(l - r);
    else if (x == '*')
        st.push(l * r);
    else if (x == '/')
        st.push(l / r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("VAO.INP", "r", stdin);
    //freopen("RA.OUT", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        if (s[i] == '(')
            op.push('(');
        else if (s[i] == ')')
        {
            while (! op.empty() && op.top() != '(')
            {
                process_op(op.top());
                op.pop();
            }
            op.pop();
        }
        else if (is_operator(s[i]))
        {
            while (! op.empty() && get_prior(s[i]) <= get_prior(op.top()))
            {
                process_op(op.top());
                op.pop();
            }
            op.push(s[i]);
        }
        else {
            // Thuật toán tách số
            int number = 0;
            while (i < s.size() && isalnum(s[i]))
            {
                number = number * 10 + s[i] - '0';
                i++;
            }
            i--;
            //cout << number << ' ' << i << '\n';
            st.push(number);
        }
    }
    while (! op.empty())
    {
        process_op(op.top());
        op.pop();
    }
    cout << st.top();
    return 0;
}
