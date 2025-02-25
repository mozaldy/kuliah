class Mahasiswa{
	String nama, nrp;
	int nilai_rpl, nilai_bd, nilai_pbo;

	Mahasiswa(String nrp, String nama, int nilai_rpl, int nilai_bd, int nilai_pbo){
		this.nrp = nrp;
		this.nama = nama;
		this.nilai_rpl = nilai_rpl;
		this.nilai_bd = nilai_bd;
		this.nilai_pbo = nilai_pbo;
	}

	double hitungMean(){
		return (nilai_rpl + nilai_bd + nilai_pbo) / 3.0;
	}
}
