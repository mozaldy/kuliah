#include <string.h>
#include <stdio.h>

// void tambah_pesanan(struct keranjang daftar_keranjang[]);
struct menu
{
    int kode, harga;
    char jenis[255];
    int kuantitas;
};
void display_menu(struct menu daftar_baju[]);
void display_bill(struct menu daftar_baju[]);
void input_pembelian(struct menu daftar_baju[]);

void main()
{

    struct menu small = {'S', 36000, "SMALL", 0};
    struct menu medium = {'M', 43000, "MEDIUM", 0};
    struct menu large = {'L', 62000, "LARGE", 0};

    struct menu daftar_baju[3] = {small, medium, large};

    
    display_menu(daftar_baju);
    input_pembelian(daftar_baju);
    display_bill(daftar_baju);
}

void display_menu(struct menu daftar_baju[])
{
    printf("Toko GPC, Gerobak Friend Chicken.\n\n");
    printf("Daftar Harga:\n");
    printf("Ukuran Baju\tNama Ukuran\tHarga per potong\n");
    for (size_t i = 0; i < 3; i++)
    {
        struct menu m = daftar_baju[i];
        printf("%c\t\t%s\t\tRp.%d\n", m.kode, m.jenis, m.harga);
    }
}

void display_bill(struct menu daftar_baju[])
{
    int total = 0;
    float pajak = 0;
    printf("GEROBAK BAJU\n");
    printf("===============================================================\n");
    printf("No.\tNama Ukuran\tHarga Satuan\tQty\tDiskon\tJumlah Harga\n");
    printf("===============================================================\n");
    for (int i = 0; i < 3; i++)
    {
        struct menu m = daftar_baju[i];
        int subtotal = m.harga * m.kuantitas;
        float diskon = (m.kuantitas / 10 != 0) ? 0.2 * subtotal : 0;
        subtotal -= diskon;
        if (m.kuantitas > 0)
            printf("%d.\t%s\t\t%d\t\t%d\t%g\t%d\n", i + 1, m.jenis, m.harga, m.kuantitas, diskon, subtotal);
        total += subtotal;
    }
    printf("===============================================================\n");
    printf("\t\t\t\t\tJumlah Bayar: %d\n", total);
    pajak = total / 10;
    printf("\t\t\t\t\tPajak: %g\n", pajak);
    printf("\t\t\t\t\tJumlah Bayar: %g\n", total + pajak);
}

void input_pembelian(struct menu daftar_baju[])
{
    int input, iterasi = 0;
    printf("Berapa jumlah data (maks 3) ? ");
    scanf(" %d", &input);
    while (iterasi <= input)
    {
        char jenis;
        int jumlah;
        printf("Data ke-%d\n", iterasi + 1);
        printf("Jenis: ");
        scanf(" %c", &jenis);
        printf("Jumlah: ");
        scanf(" %d", &jumlah);

        iterasi++;
        switch (jenis)
        {
        case 'S':
            daftar_baju[0].kuantitas += jumlah;
            break;
        case 'M':
            daftar_baju[1].kuantitas += jumlah;
            break;
        case 'L':
            daftar_baju[2].kuantitas += jumlah;
            break;
        default:
            printf("Menu tidak valid!");
            iterasi--;
            break;
        }
        getchar();
    }
}