#include <iomanip>
#include <iostream>

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

    cout << fixed << setprecision(1);

    double a;
    double b;
    double c;
    double d;

    cin >> a >> b >> c >> d;

    double score {(2 * a + 3 * b + 4 * c + d) / 10};

    cout << "Media: " << score << '\n';

    if (score >= 7)
    {
        cout << "Aluno aprovado.\n";
    }
    else if (score >= 5)
    {
        cout << "Aluno em exame.\n";

        double e;
        cin >> e;

        cout << "Nota do exame: " << e << '\n';

        score = (score + e) / 2;

        if (score >= 5)
        {
            cout << "Aluno aprovado.\n";
        }
        else
        {
            cout << "Aluno reprovado.\n";
        }

        cout << "Media final: " << score << '\n';
    }
    else
    {
        cout << "Aluno reprovado.\n";
    }

    return 0;
}
