#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct siswa {
  char *nama;
  int tugas, uts, uas;
  float nilai_akhir;
} siswa;

typedef struct max {
  char *nama;
  float nilai;
} max;
char getGrade(float);
int input_data(int, siswa *);
int display_data(int, siswa *);

int main() {
  printf("MENGHITUNG NILAI AKHIR MATA KULIAH KONSEP PEMROGRAMAN\n");
  printf("Berapa jumlah mahasiswa? ");
  int jumlah_mahasiswa;
  scanf("%d", &jumlah_mahasiswa);
  struct siswa data_siswa[jumlah_mahasiswa];

  input_data(jumlah_mahasiswa, data_siswa);
  display_data(jumlah_mahasiswa, data_siswa);
}

char getGrade(float n) {
  if (n >= 80)
    return 'A';
  else if (n >= 70)
    return 'B';
  else if (n >= 60)
    return 'C';
  else if (n >= 50)
    return 'D';
  else
    return 'E';
}

int input_data(int jumlah_mahasiswa, siswa *data_siswa) {
  struct siswa s;
  for (int i = 0; i < jumlah_mahasiswa; i++) {
    char *nama;
    nama = malloc(255);
    int tugas, uts, uas;
    printf("Mahasiswa ke-%d\n", i + 1);
    printf("Nama: ");
    scanf("%s", nama);
    printf("Nilai Tugas: ");
    scanf("%d", &tugas);
    printf("Nilai UTS: ");
    scanf("%d", &uts);
    printf("Nilai UAS: ");
    scanf("%d", &uas);
    struct siswa s;
    s.nama = nama;
    s.uts = uts;
    s.uas = uas;
    s.tugas = tugas;
    s.nilai_akhir = (0.2 * uts + 0.4 * uas + 0.4 * tugas);
    data_siswa[i] = s;
  }
  return 1;
}
int display_data(int jumlah_mahasiswa, siswa *data_siswa) {
  printf("DAFTAR NILAI KONSEP PEMROGRAMAN:\n");
  printf("No.\tNama\t\t\tNilai\t\t\t\tGrade\n");
  printf("\tMahasiswa\t\tTugas\tUTS\tUAS\tAKHIR\n");
  int index_max = 0;
  for (int i = 0; i < jumlah_mahasiswa; i++) {
    if (data_siswa[i].nilai_akhir > data_siswa[index_max].nilai_akhir)
      index_max = i;
    printf("%d\t", i + 1);
    printf("%s\t\t\t", data_siswa[i].nama);
    printf("%d\t", data_siswa[i].tugas);
    printf("%d\t", data_siswa[i].uts);
    printf("%d\t", data_siswa[i].uas);
    printf("%g\t", data_siswa[i].nilai_akhir);
    printf("%c\n", getGrade(data_siswa[i].nilai_akhir));
  }
  printf("Total mahasiswa: %d\n", jumlah_mahasiswa);
  max maks;
  maks.nama = malloc(255);
  strcpy(maks.nama, data_siswa[index_max].nama);
  maks.nilai = data_siswa[index_max].nilai_akhir;
  printf("Nilai tertinggi\n");
  printf("Nama: %s\n", maks.nama);
  printf("Nilai: %g\n", maks.nilai);
  return 1;
}
