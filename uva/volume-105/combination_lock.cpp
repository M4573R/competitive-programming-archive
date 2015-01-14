#include <iostream>

using namespace std;

constexpr unsigned int turn_distance        {40};
constexpr unsigned int turn_degrees         {360};
constexpr unsigned int degrees_per_distance {turn_degrees / turn_distance};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

enum class Direction
{
    Clockwise,
    CounterClockwise
};

inline unsigned int to_degrees(unsigned int distance)
{
    return distance * degrees_per_distance;
}

inline unsigned int distance(unsigned int from,
                             unsigned int to,
                             Direction direction)
{
    switch (direction)
    {
    case Direction::Clockwise:
        return from >= to ? from - to : turn_distance - (to - from);

    case Direction::CounterClockwise:
        return from >= to ? turn_distance - (from - to) : to - from;
    }
}

int main()
{
    use_io_optimizations();

    unsigned int start;
    unsigned int first;
    unsigned int second;
    unsigned int third;

    while (cin >> start >> first >> second >> third &&
           !(start == 0 && first == 0 && second == 0 && third == 0))
    {
        unsigned int rotated_distance {3 * turn_distance};

        rotated_distance += distance(start, first,  Direction::Clockwise);
        rotated_distance += distance(first, second, Direction::CounterClockwise);
        rotated_distance += distance(second, third, Direction::Clockwise);

        cout << to_degrees(rotated_distance) << '\n';
    }

    return 0;
}
