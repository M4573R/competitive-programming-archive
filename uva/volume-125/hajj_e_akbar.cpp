#include <iostream>
#include <string>

using namespace std;

const string end_of_input {'*'};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string ritual;

    for (unsigned int test{1}; cin >> ritual && ritual != end_of_input; ++test)
    {
        cout << "Case " << test << ": ";

        if (ritual == "Hajj")
        {
            cout << "Hajj-e-Akbar";
        }
        else
        {
            cout << "Hajj-e-Asghar";
        }

        cout << '\n';
    }

    return 0;
}
