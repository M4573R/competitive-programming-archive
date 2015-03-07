#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> display {
    " * * * \n*     *\n*     *\n*     *\n       \n*     *\n*     *\n*     *\n * * * \n",
    "       \n      *\n      *\n      *\n       \n      *\n      *\n      *\n       \n",
    " * * * \n      *\n      *\n      *\n * * * \n*      \n*      \n*      \n * * * \n",
    " * * * \n      *\n      *\n      *\n * * * \n      *\n      *\n      *\n * * * \n",
    "       \n*     *\n*     *\n*     *\n * * * \n      *\n      *\n      *\n       \n",
    " * * * \n*      \n*      \n*      \n * * * \n      *\n      *\n      *\n * * * \n",
    " * * * \n*      \n*      \n*      \n * * * \n*     *\n*     *\n*     *\n * * * \n",
    " * * * \n      *\n      *\n      *\n       \n      *\n      *\n      *\n      *\n",
    " * * * \n*     *\n*     *\n*     *\n * * * \n*     *\n*     *\n*     *\n * * * \n",
    " * * * \n*     *\n*     *\n*     *\n * * * \n      *\n      *\n      *\n * * * \n"
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int digit;
    cin >> digit;

    cout << display[digit];

    return 0;
}
