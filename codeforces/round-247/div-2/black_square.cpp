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

    vector<unsigned int> calories(4);

    for (auto& calories_per_strip : calories)
    {
        cin >> calories_per_strip;
    }

    string game;
    cin >> game;

    unsigned int total_calories {0};

    for (auto strip : game)
    {
        total_calories += calories[strip - '1'];
    }

    cout << total_calories << '\n';

    return 0;
}
