lulusan_sd(anas). % es = Elemetary School

wni(anas).

tahun_lahir(anas, 1952).

tahun_sekarang(2005).

tahun_daftar(anas, 1985).

daftar_pns(Orang) :- lulusan_sd(Orang), wni(Orang), tanggal_lahir(Orang, TanggalLahir), tahun_daftar(Orang, TahunDaftar), TahunDaftar - TanggalLahir < 35.

daftar_pns(anas).

umur_sekarang(Orang, UmurSekarang) :- tahun_lahir(Orang, TahunLahir), tahun_sekarang(TahunSekarang), UmurSekarang is TahunSekarang - TahunLahir.

pensiun(Orang) :- umur_sekarang(Orang, UmurSekarang), UmurSekarang > 60.