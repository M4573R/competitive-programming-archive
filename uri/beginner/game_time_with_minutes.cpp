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

    unsigned int start_hour;
    unsigned int start_minute;

    unsigned int end_hour;
    unsigned int end_minute;

    cin >> start_hour >> start_minute >> end_hour >> end_minute;

    unsigned int start_in_minutes {start_hour * 60 + start_minute};
    unsigned int end_in_minutes   {end_hour   * 60 + end_minute};

    cout << "O JOGO DUROU ";

    if (start_in_minutes < end_in_minutes)
    {
        unsigned int duration {end_in_minutes - start_in_minutes};

        cout << duration / 60 << " HORA(S) E "
             << duration % 60 << " MINUTO(S)";
    }
    else
    {
        unsigned int duration {24 * 60 - start_in_minutes + end_in_minutes};

        cout << duration / 60 << " HORA(S) E "
             << duration % 60 << " MINUTO(S)";
    }

    cout << '\n';

    return 0;
}
