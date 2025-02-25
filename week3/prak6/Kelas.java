class Kelas{
	public String namaKelas;
	public Dosen pengajar;
	public Mahasiswa[] murid;

	public void cetak(){
		System.out.println("Data untuk kelas " + namaKelas);
		System.out.println("Pengajar: " + pengajar.getNama());
		for(Mahasiswa mahasiswa: murid){
			System.out.println("Nama: " + mahasiswa.getNama());
		}
	}

	public boolean cariMahasiswa(Mahasiswa mahasiswa){
		for(Mahasiswa mahasiswaDiKelas: murid){
			String cursor = mahasiswaDiKelas.getNrp();
			if(cursor.equals(mahasiswa.getNrp()))
				return true;
		}
		return false;
	}
}
