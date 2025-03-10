main()
{
    float *pu, nu;
    double u = 1234.0;
    pu = &u;
    nu = *pu;
    printf("Alamat dari u = %p\n", &u);
    printf("Isi pu = %p\n", pu);
    printf("Isi u = %lf\n", u);
    printf("Nilai yang ditunjuk oleh pu = %f\n", *pu);
    printf("Nilai nu = %f\n", nu);
}