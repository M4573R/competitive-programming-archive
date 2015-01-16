#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr char window {'X'};

constexpr unsigned int grille_size {4};
constexpr unsigned int rotations   {4};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<string> rotate_clockwise(const vector<string>& grille)
{
    vector<string> transposed(grille.size());

    for (vector<string>::size_type i {0}; i < grille.size(); ++i)
    {
        for (vector<string>::size_type j {0}; j < grille.size(); ++j)
        {
            transposed[i] += grille[grille.size() - 1 - j][i];
        }
    }

    return transposed;
}

int main()
{
    use_io_optimizations();

    vector<string> grille(grille_size);
    vector<string> cipher(grille_size);

    for (auto& row : grille)
    {
        cin >> row;
    }

    for (auto& row : cipher)
    {
        cin >> row;
    }

    string password;

    for (unsigned int rotation {0}; rotation < rotations; ++rotation)
    {
        for (unsigned int i {0}; i < grille_size; ++i)
        {
            for (unsigned int j {0}; j < grille_size; ++j)
            {
                if (grille[i][j] == window)
                {
                    password += cipher[i][j];
                }
            }
        }

        grille = rotate_clockwise(grille);
    }

    cout << password << '\n';

    return 0;
}
