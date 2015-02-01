#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void find_lis(const vector<int>& sequence,
              vector<int>& parents,
              int& lis_size,
              int& lis_end)
{
    vector<int> tails(sequence.size());
    vector<int> tail_ids(sequence.size());

    for (int i = 0; i < sequence.size(); ++i)
    {
        int tail {lower_bound(tails.begin(),
                              tails.begin() + lis_size,
                              sequence[i]) -
                  tails.begin()};

        tails[tail]    = sequence[i];
        tail_ids[tail] = i;
        parents[i]     = tail ? tail_ids[tail - 1] : -1;

        if (tail + 1 > lis_size)
        {
            lis_size = tail + 1;
            lis_end  = i;
        }
    }
}

void print_lis(const vector<int>& sequence,
               const vector<int>& parents,
               int lis_size,
               int lis_end)
{
    cout << lis_size << "\n-\n";

    stack<int> lis;

    for (int i = lis_end; i >= 0; i = parents[i])
    {
        lis.push(sequence[i]);
    }

    for (; !lis.empty(); lis.pop())
    {
        cout << lis.top() << '\n';
    }
}

int main()
{
    use_io_optimizations();

    vector<int> sequence;

    for (int element; cin >> element; sequence.push_back(element))
    { }

    int lis_size {0};
    int lis_end  {0};

    vector<int> parents(sequence.size());

    find_lis(sequence, parents, lis_size, lis_end);
    print_lis(sequence, parents, lis_size, lis_end);

    return 0;
}
