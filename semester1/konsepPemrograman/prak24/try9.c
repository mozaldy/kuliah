main()
{
    int count = 13, sum = 9, *x, *y;
    x = &count;
    *x = 27;
    y = x;
    x = &sum;
    *x = count;
    sum = *x / 2 * 3;
    printf("count=%d, sum=%d, *x=%d, *y=%d\n", count, sum, *x, *y);
}