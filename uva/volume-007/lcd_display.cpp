#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline unsigned int rows(unsigned int digit_size)
{
    return 2 * digit_size + 3;
}

inline unsigned int columns(unsigned int digit_size)
{
    return digit_size + 2;
}

constexpr char vertical_pixel   {'|'};
constexpr char horizontal_pixel {'-'};
constexpr char blank_pixel      {' '};
constexpr char gap_pixel        {' '};
constexpr char line_break_pixel {'\n'};

inline string horizontal(unsigned int size, char filling_pixel)
{
    return blank_pixel + string(size, filling_pixel) + blank_pixel;
}

inline string horizontal_blank(unsigned int size)
{
    return horizontal(size, blank_pixel);
}

inline string horizontal_filled(unsigned int size)
{
    return horizontal(size, horizontal_pixel);
}

inline string vertical_left(unsigned int size)
{
    return vertical_pixel + string(size + 1, blank_pixel);
}

inline string vertical_right(unsigned int size)
{
    return string(size + 1, blank_pixel) + vertical_pixel;
}

inline string vertical_both(unsigned int size)
{
    return vertical_pixel + string(size, blank_pixel) + vertical_pixel;
}

using row_drawer = string (*)(unsigned int);

const vector<vector<row_drawer>> digit_drawers {
    {horizontal_filled,
     vertical_both,
     horizontal_blank,
     vertical_both,
     horizontal_filled},

    {horizontal_blank,
     vertical_right,
     horizontal_blank,
     vertical_right,
     horizontal_blank},

    {horizontal_filled,
     vertical_right,
     horizontal_filled,
     vertical_left,
     horizontal_filled},

    {horizontal_filled,
     vertical_right,
     horizontal_filled,
     vertical_right,
     horizontal_filled},

    {horizontal_blank,
     vertical_both,
     horizontal_filled,
     vertical_right,
     horizontal_blank},

    {horizontal_filled,
     vertical_left,
     horizontal_filled,
     vertical_right,
     horizontal_filled},

    {horizontal_filled,
     vertical_left,
     horizontal_filled,
     vertical_both,
     horizontal_filled},

    {horizontal_filled,
     vertical_right,
     horizontal_blank,
     vertical_right,
     horizontal_blank},

    {horizontal_filled,
     vertical_both,
     horizontal_filled,
     vertical_both,
     horizontal_filled},

    {horizontal_filled,
     vertical_both,
     horizontal_filled,
     vertical_right,
     horizontal_filled}
};

constexpr unsigned int digits_count {10};

vector<vector<string>> lcd_digits(unsigned int size)
{
    vector<vector<string>> digits(digits_count, vector<string>(rows(size)));

    for (unsigned int i {0}; i < digits_count; ++i)
    {
        digits[i][0] = digit_drawers[i][0](size);

        for(unsigned int j {1}; j <= size; ++j)
        {
            digits[i][j] = digit_drawers[i][1](size);
        }

        digits[i][size + 1] = digit_drawers[i][2](size);

        for (unsigned int j {size + 2}; j <= 2 * size + 1; ++j)
        {
            digits[i][j] = digit_drawers[i][3](size);
        }

        digits[i][2 * size + 2] = digit_drawers[i][4](size);
    }

    return digits;
}

int main()
{
    use_io_optimizations();

    unsigned int size;
    unsigned int number;

    while (cin >> size >> number && (size != 0 || number != 0))
    {
        string digits                      {to_string(number)};
        vector<vector<string>> digits_rows {lcd_digits(size)};

        for (unsigned int i {0}; i < rows(size); ++i)
        {
            for (auto digit = digits.cbegin(); digit != digits.cend(); ++digit)
            {
                cout << digits_rows[*digit - '0'][i];

                if (digit == digits.end() - 1)
                {
                    cout << line_break_pixel;
                }
                else
                {
                    cout << gap_pixel;
                }
            }
        }

        cout << line_break_pixel;
    }

    return 0;
}
