#include <iostream>
#include <set>

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

    unsigned int gates;
    unsigned int planes;

    cin >> gates >> planes;

    set<unsigned int> free_gates;

    for (unsigned int i {1}; i <= gates; ++i)
    {
        free_gates.insert(i);
    }

    for (unsigned int i {0}; i < planes; ++i)
    {
        unsigned int max_gate;
        cin >> max_gate;

        auto gate = free_gates.upper_bound(max_gate);

        if (gate == free_gates.begin())
        {
            break;
        }

        free_gates.erase(--gate);
    }

    cout << gates - free_gates.size() << '\n';

    return 0;
}

// Another solution with the same complexity (runs twice as fast).

// #include <iostream>
// #include <vector>

// using namespace std;

// inline
// void use_io_optimizations()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
// }

// class UnionFind
// {
// public:
//     UnionFind(unsigned int components):
//         components(components),
//         parents(components)
//     {
//         for (unsigned int i {0}; i < components; ++i)
//         {
//             parents[i] = i;
//         }
//     }

//     void link(unsigned int left, unsigned int right)
//     {
//         unsigned int left_root  {find(left)};
//         unsigned int right_root {find(right)};

//         if (left_root != right_root)
//         {
//             parents[left_root] = right_root;
//             --components;
//         }
//     }

//     unsigned int find(unsigned int item)
//     {
//         unsigned int root {item};

//         while (root != parents[root])
//         {
//             root = parents[root];
//         }

//         while (item != root)
//         {
//             unsigned int parent {parents[item]};

//             parents[item] = root;
//             item          = parent;
//         }

//         return root;
//     }

//     unsigned int size() const
//     {
//         return components;
//     }

// private:
//     unsigned int components;
//     vector<unsigned int> parents;
// };

// int main()
// {
//     use_io_optimizations();

//     unsigned int gates;
//     unsigned int planes;

//     cin >> gates >> planes;

//     UnionFind forest(gates + 1);

//     for (unsigned int i {0}; i < planes; ++i)
//     {
//         unsigned int max_gate;
//         cin >> max_gate;

//         unsigned int free_gate {forest.find(max_gate)};

//         if (!free_gate)
//         {
//             break;
//         }

//         forest.link(free_gate, free_gate - 1);
//     }

//     cout << gates + 1 - forest.size() << '\n';

//     return 0;
// }
