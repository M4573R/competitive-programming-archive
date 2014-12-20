#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr unsigned int test_case_lines {10};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct WebPage
{
    string url;
    int relevance;
};

bool operator<(const WebPage& left, const WebPage& right)
{
    return left.relevance < right.relevance;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        vector<WebPage> web_pages(test_case_lines);

        for (auto& web_page : web_pages)
        {
            cin >> web_page.url >> web_page.relevance;
        }

        cout << "Case #" << i + 1 << ":\n";

        int max_relevance {
            max_element(web_pages.begin(), web_pages.end())->relevance
        };

        for (const auto& web_page : web_pages)
        {
            if (web_page.relevance == max_relevance)
            {
                cout << web_page.url << '\n';
            }
        }
    }

    return 0;
}
