#include <iostream>
#include <vector>

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

    unsigned int length;
    cin >> length;

    vector<unsigned int> folds;

    for (unsigned int i {length}; i > 1; i = (i + 1) / 2)
    {
        folds.push_back(i / 2);
    }

    cout << folds.size() << '\n';

    for (auto i = folds.cbegin(); i != folds.cend(); ++i)
    {
        cout << *i << " \n"[i + 1 == folds.cend()];
    }

    return 0;
}
