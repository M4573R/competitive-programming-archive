#include <algorithm>
#include <iostream>
#include <vector>

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

    unsigned int subjects;
    unsigned int learning_time;

    cin >> subjects >> learning_time;

    vector<unsigned int> chapters(subjects);

    for (auto& count : chapters)
    {
        cin >> count;
    }

    sort(chapters.begin(), chapters.end());

    unsigned long long min_time {0};

    for (auto count : chapters)
    {
        min_time      += static_cast<unsigned long long>(count) * learning_time;
        learning_time  = max(1u, learning_time - 1);
    }

    cout << min_time << '\n';

    return 0;
}
