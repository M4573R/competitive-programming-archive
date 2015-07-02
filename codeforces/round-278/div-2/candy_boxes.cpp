#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline void solve_with_four_left_boxes(const vector<unsigned int>& boxes)
{
    if ((3 * boxes[0] == boxes[3]) && (boxes[1] + boxes[2] == 4 * boxes[0]))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

inline void solve_with_three_left_boxes(const vector<unsigned int>& boxes)
{
    unsigned int missing_box;

    if (3 * boxes[0] == boxes[2])
    {
        missing_box = 4 * boxes[0] - boxes[1];
    }
    else if (boxes[1] + boxes[2] == 4 * boxes[0])
    {
        missing_box = 3 * boxes[0];
    }
    else if (4 * boxes[2] == 3 * (boxes[0] + boxes[1]))
    {
        missing_box = boxes[2] / 3;
    }
    else
    {
        cout << "NO\n";
        return;
    }

    cout << "YES"       << '\n'
         << missing_box << '\n';
}

inline void solve_with_two_left_boxes(const vector<unsigned int>& boxes)
{
    if (boxes[1] <= 3 * boxes[0])
    {
        cout << "YES"                   << '\n'
             << 4 * boxes[0] - boxes[1] << '\n'
             << 3 * boxes[0]            << '\n';
    }
    else
    {
        cout << "NO\n";
    }
}

inline void solve_with_one_left_box(const vector<unsigned int>& boxes)
{
    cout << "YES"        << '\n'
         << boxes[0]     << '\n'
         << 3 * boxes[0] << '\n'
         << 3 * boxes[0] << '\n';
}

inline void solve_with_zero_left_boxes(const vector<unsigned int>& boxes)
{
    cout << "YES" << '\n'
         << 1     << '\n'
         << 1     << '\n'
         << 3     << '\n'
         << 3     << '\n';
}

int main()
{
    use_io_optimizations();

    unsigned int left_boxes;
    cin >> left_boxes;

    vector<unsigned int> boxes(4);

    for (unsigned int i {0}; i < left_boxes; ++i)
    {
        cin >> boxes[i];
    }

    sort(boxes.begin(), boxes.begin() + left_boxes);

    switch (left_boxes)
    {
    case 4:
        solve_with_four_left_boxes(boxes);
        break;

    case 3:
        solve_with_three_left_boxes(boxes);
        break;

    case 2:
        solve_with_two_left_boxes(boxes);
        break;

    case 1:
        solve_with_one_left_box(boxes);
        break;

    case 0:
        solve_with_zero_left_boxes(boxes);
        break;
    }

    return 0;
}
