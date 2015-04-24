#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int left;
    int right;

    Node():
        left(-1),
        right(-1)
    { }
};

void detach(vector<Node>& list, unsigned int index)
{
    list[list[index].left].right = list[index].right;
    list[list[index].right].left = list[index].left;
}

void insert_before(vector<Node>& list, unsigned int second, unsigned int first)
{
    list[list[second].left].right = first;

    list[first].left  = list[second].left;
    list[first].right = second;

    list[second].left = first;
}

void insert_after(vector<Node>& list, unsigned int first, unsigned int second)
{
    list[list[first].right].left = second;

    list[second].left  = first;
    list[second].right = list[first].right;

    list[first].right = second;
}

void initialize_list(vector<Node>& list, unsigned int length)
{
    for (unsigned int i = 0; i <= length + 1; ++i)
    {
        list[i].left  = i - 1;
        list[i].right = i + 1;
    }
}

void execute_operations(vector<Node>& list, unsigned int operations)
{
    for (unsigned int i = 0; i < operations; ++i)
    {
        unsigned int type;
        unsigned int left;
        unsigned int right;

        cin >> type >> left >> right;

        detach(list, left + 1);

        if (type == 1)
        {
            insert_after(list, right + 1, left + 1);
        }
        else
        {
            insert_before(list, right + 1, left + 1);
        }
    }
}

void initialize_sequence(const vector<Node>& list,
                         unsigned int length,
                         vector<unsigned int>& sequence)
{
    for (unsigned int i = list[0].right; i != length + 1; i = list[i].right)
    {
        sequence.push_back(i - 1);
    }
}

unsigned int longest_descreasing_subsequence(const vector<unsigned int>& sequence)
{
    unsigned int max_length = 0;
    vector<unsigned int> min_tails(sequence.size() + 1);

    for (vector<unsigned int>::size_type i = 0; i < sequence.size(); ++i)
    {
        unsigned int low  = 1;
        unsigned int high = max_length;

        while (low <= high)
        {
            unsigned int middle = (low + high) / 2;

            if (sequence[min_tails[middle]] > sequence[i])
            {
                low = middle + 1;
            }
            else
            {
                high = middle - 1;
            }
        }

        min_tails[low] = i;
        max_length = max(max_length, low);
    }

    return max_length;
}

int main()
{
    freopen("sequence.in",  "r", stdin);
    freopen("sequence.out", "w", stdout);

    unsigned int length;
    unsigned int operations;

    cin >> length >> operations;

    vector<Node> list(length + 2);

    initialize_list(list, length);
    execute_operations(list, operations);

    vector<unsigned int> sequence(length);

    initialize_sequence(list, length, sequence);

    cout << length - longest_descreasing_subsequence(sequence) << '\n';

    return 0;
}
