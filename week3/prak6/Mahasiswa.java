class Mahasiswa{
	private String nama;
	private String nrp;

	public Mahasiswa(String nama, String nrp){
		setNama(nama);
		setNrp(nrp);
	}

	public void setNama(String nama){
		this.nama = nama;
	}

	public void setNrp(String nrp){
		this.nrp = nrp;
	}

	public String getNama(){
		return this.nama;
	}

	public String getNrp(){
		return this.nrp;
	}

	public void cetak(){
		System.out.println("------------------");
		System.out.println("Nama: " + this.nama);
		System.out.println("NRP: " + this.nrp);
		System.out.println("------------------");
	}
}
