int OddEvenTest(int);
main()
{
    int a, hasil;
    a = 5;
    hasil = OddEvenTest(a);
    printf("a=%d; hasil=%d\n", a, hasil);
}
OddEvenTest(int b)
{
    int a;
    a = b % 2;
    return a;
}