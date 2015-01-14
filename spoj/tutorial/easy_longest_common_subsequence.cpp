#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    string a;
    string b;

    cin >> a >> b;

    string::size_type n = a.size();
    string::size_type m = b.size();

    vector< vector<unsigned int> > computed(n + 1, vector<unsigned int>(m + 1));

    for (string::size_type i = 1; i <= n; ++i)
    {
        for (string::size_type j = 1; j <= m; ++j)
        {
            if (a[i - 1] == b[j - 1])
            {
                computed[i][j] = computed[i - 1][j - 1] + 1;
            }
            else
            {
                computed[i][j] = max(computed[i - 1][j], computed[i][j - 1]);
            }
        }
    }

    cout << computed[n][m] << '\n';

    return 0;
}
