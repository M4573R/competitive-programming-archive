#include <algorithm>
#include <iostream>
#include <map>
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

struct Book
{
    string title;
    string author;

    Book() = default;

    Book(const string& title, const string& author):
        title(title),
        author(author)
    { }
};

bool operator<(const Book& left, const Book& right)
{
    if (left.author == right.author)
    {
        return left.title < right.title;
    }

    return left.author < right.author;
}

void initialize_shelves(vector<Book>& shelves)
{
    for (string line; getline(cin, line) && line != "END"; )
    {
        istringstream book {line};

        string title;
        string author;

        book.ignore();

        getline(book, title, '"');

        book.ignore();
        book.ignore();
        book.ignore();
        book.ignore();

        getline(book, author);

        shelves.emplace_back(title, author);
    }
}

void get_book(vector<bool>& borrowed,
              const map<string, unsigned int>& positions)
{
    string title;

    cin.ignore(2, '"');
    getline(cin, title, '"');

    borrowed[positions.at(title)] = true;
}

void turn_in_book(vector<bool>& returned,
                  const map<string, unsigned int>& positions)
{
    string title;

    cin.ignore(2, '"');
    getline(cin, title, '"');

    returned[positions.at(title)] = true;
}

void place_back_books(const vector<Book>& shelves,
                      vector<bool>& borrowed,
                      vector<bool>& returned)
{
    int previous {-1};

    for (unsigned int i {0}; i < shelves.size(); ++i)
    {
        if (!borrowed[i])
        {
            previous = i;
        }
        else if (returned[i])
        {
            cout << "Put \"" << shelves[i].title;

            if (previous == -1)
            {
                cout << "\" first\n";
            }
            else
            {
                cout << "\" after \"" << shelves[previous].title << "\"\n";
            }

            returned[i] = false;
            borrowed[i] = false;
            previous    = i;
        }
    }

    cout << "END\n";
}

int main()
{
    use_io_optimizations();

    vector<Book> shelves;

    initialize_shelves(shelves);
    sort(shelves.begin(), shelves.end());

    map<string, unsigned int> positions;

    for (unsigned int i {0}; i < shelves.size(); ++i)
    {
        positions[shelves[i].title] = i;
    }

    vector<bool> borrowed(shelves.size());
    vector<bool> returned(shelves.size());

    for (string command; cin >> command && command != "END"; )
    {
        if (command == "BORROW")
        {
            get_book(borrowed, positions);
        }
        else if (command == "RETURN")
        {
            turn_in_book(returned, positions);
        }
        else if (command == "SHELVE")
        {
            place_back_books(shelves, borrowed, returned);
        }

        cin.ignore();
    }

    return 0;
}
