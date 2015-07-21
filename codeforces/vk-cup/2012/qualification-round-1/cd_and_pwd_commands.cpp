#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void update_path(vector<string>& current_path)
{
    string path;
    cin >> path;

    if (path[0] == '/')
    {
        current_path.clear();
        path.erase(path.begin());
    }

    istringstream directories {path};

    for (string directory; getline(directories, directory, '/'); )
    {
        if (directory == "..")
        {
            current_path.pop_back();
        }
        else
        {
            current_path.push_back(directory);
        }
    }
}

void print_path(const vector<string>& path)
{
    cout << '/';

    for (const auto& directory : path)
    {
        cout << directory << '/';
    }

    cout << '\n';
}

int main()
{
    use_io_optimizations();

    unsigned int commands;
    cin >> commands;

    vector<string> current_path;

    for (unsigned int i {0}; i < commands; ++i)
    {
        string command;
        cin >> command;

        if (command == "cd")
        {
            update_path(current_path);
        }
        else
        {
            print_path(current_path);
        }
    }

    return 0;
}
