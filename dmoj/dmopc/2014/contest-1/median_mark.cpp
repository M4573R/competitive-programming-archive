#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int marks_count;
    cin >> marks_count;

    vector<unsigned int> marks(marks_count);

    for (auto& mark : marks)
    {
        cin >> mark;
    }

    sort(marks.begin(), marks.end());

    cout << (marks[marks_count / 2] + marks[(marks_count - 1) / 2] + 1) / 2
         << '\n';

    return 0;
}
