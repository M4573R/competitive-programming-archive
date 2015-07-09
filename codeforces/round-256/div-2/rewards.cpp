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

    unsigned int gold_cups;
    unsigned int silver_cups;
    unsigned int bronze_cups;

    cin >> gold_cups >> silver_cups >> bronze_cups;

    unsigned int gold_medals;
    unsigned int silver_medals;
    unsigned int bronze_medals;

    cin >> gold_medals >> silver_medals >> bronze_medals;

    unsigned int shelves;
    cin >> shelves;

    unsigned int cups   {gold_cups   + silver_cups   + bronze_cups};
    unsigned int medals {gold_medals + silver_medals + bronze_medals};

    if ((cups + 4) / 5 + (medals + 9) / 10 <= shelves)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    cout << '\n';

    return 0;
}
