int add(int a, int b)
{
    return a + b;
}

int power(int x, int n)
{
    int output = 1;

    if (n == 0)
        return 0;

    for (int i = 0; i < n; i++)
    {
        output = output * x;
    }

    return output;
}