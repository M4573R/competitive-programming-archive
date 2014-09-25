#include <cstdio>

using namespace std;

constexpr double fee = 0.50;

int main()
{
    unsigned short amount;
    double balance;

    scanf("%hu %lf", &amount, &balance);

    if ((amount % 5 == 0) && (amount + fee <= balance))
    {
        balance -= amount + fee;
    }

    printf("%.2f\n", balance);

    return 0;
}
