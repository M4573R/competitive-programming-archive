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

    unsigned int rides;
    unsigned int m_rides;
    unsigned int one_ride_price;
    unsigned int m_rides_price;

    cin >> rides >> m_rides >> one_ride_price >> m_rides_price;

    if (one_ride_price * m_rides <= m_rides_price)
    {
        cout << rides * one_ride_price;
    }
    else
    {
        cout << (rides / m_rides) * m_rides_price +
                min(m_rides_price, (rides % m_rides) * one_ride_price);
    }

    cout << '\n';

    return 0;
}
