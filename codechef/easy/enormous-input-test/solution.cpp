#include <cstdio>

using namespace std;

int main()
{
    unsigned int number_of_entries;
    unsigned int divisor;

    scanf("%u %u", &number_of_entries, &divisor);

    unsigned int entry;
    unsigned int divisible_entries = 0;

    while (scanf("%u", &entry) != EOF)
    {
        if (entry % divisor == 0)
        {
            ++divisible_entries;
        }
    }

    printf("%u\n", divisible_entries);

    return 0;
}
