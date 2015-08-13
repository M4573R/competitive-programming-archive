#include <iostream>
#include <string>

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

    string verb;
    string object;

    cin >> verb >> object;

    cout << verb << "-tu ";

    if (object.back() == 'e')
    {
        cout << "la ";
    }
    else if (object.back() == 's')
    {
        cout << "les ";
    }
    else
    {
        cout << "le ";
    }

    cout << object << " ?\n";

    return 0;
}
