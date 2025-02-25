class Tugas{
	public static void main(String args[]){
		Mahasiswa aldy = new Mahasiswa("Rizaldy", "3123600011");
		Mahasiswa aril = new Mahasiswa("Aril", "3123600012");
		Dosen ivan = new Dosen("Ivan", "1234");
		ivan.jabatan = "Professor";
		aldy.cetak();
		aril.cetak();
		ivan.cetak();
		Kelas d4ita = new Kelas();
		d4ita.namaKelas = "D4 IT A 2023";
		d4ita.pengajar = ivan;
		d4ita.murid = new Mahasiswa[] {aldy, aril};
		System.out.println("Aldi ada di kelas? " + d4ita.cariMahasiswa(aldy));
		d4ita.cetak();
	}
}
