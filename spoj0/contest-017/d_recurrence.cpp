#include <iostream>
#include <vector>

using namespace std;

const unsigned int modulo = 9929;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

template <typename T>
class Matrix
{
public:
    static Matrix identity_matrix(unsigned int rows, unsigned int columns)
    {
        Matrix identity(rows, columns);

        for (unsigned int i {0}; i < identity.rows; ++i)
        {
            identity.elements[i][i] = 1;
        }

        return identity;
    }

    Matrix(unsigned int rows, unsigned int columns):
        elements(rows, vector<T>(columns)),
        rows(rows),
        columns(columns)
    { }

    Matrix operator*(const Matrix& other) const
    {
        Matrix product(rows, other.columns);

        for (unsigned int i {0}; i < rows; ++i)
        {
            for (unsigned int j {0}; j < other.columns; ++j)
            {
                for (unsigned int k {0}; k < columns; ++k)
                {
                    product[i][j] += elements[i][k] * other.elements[k][j];
                }
            }
        }

        return product;
    }

    vector<T> operator*(const vector<T>& other)
    {
        vector<T> product(rows);

        for (unsigned int i {0}; i < rows; ++i)
        {
            for (unsigned int k {0}; k < columns; ++k)
            {
                product[i] += elements[i][k] * other[k];
            }
        }

        return product;
    }

    Matrix operator%(unsigned int modulo)
    {
        Matrix remainder_matrix {*this};

        for (unsigned int i {0}; i < remainder_matrix.rows; ++i)
        {
            for (unsigned int j {0}; j < remainder_matrix.columns; ++j)
            {
                remainder_matrix.elements[i][j] %= modulo;
            }
        }

        return remainder_matrix;
    }

    vector<T>& operator[](unsigned int row)
    {
        return elements[row];
    }

private:
    vector<vector<T>> elements;

    unsigned int rows;
    unsigned int columns;
};

template <typename T>
vector<T> operator%(const vector<T>& array, unsigned int modulo)
{
    vector<T> remainder_array {array};

    for (auto& element : remainder_array)
    {
        element %= modulo;
    }

    return remainder_array;
}

template <typename T>
T exponentiate(T base, unsigned int exponent, unsigned int modulo, T identity)
{
    T result    {identity};
    T aggregate {base};

    for (unsigned int i {exponent}; i > 0; i /= 2)
    {
        if (i % 2 == 1)
        {
            result = (result * aggregate) % modulo;
        }

        aggregate = (aggregate * aggregate) % modulo;
    }

    return result;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int recurrence_order;
        unsigned int wanted_member;

        cin >> recurrence_order >> wanted_member;

        Matrix<int> recurrence_matrix(recurrence_order, recurrence_order);

        for (unsigned int j {recurrence_order}; j-- > 0;)
        {
            cin >> recurrence_matrix[0][j];
        }

        for (unsigned int j {1}; j < recurrence_order; ++j)
        {
            recurrence_matrix[j][j - 1] = 1;
        }

        vector<int> seeds(recurrence_order);

        for (unsigned int j {recurrence_order}; j-- > 0;)
        {
            cin >> seeds[j];
        }

        if (wanted_member <= recurrence_order)
        {
            cout << seeds[recurrence_order - wanted_member] << '\n';
            continue;
        }

        recurrence_matrix = exponentiate(
            recurrence_matrix,
            wanted_member - recurrence_order,
            modulo,
            Matrix<int>::identity_matrix(recurrence_order, recurrence_order)
        );

        cout << ((recurrence_matrix * seeds) % modulo).front() << '\n';
    }

    return 0;
}
