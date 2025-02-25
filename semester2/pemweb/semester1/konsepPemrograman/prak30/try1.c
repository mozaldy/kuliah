#include <stdio.h>

struct mahasiswa
{
    int no, nrp, nilai_tugas, nilai_uts, nilai_uas, nilai_akhir;
    char grade;
    char nama[255];
};
void input_nilai(struct mahasiswa data_mahasiswa[], int jumlah_mahasiswa);

void display_nilai(struct mahasiswa data_mahasiswa[], int jumlah_mahasiswa);

void main()
{
    int jumlah_mahasiswa;
    printf("Berapa jumlah mahasiswa? ");
    scanf("%d", &jumlah_mahasiswa);

    struct mahasiswa data_mahasiswa[jumlah_mahasiswa];

    input_nilai(data_mahasiswa, jumlah_mahasiswa);
    display_nilai(data_mahasiswa, jumlah_mahasiswa);
}

void input_nilai(struct mahasiswa data_mahasiswa[], int jumlah_mahasiswa)
{
    int input = 1;

    printf("Masukkan DATA Mahasiswa\n");
    while (input <= jumlah_mahasiswa)
    {
        struct mahasiswa m;
        printf("Mahasiswa ke-%d\n", input);
        printf("Nama\t\t: ");
        fgets(m.nama, sizeof(m.nama), stdin);
        scanf("%s", m.nama);
        printf("Nilai tugas\t: ");
        scanf(" %d", &m.nilai_tugas);
        printf("Nilai UTS\t: ");
        scanf(" %d", &m.nilai_uts);
        printf("Nilai UAS\t: ");
        scanf(" %d", &m.nilai_uas);
        input++;
        m.nilai_akhir = m.nilai_tugas * 0.2 + m.nilai_uts * 0.4 + m.nilai_uas * 0.4;
        if (m.nilai_akhir >= 80)
        {
            m.grade = 'A';
        }
        else if (m.nilai_akhir >= 70)
        {
            m.grade = 'B';
        }
        else if (m.nilai_akhir >= 60)
        {
            m.grade = 'C';
        }
        else if (m.nilai_akhir >= 50)
        {
            m.grade = 'D';
        }
        else if (m.nilai_akhir < 50)
        {
            m.grade = 'E';
        }
        data_mahasiswa[input - 2] = m;
    }
}

void display_nilai(struct mahasiswa data_mahasiswa[], int jumlah_mahasiswa)
{
    printf("DAFTAR NILAI.\n");
    printf("Kuliah Konsep Pemrograman.\n");
    printf("-------------------------------------------------------------------\n");
    printf("No.\tNama\t\t\tNilai\t\t\tGrade\n");
    printf("\tMahasiswa\tTugas\tUTS\tUAS\tAkhir\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < jumlah_mahasiswa; i++)
    {
        struct mahasiswa m = data_mahasiswa[i];
        printf("%d.\t%s\t\t%d\t%d\t%d\t%d\t%c\n", i + 1, m.nama, m.nilai_tugas, m.nilai_uts, m.nilai_uas, m.nilai_akhir, m.grade);
    }
    printf("-------------------------------------------------------------------\n");
    printf("Total mahasiswa: %d", jumlah_mahasiswa);
}