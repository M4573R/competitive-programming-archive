class PolynomialRemainder
{
public:
    int findRoot(int a, int b, int c)
    {
        int two_to_ninth  {2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2};
        int five_to_ninth {5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5};

        int first_root  {solve_congruence(a, b, c, two_to_ninth)};
        int second_root {solve_congruence(a, b, c, five_to_ninth)};

        if (first_root == -1 || second_root == -1)
        {
            return -1;
        }

        int root {second_root};

        while (root % two_to_ninth != first_root)
        {
            root += five_to_ninth;
        }

        return root;
    }

private:
    int solve_congruence(long long a, long long b, long long c, long long mod)
    {
        for (int i {0}; i < mod; ++i)
        {
            if ((((a * i) % mod * i) % mod + (b * i) % mod + c) % mod == 0)
            {
                return i;
            }
        }

        return -1;
    }
};
