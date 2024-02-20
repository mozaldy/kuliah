#include <stdio.h>
#include <stdlib.h>

typedef struct pegawai {
  char *nama, kelamin, *tgl_lahir;
  int id, gaji;
} pegawai;
int input_data(int, pegawai *);
int display_data(int, pegawai *);

int main() {
  printf("DATA PEGAWAI\n");
  printf("Berapa jumlah pegawai? ");
  int jumlah_pegawai;
  scanf("%d", &jumlah_pegawai);
  pegawai data_pegawai[jumlah_pegawai];

  input_data(jumlah_pegawai, data_pegawai);
  display_data(jumlah_pegawai, data_pegawai);
}

int input_data(int jumlah_pegawai, pegawai *data_pegawai) {
  for (int i = 0; i < jumlah_pegawai; i++) {
    pegawai p;
    p.nama = malloc(255);
    p.tgl_lahir = malloc(255);
    printf("Data pegawai ke-%d\n", i + 1);
    p.id = i;
    printf("Nama\t\t\t: ");
    scanf("%s", p.nama);
    printf("Tanggal lahir (dd-mm-yy): ");
    scanf("%s", p.tgl_lahir);
    printf("Jenis kelamin (L/P)\t: ");
    getchar();
    p.kelamin = getchar();
    printf("Gaji/bulan\t\t: ");
    scanf("%d", &p.gaji);
    data_pegawai[i] = p;
  }
  return 1;
}
int display_data(int jumlah_pegawai, pegawai *data_pegawai) {
  printf("Data pegawai yang telah diinputkan\n");
  for (int i = 0; i < jumlah_pegawai; i++) {
    pegawai p = data_pegawai[i];
    printf("Data pegawai ke-%d\n", i + 1);
    printf("Nama\t\t\t: %s\n", p.nama);
    printf("Tanggal lahir (dd-mm-yy): %s\n", p.tgl_lahir);
    printf("Jenis kelamin\t\t: ");
    if (p.kelamin == 'l' || p.kelamin == 'L') {
      printf("Laki-laki\n");
    } else {
      printf("Perempuan\n");
    }
    printf("Gaji/bulan\t\t: Rp. %d.00\n", p.gaji);
  }
  return 1;
}
