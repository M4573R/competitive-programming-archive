#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector< vector<int> > > no;
typedef vector< vector<int> >           cpp11;
typedef vector<int>                     qq;

const unsigned int modulo = 1000003;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class RoutesCount
{
public:
    RoutesCount(unsigned int cities):
        routes(cities + 1, no(cities + 1, cpp11(cities + 1, qq(3, -1)))),
        cities(cities)
    { }

    unsigned int find()
    {
        return find(0, cities - 1, cities, cities);
    }

private:
    vector< vector< vector< vector<int> > > > routes;
    unsigned int cities;

    unsigned int find(unsigned int island,
                      unsigned int left_a,
                      unsigned int left_b,
                      unsigned int left_c)
    {
        if (left_a + left_b + left_c == 0)
        {
            return island != 0;
        }

        if (routes[left_a][left_b][left_c][island] != -1)
        {
            return routes[left_a][left_b][left_c][island];
        }

        unsigned int count = 0;

        if (island != 0 && left_a > 0)
        {
            count += left_a * find(0, left_a - 1, left_b, left_c);
        }

        if (island != 1 && left_b > 0)
        {
            count += left_b * find(1, left_a, left_b - 1, left_c);
        }

        if (island != 2 && left_c > 0)
        {
            count += left_c * find(2, left_a, left_b, left_c - 1);
        }

        return routes[left_a][left_b][left_c][island] = count % modulo;
    }
};

int main()
{
    use_io_optimizations();

    unsigned int cities;
    cin >> cities;

    cout << RoutesCount(cities).find() << '\n';

    return 0;
}
