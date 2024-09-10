class Dosen{
	private String nama;
	private String nim;
	public String jabatan;

	public Dosen(String nama, String nim){
		setNama(nama);
		setNrp(nim);
	}

	public void setNama(String nama){
		this.nama = nama;
	}

	public void setNrp(String nim){
		this.nim = nim;
	}

	public String getNama(){
		return this.nama;
	}

	public String getNrp(){
		return this.nim;
	}

	public void cetak(){
		System.out.println("---------------- ");
		System.out.println("Nama: " + this.nama);
		System.out.println("NIM: " + this.nim);
		System.out.println("Jabatan: " + this.jabatan);
		System.out.println("---------------- ");
	}
}
