#include <algorithm>
#include <map>
#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
char shift_left(char letter)
{
    static const map<char, char> left_of {
        {'q', 'w'}, {'w', 'e'}, {'e', 'r'},
        {'r', 't'}, {'t', 'y'}, {'y', 'u'},
        {'u', 'i'}, {'i', 'o'}, {'o', 'p'},
        {'a', 's'}, {'s', 'd'}, {'d', 'f'},
        {'f', 'g'}, {'g', 'h'}, {'h', 'j'},
        {'j', 'k'}, {'k', 'l'}, {'l', ';'},
        {'z', 'x'}, {'x', 'c'}, {'c', 'v'},
        {'v', 'b'}, {'b', 'n'}, {'n', 'm'},
        {'m', ','}, {',', '.'}, {'.', '/'}
    };

    return left_of.at(letter);
}

inline
char shift_right(char letter)
{
    static const map<char, char> right_of {
        {'w', 'q'}, {'e', 'w'}, {'r', 'e'},
        {'t', 'r'}, {'y', 't'}, {'u', 'y'},
        {'i', 'u'}, {'o', 'i'}, {'p', 'o'},
        {'s', 'a'}, {'d', 's'}, {'f', 'd'},
        {'g', 'f'}, {'h', 'g'}, {'j', 'h'},
        {'k', 'j'}, {'l', 'k'}, {';', 'l'},
        {'x', 'z'}, {'c', 'x'}, {'v', 'c'},
        {'b', 'v'}, {'n', 'b'}, {'m', 'n'},
        {',', 'm'}, {'.', ','}, {'/', '.'}
    };

    return right_of.at(letter);
}

int main()
{
    use_io_optimizations();

    char shift;
    string message;

    cin >> shift >> message;

    transform(message.begin(),
              message.end(),
              message.begin(),
              shift == 'L' ? shift_left : shift_right);

    cout << message << '\n';

    return 0;
}
