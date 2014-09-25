#include <cstdio>

using namespace std;

int main()
{
    short input_number;

    while (scanf("%hd", &input_number) != EOF && input_number != 42)
    {
        printf("%hd\n", input_number);
    }

    return 0;
}
