#include <iostream>
#include <string>

using namespace std;

const string sequence {"16 06 68 88"};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int length;
    cin >> length;

    if (length > 4)
    {
        cout << "Glupenky Pierre";
    }
    else
    {
        cout << sequence.substr(3 * (4 - length));
    }

    cout << '\n';

    return 0;
}
