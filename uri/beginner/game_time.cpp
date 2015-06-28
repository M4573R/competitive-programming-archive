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

    unsigned int start_time;
    unsigned int end_time;

    cin >> start_time >> end_time;

    cout << "O JOGO DUROU ";

    if (start_time < end_time)
    {
        cout << end_time - start_time;
    }
    else
    {
        cout << 24 - start_time + end_time;
    }

    cout << " HORA(S)\n";

    return 0;
}
