#include <cctype>
#include <iostream>
#include <stack>
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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string expression;
        cin >> expression;

        stack<char> operators;

        for (auto symbol : expression)
        {
            if (isalpha(symbol))
            {
                cout << symbol;
            }
            else if (symbol == ')')
            {
                cout << operators.top();
                operators.pop();
            }
            else if (symbol != '(')
            {
                operators.push(symbol);
            }
        }

        cout << '\n';
    }

    return 0;
}
