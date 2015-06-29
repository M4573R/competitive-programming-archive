#include <iostream>
#include <map>
#include <string>

using namespace std;

const map<string, map<string, map<string, string>>> animals {
    {"vertebrado",
        {{"ave",
            {{"carnivoro", "aguia"},
             {"onivoro",   "pomba"}}},
         {"mamifero",
            {{"onivoro",   "homem"},
             {"herbivoro", "vaca"}}}}},

    {"invertebrado",
        {{"inseto",
            {{"hematofago", "pulga"},
             {"herbivoro",  "lagarta"}}},
         {"anelideo",
            {{"hematofago", "sanguessuga"},
             {"onivoro",    "minhoca"}}}}}
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string first_key;
    string second_key;
    string third_key;

    cin >> first_key >> second_key >> third_key;

    cout << animals.at(first_key).at(second_key).at(third_key) << '\n';

    return 0;
}
