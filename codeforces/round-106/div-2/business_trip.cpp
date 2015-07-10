#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    int lower_limit;
    cin >> lower_limit;

    vector<int> growth(12);

    for (int i {0}; i < 12; ++i)
    {
        cin >> growth[i];
    }

    sort(growth.begin(), growth.end(), greater<int>());

    int months {0};
    int height {0};

    for (int i {0}; i < 12 && height < lower_limit; ++i)
    {
        months += 1;
        height += growth[i];
    }

    cout << (height < lower_limit ? -1 : months) << '\n';

    return 0;
}
