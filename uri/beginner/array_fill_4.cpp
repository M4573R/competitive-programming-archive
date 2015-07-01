#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void print_and_clear(vector<int>& numbers, const string& name)
{
    for (vector<int>::size_type i {0}; i < numbers.size(); ++i)
    {
        cout << name << '[' << i << "] = " << numbers[i] << '\n';
    }

    numbers.clear();
}

int main()
{
    use_io_optimizations();

    vector<int> even;
    vector<int> odd;

    for (unsigned int i {0}; i < 15; ++i)
    {
        int number;
        cin >> number;

        if (number % 2 == 0)
        {
            even.push_back(number);

            if (even.size() == 5)
            {
                print_and_clear(even, "par");
            }
        }
        else
        {
            odd.push_back(number);

            if (odd.size() == 5)
            {
                print_and_clear(odd, "impar");
            }
        }
    }

    print_and_clear(odd,  "impar");
    print_and_clear(even, "par");

    return 0;
}
