#include <bits/stdc++.h>
using namespace std;

vector<int> left(int n, vector<int> &vec)
{

    vector<int> ans;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && vec[st.top()] >= vec[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(st.top() + 1);
        }
        st.push(i);
    }
    return ans;
}
vector<int> right(int n, vector<int> &vec)
{
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && vec[st.top()] >= vec[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = n - 1;
        }
        else
        {
            ans[i] = (st.top() - 1);
        }
        st.push(i);
    }
    return ans;
}
int solve(int n, vector<int> vec)
{
    vector<int> sl = left(n, vec);
    vector<int> sr = right(n, vec);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int calci = (sr[i] - sl[i] + 1) * vec[i];
        ans = max(ans, calci);
    }
    return ans;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> vec(m, 0);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                vec[j] += 1;
            }
            else
            {
                vec[j] = 0;
            }
        }
        ans = max(ans, solve(m, vec));
    }
    return ans;
}