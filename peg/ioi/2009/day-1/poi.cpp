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

struct Contestant
{
    unsigned int id;
    unsigned int score;

    vector<unsigned int> solved;
};

bool operator<(const Contestant& left, const Contestant& right)
{
    if (left.score > right.score)
    {
        return true;
    }
    else if (left.score == right.score)
    {
        if (left.solved.size() > right.solved.size())
        {
            return true;
        }
        else if (left.solved.size() == right.solved.size())
        {
            if (left.id < right.id)
            {
                return true;
            }
        }
    }

    return false;
}

void read_input(unsigned int& contestants_count,
                unsigned int& tasks_count,
                unsigned int& philip_id,
                vector<Contestant>& contestants,
                vector<unsigned int>& points)
{
    cin >> contestants_count >> tasks_count >> philip_id;

    contestants.resize(contestants_count);
    points.resize(tasks_count);

    for (unsigned int i {0}; i < contestants_count; ++i)
    {
        contestants[i].id    = i + 1;
        contestants[i].score = 0;

        for (unsigned int j {0}; j < tasks_count; ++j)
        {
            bool is_solved;
            cin >> is_solved;

            if (is_solved)
            {
                contestants[i].solved.push_back(j);
            }
            else
            {
                ++points[j];
            }
        }
    }
}

void write_output(unsigned int contestants_count,
                  unsigned int philip_id,
                  const vector<Contestant>& contestants)
{
    for (unsigned int i {0}; i < contestants_count; ++i)
    {
        if (contestants[i].id == philip_id)
        {
            cout << contestants[i].score << ' ' << i + 1 << '\n';
        }
    }
}

int main()
{
    use_io_optimizations();

    unsigned int contestants_count;
    unsigned int tasks_count;
    unsigned int philip_id;

    vector<Contestant>   contestants;
    vector<unsigned int> points;

    read_input(contestants_count,
               tasks_count,
               philip_id,
               contestants,
               points);

    for (auto& contestant : contestants)
    {
        for (const auto& solved_task : contestant.solved)
        {
            contestant.score += points[solved_task];
        }
    }

    sort(contestants.begin(), contestants.end());

    write_output(contestants_count,
                 philip_id,
                 contestants);

    return 0;
}
