#include <iostream>
#include <list>
#include <vector>

using namespace std;

constexpr unsigned int registers_count {10};
constexpr unsigned int ram_size        {1000};
constexpr unsigned int word_size       {3};

const vector<unsigned int> empty_instruction {0, 0, 0};
const vector<unsigned int> halt_instruction  {1, 0, 0};

enum InstructionCode
{
    GoTo,
    Halt,
    SetRegisterToValue,
    AddValueToRegister,
    MultiplyRegisterByValue,
    SetRegisterToRegister,
    AddRegisterToRegister,
    MultiplyRegisterByRegister,
    SetRegisterFromRam,
    SetRamFromRegister,
};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int number_from_digits(const vector<unsigned int>& digits)
{
    unsigned int number {0};

    for (auto digit : digits)
    {
        number = number * 10 + digit;
    }

    return number;
}

vector<unsigned int> digits_from_number(unsigned int number)
{
    list<unsigned int> digits;

    for (unsigned int i {number}; i != 0; i /= 10)
    {
        digits.push_front(i % 10);
    }

    return vector<unsigned int>(digits.begin(), digits.end());
}

unsigned int execute_instruction(vector<unsigned int>& registers,
                                 vector<vector<unsigned int>>& ram,
                                 unsigned int instruction_pointer)
{
    unsigned int instruction_code {ram[instruction_pointer][0]};
    unsigned int to_register      {ram[instruction_pointer][1]};

    unsigned int from_register;
    unsigned int condition_register;
    unsigned int value;

    switch (instruction_code)
    {
    case GoTo:
        condition_register = ram[instruction_pointer][2];

        if (registers[condition_register] != 0)
        {
            return registers[to_register];
        }

        break;

    case Halt:
        break;

    case SetRegisterToValue:
        value                  = ram[instruction_pointer][2];
        registers[to_register] = value;

        break;

    case AddValueToRegister:
        value                   = ram[instruction_pointer][2];
        registers[to_register] += value;
        registers[to_register] %= ram_size;

        break;

    case MultiplyRegisterByValue:
        value                   = ram[instruction_pointer][2];
        registers[to_register] *= value;
        registers[to_register] %= ram_size;

        break;

    case SetRegisterToRegister:
        from_register          = ram[instruction_pointer][2];
        registers[to_register] = registers[from_register];

        break;

    case AddRegisterToRegister:
        from_register           = ram[instruction_pointer][2];
        registers[to_register] += registers[from_register];
        registers[to_register] %= ram_size;

        break;

    case MultiplyRegisterByRegister:
        from_register           = ram[instruction_pointer][2];
        registers[to_register] *= registers[from_register];
        registers[to_register] %= ram_size;

        break;

    case SetRegisterFromRam:
        from_register          = ram[instruction_pointer][2];
        registers[to_register] = number_from_digits(ram[registers[from_register]]);

        break;

    case SetRamFromRegister:
        to_register                   = ram[instruction_pointer][2];
        from_register                 = ram[instruction_pointer][1];
        ram[registers[to_register]] = digits_from_number(registers[from_register]);

        break;
    }

    return instruction_pointer + 1;
}

unsigned int executed_instructions(vector<vector<unsigned int>>& ram)
{
    vector<unsigned int> registers(registers_count);

    unsigned int instructions        {0};
    unsigned int instruction_pointer {0};

    while (ram[instruction_pointer] != halt_instruction)
    {
        if (ram[instruction_pointer] != empty_instruction)
        {
            instruction_pointer = execute_instruction(registers,
                                                      ram,
                                                      instruction_pointer);
        }
        else
        {
            ++instruction_pointer;
        }

        ++instructions;
    }

    return instructions + 1;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    char next_symbol;
    cin.get(next_symbol);
    cin.get(next_symbol);

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        vector<vector<unsigned int>> ram(ram_size,
                                         vector<unsigned int>(word_size));

        cin.get(next_symbol);

        for (unsigned int ram_pointer {0}; next_symbol != '\n'; ++ram_pointer)
        {
            ram[ram_pointer][0] = next_symbol - '0';

            for (unsigned int j {1}; j < word_size; ++j)
            {
                cin.get(next_symbol);
                ram[ram_pointer][j] = next_symbol - '0';
            }

            cin.get(next_symbol);
            cin.get(next_symbol);
        }

        cout << executed_instructions(ram) << '\n';

        if (i < test_cases - 1)
        {
            cout << '\n';
        }
    }

    return 0;
}
