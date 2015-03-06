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

    double weight;
    double height;

    cin >> weight >> height;

    double bmi {weight / (height * height)};

    if (bmi > 25)
    {
        cout << "Overweight";
    }
    else if (bmi >= 18.5)
    {
        cout << "Normal weight";
    }
    else
    {
        cout << "Underweight";
    }

    cout << '\n';

    return 0;
}
