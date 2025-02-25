#include <string.h>
#include <stdio.h>

// void tambah_pesanan(struct keranjang daftar_keranjang[]);
struct menu
{
    int kode, harga;
    char jenis[255];
    int kuantitas;
};
void display_menu(struct menu daftar_menu[]);
void display_bill(struct menu daftar_menu[]);
void input_pembelian(struct menu daftar_menu[]);

void main()
{

    struct menu dada = {'D', 5000, "Dada", 0};
    struct menu paha = {'P', 4000, "Paha", 0};
    struct menu sayap = {'S', 3000, "Sayap", 0};

    struct menu daftar_menu[3] = {dada, paha, sayap};

    
    display_menu(daftar_menu);
    input_pembelian(daftar_menu);
    display_bill(daftar_menu);
}

void display_menu(struct menu daftar_menu[])
{
    printf("Toko GPC, Gerobak Friend Chicken.\n\n");
    printf("Daftar Harga:\n");
    printf("Kode\tJenis\tHarga per potong\n");
    for (size_t i = 0; i < 3; i++)
    {
        struct menu m = daftar_menu[i];
        printf("%c\t%s\t%d\n", m.kode, m.jenis, m.harga);
    }
}

void display_bill(struct menu daftar_menu[])
{
    int total = 0;
    float pajak = 0;
    printf("GEROBAK FRIED CHICKEN\n");
    printf("===============================================================\n");
    printf("No.\tJenis Potong\tHarga Satuan\tQty\tJumlah Harga\n");
    printf("===============================================================\n");
    for (int i = 0; i < 3; i++)
    {
        struct menu m = daftar_menu[i];
        int subtotal = m.harga * m.kuantitas;
        if (m.kuantitas > 0)
            printf("%d.\t%s\t\t%d\t\t%d\t%d\n", i + 1, m.jenis, m.harga, m.kuantitas, subtotal);
        total += subtotal;
    }
    printf("===============================================================\n");
    printf("\t\t\t\t\tJumlah Bayar: %d\n", total);
    pajak = total / 10;
    printf("\t\t\t\t\tPajak: %f\n", pajak);
    printf("\t\t\t\t\tJumlah Bayar: %g\n", total + pajak);
}

void input_pembelian(struct menu daftar_menu[])
{
    int input = 1, iterasi = 0;
    while (input)
    {
        char jenis;
        int jumlah;
        printf("Masukkan pesanan Anda.\n");
        printf("Pesanan ke-%d\n", iterasi + 1);
        printf("Jenis: ");
        scanf(" %c", &jenis);
        printf("Jumlah: ");
        scanf(" %d", &jumlah);

        iterasi++;
        switch (jenis)
        {
        case 'D':
            daftar_menu[0].kuantitas += jumlah;
            break;
        case 'P':
            daftar_menu[1].kuantitas += jumlah;
            break;
        case 'S':
            daftar_menu[2].kuantitas += jumlah;
            break;
        default:
            printf("Menu tidak valid!");
            iterasi--;
            break;
        }
        getchar();
        printf("Ada lagi (y/t) ?: ");
        input = ((getchar() == 'y') ? 1 : 0);
    }
}