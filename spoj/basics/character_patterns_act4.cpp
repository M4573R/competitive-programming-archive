#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<string> generate_pixel(unsigned int height, unsigned int width)
{
    vector<string> pixel {string(width + 1, '*')};

    for (unsigned int i {0}; i < height; ++i)
    {
        pixel.push_back('*' + string(width, '.'));
    }

    return pixel;
}

void print_pattern(unsigned int rows,
                   unsigned int columns,
                   const vector<string>& pixel)
{
    for (unsigned int i {0}; i < rows; ++i)
    {
        for (const auto& element : pixel)
        {
            for (unsigned int j {0}; j < columns; ++j)
            {
                cout << element;
            }

            cout << "*\n";
        }
    }

    cout << string(pixel.front().size() * columns + 1, '*') << '\n';
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int rows;
        unsigned int columns;
        unsigned int height;
        unsigned int width;

        cin >> rows >> columns >> height >> width;

        print_pattern(rows, columns, generate_pixel(height, width));

        if (test + 1 < test_cases)
        {
            cout << '\n';
        }
    }

    return 0;
}
