#include <iostream>
#include <queue>
#include <stack>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool check_stack(const vector<pair<unsigned int, unsigned int>>& operations)
{
    stack<unsigned int> items;

    for (const auto& operation : operations)
    {
        if (operation.first == 1)
        {
            items.push(operation.second);
        }
        else if (!items.empty() && items.top() == operation.second)
        {
            items.pop();
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool check_queue(const vector<pair<unsigned int, unsigned int>>& operations)
{
    queue<unsigned int> items;

    for (const auto& operation : operations)
    {
        if (operation.first == 1)
        {
            items.push(operation.second);
        }
        else if (!items.empty() && items.front() == operation.second)
        {
            items.pop();
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool check_priority_queue(const vector<pair<unsigned int, unsigned int>>& operations)
{
    priority_queue<unsigned int> items;

    for (const auto& operation : operations)
    {
        if (operation.first == 1)
        {
            items.push(operation.second);
        }
        else if (!items.empty() && items.top() == operation.second)
        {
            items.pop();
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    use_io_optimizations();

    for (unsigned int count; cin >> count; )
    {
        vector<pair<unsigned int, unsigned int>> operations(count);

        for (auto& operation : operations)
        {
            cin >> operation.first >> operation.second;
        }

        bool is_stack          {check_stack(operations)};
        bool is_queue          {check_queue(operations)};
        bool is_priority_queue {check_priority_queue(operations)};

        if (is_stack + is_queue + is_priority_queue > 1)
        {
            cout << "not sure\n";
        }
        else if (is_stack + is_queue + is_priority_queue == 0)
        {
            cout << "impossible\n";
        }
        else if (is_stack)
        {
            cout << "stack\n";
        }
        else if (is_queue)
        {
            cout << "queue\n";
        }
        else
        {
            cout << "priority queue\n";
        }
    }

    return 0;
}
