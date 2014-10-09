#include <iostream>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

enum Token
{
    LeftParen, RightParen, Operand, Operator, NoToken
};

Token token(char character)
{
    if (character == '(')
    {
        return LeftParen;
    }
    else if (character == ')')
    {
        return RightParen;
    }
    else if (character >= 'a' && character <= 'z')
    {
        return Operand;
    }
    else if (character == '+' || character == '-' ||
             character == '*' || character == '/' ||
             character == '^')
    {
        return Operator;
    }
    else
    {
        return NoToken;
    }
}

string read_expression()
{
    ostringstream reverse_polish_notation;

    stack<char> operators;
    queue<char> operands;

    unsigned int unclosed_parentheses = 0;

    do
    {
        char character;
        cin >> character;

        switch (token(character))
        {
        case LeftParen:
            while (!operands.empty())
            {
                reverse_polish_notation << operands.front();
                operands.pop();
            }

            ++unclosed_parentheses;
            break;

        case RightParen:
            while (!operands.empty())
            {
                reverse_polish_notation << operands.front();
                operands.pop();
            }

            reverse_polish_notation << operators.top();
            operators.pop();

            --unclosed_parentheses;
            break;

        case Operand:
            operands.push(character);
            break;

        default:
            operators.push(character);
            break;
        }

    } while (unclosed_parentheses > 0);

    return reverse_polish_notation.str();
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i = 0; i < test_cases; ++i)
    {
        cout << read_expression() << '\n';
    }

    return 0;
}
