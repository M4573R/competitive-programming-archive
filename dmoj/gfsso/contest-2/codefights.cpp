#include <cstdlib>
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

    int my_rating;
    int competitors;

    cin >> my_rating >> competitors;

    for (int i {0}; i < competitors; ++i)
    {
        int competitor_rating;
        cin >> competitor_rating;

        if (abs(my_rating - competitor_rating) <= 100)
        {
            cout << "fite me! >:3";
        }
        else
        {
            cout << "go away! 3:<";
        }

        cout << '\n';
    }

    return 0;
}
