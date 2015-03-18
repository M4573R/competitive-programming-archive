#include <iostream>

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
        unsigned int poetry_pages;
        unsigned int left_pages;
        unsigned int money;
        unsigned int notebooks;

        cin >> poetry_pages >> left_pages >> money >> notebooks;

        bool is_lucky {false};
        unsigned int needed_pages {poetry_pages - left_pages};

        for (unsigned int i {0}; i < notebooks; ++i)
        {
            unsigned int pages;
            unsigned int price;

            cin >> pages >> price;

            if (pages >= needed_pages && price <= money)
            {
                is_lucky = true;
            }
        }

        cout << (is_lucky ? "LuckyChef" : "UnluckyChef") << '\n';
    }

    return 0;
}
