#include <iostream>
#include <stack>
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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int ingredients;
        cin >> ingredients;

        vector<unsigned int> cars(ingredients);

        for (auto& car : cars)
        {
            cin >> car;
        }

        unsigned int next_car {1};
        stack<unsigned int> branch;

        for (auto car = cars.crbegin(); car != cars.crend(); ++car)
        {
            branch.push(*car);

            while (!branch.empty() && branch.top() == next_car)
            {
                branch.pop();
                ++next_car;
            }
         }

        cout << (branch.empty() ? 'Y' : 'N') << '\n';
    }

    return 0;
}
