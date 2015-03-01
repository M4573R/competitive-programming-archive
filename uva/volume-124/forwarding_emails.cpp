#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void compute_reachability(const vector<unsigned int>& links,
                          vector<unsigned int>& reachable)
{
    for (unsigned int i {0}; i < links.size(); ++i)
    {
        if (reachable[i] == 0)
        {
            vector<unsigned int> path;
            vector<bool> in_path(links.size());

            unsigned int current {i};

            while (reachable[current] == 0 && !in_path[current])
            {
                in_path[current] = true;
                path.push_back(current);
                current = links[current];
            }

            if (reachable[current] != 0)
            {
                for (unsigned int j {0}; j < path.size(); ++j)
                {
                    reachable[path[j]] = reachable[current] + (path.size() - j);
                }
            }
            else
            {
                unsigned int cycle_begin {0};

                while (path[cycle_begin] != current)
                {
                    ++cycle_begin;
                }

                unsigned int cycle_size {path.size() - cycle_begin};

                for (unsigned int j {cycle_begin}; j < path.size(); ++j)
                {
                    reachable[path[j]] = cycle_size;
                }

                for (unsigned int j {0}; j < cycle_begin; ++j)
                {
                    reachable[path[j]] = cycle_size + (cycle_begin - j);
                }
            }
        }
    }
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        unsigned int martians;
        cin >> martians;

        vector<unsigned int> links(martians);

        for (unsigned int i {0}; i < martians; ++i)
        {
            unsigned int from;
            unsigned int to;

            cin >> from >> to;

            links[from - 1] = to - 1;
        }

        vector<unsigned int> reachable(martians);
        compute_reachability(links, reachable);

        auto martian = (max_element(reachable.cbegin(), reachable.cend()) -
                        reachable.cbegin() + 1);

        cout << "Case " << test << ": " << martian << '\n';
    }
}
