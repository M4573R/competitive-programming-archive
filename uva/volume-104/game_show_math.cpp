#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Expression
{
public:
    Expression(const vector<int>& operands, int target):
        operands(operands),
        target(target)
    { }

    string find()
    {
        computed = vector<vector<char>>(operands.size(), vector<char>(64001, 'f'));

        if (find_expression(1, operands.front()) == ' ')
        {
            return "NO EXPRESSION";
        }
        else
        {
            return build_expression();
        }
    }

private:
    vector<int> operands;
    vector<vector<char>> computed;

    int target;

    char find_expression(int i, int value)
    {

        if (i == operands.size())
        {
            return value == target ? 's' : ' ';
        }

        if (computed[i][value + 32000] != 'f')
        {
            return computed[i][value + 32000];
        }

        char result {' '};
        char operation;

        if (value % operands[i] == 0)
        {
            result = find_expression(i + 1, value / operands[i]);
            operation = '/';
        }

        if (result == ' ' && value + operands[i] <= 32000)
        {
            result = find_expression(i + 1, value + operands[i]);
            operation = '+';
        }

        if (result == ' ' && value - operands[i] >= -32000)
        {
            result = find_expression(i + 1, value - operands[i]);
            operation = '-';
        }

        if (result == ' '                 &&
            value * operands[i] >= -32000 &&
            value * operands[i] <=  32000)
        {
            result = find_expression(i + 1, value * operands[i]);
            operation = '*';
        }

        return computed[i][value + 32000] = (result == ' ' ? ' ' : operation);
    }

    string build_expression()
    {
        int value {operands.front()};

        ostringstream expression;
        expression << operands.front();

        for (unsigned int i {1}; i < operands.size(); ++i)
        {
            expression << computed[i][value + 32000] << operands[i];

            switch (computed[i][value + 32000])
            {
            case '+':
                value += operands[i];
                break;

            case '-':
                value -= operands[i];
                break;

            case '*':
                value *= operands[i];
                break;

            case '/':
                value /= operands[i];
                break;
            }
        }

        expression << '=' << target;

        return expression.str();
    }
};

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int operands_count;
        cin >> operands_count;

        vector<int> operands(operands_count);

        for (auto& operand : operands)
        {
            cin >> operand;
        }

        int target;
        cin >> target;

        cout << Expression{operands, target}.find() << '\n';
    }

    return 0;
}
