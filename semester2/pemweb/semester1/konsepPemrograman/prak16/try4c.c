void fung_a(void);
void fung_b(void);
int x = 20;
main()
{
    printf("%d\n", x);
    x += 2;
    printf("%d\n", x);
    fung_a();
    fung_a();
    printf("\nNilai x dalam main() = %d\n\n", x);
}
void fung_a(void)
{
    static x = 5;
    x++;
    printf("Nilai x dalam fung_a() = %d\n", x);
    fung_b();
}
void fung_b(void)
{
    x--;
    printf("Nilai x dalam fung_b() = %d\n", x);
}