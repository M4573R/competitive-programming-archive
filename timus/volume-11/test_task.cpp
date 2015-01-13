#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int operations;
    cin >> operations;

    set<string>         logged_in;
    map<string, string> passwords;

    for (unsigned int i {0}; i < operations; ++i)
    {
        string operation;
        string username;
        string password;

        cin >> operation >> username;

        if (operation == "register")
        {
            cin >> password;

            if (passwords.count(username))
            {
                cout << "fail: user already exists\n";
            }
            else
            {
                passwords[username] = password;
                cout << "success: new user added\n";
            }
        }
        else if (operation == "login")
        {
            cin >> password;

            if (passwords.count(username) == 0)
            {
                cout << "fail: no such user\n";
            }
            else if (passwords[username] != password)
            {
                cout << "fail: incorrect password\n";
            }
            else if (logged_in.count(username))
            {
                cout << "fail: already logged in\n";
            }
            else
            {
                logged_in.insert(username);
                cout << "success: user logged in\n";
            }
        }
        else
        {
            if (passwords.count(username) == 0)
            {
                cout << "fail: no such user\n";
            }
            else if (logged_in.count(username) == 0)
            {
                cout << "fail: already logged out\n";
            }
            else
            {
                logged_in.erase(username);
                cout << "success: user logged out\n";
            }
        }
    }

    return 0;
}
