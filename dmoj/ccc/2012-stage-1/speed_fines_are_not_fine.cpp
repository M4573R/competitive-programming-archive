#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline unsigned int fine(unsigned int over_the_limit)
{
    return over_the_limit <= 20 ? 100:
           over_the_limit <= 30 ? 270:
                                  500;
}

int main()
{
    use_io_optimizations();

    unsigned int speed_limit;
    unsigned int car_speed;

    cin >> speed_limit >> car_speed;

    if (car_speed <= speed_limit)
    {
        cout << "Congratulations, you are within the speed limit!";
    }
    else
    {
        cout << "You are speeding and your fine is $"
             << fine(car_speed - speed_limit)
             << '.';
    }

    cout << '\n';

    return 0;
}
