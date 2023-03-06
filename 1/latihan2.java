import java.util.*;
public class latihan2{
    public static void main(String argsp[]) {
        String[] warna = {"biru", "hitam", "merah", "hijau", "kuning", "putih", "ungu"};
        String[] sifat = {"Warna Ungu adalah pribadi dengan tipe yang benar-benar luar biasa. Selalu optimis, dalam menghadapi masadepan kamu tidak pernah ragu-ragu, apa yang dikerjakan kamu adalah yang terbaik. Kamu pandai benar dalammengikuti perkembangan jaman. Dalam bercinta, hanya merekalah yang kuat mental yang bisa mendekati danmenjadi kekasih kamu.", "Warna kesukaan kamu Biru, biasanya termasuk tipe pemurung, selalu menyenangkan dan selalu bertindak pasif dalam segala hal. Selalu mengharapkan kedamaian dan ketenangan. Kamu memiliki kesulitan dalam pergaulan.Demikian pula dalam bercinta karena kamu sering sekali menyembunyikan perasaan.", "Kamu termasuk tipe orang yang sangat lincah dalam hal-hal tertentu saja. Jika berada dilingkungan yang tidak disukai, maka kamu akan menjadi murung. Kamu selalu tampil menarik, rapi, cukup banyak lawan jenis berusahamengejar dan merebut cinta kamu.", "Kamu sangat berwibawa dan juga senang melindungi orang yang lemah. Walau sering kali bergaul dan bercandatapi kamu bisa menahan diri. Banyak orang mengatakan cinta, tapi kamu selalu berpikir dan berpikir lagi. Kamutermasuk tipe yang sulit jatuh cinta.", "Jika warna favorit kamu hijau, maka kamu adalah tipe yang sangat romantik, menyukai keindahan, menyenangialam dengan udara yang sejuk. Kamu adalah seseorang yang selalu memegang prinsip. Dalam hal bercinta kamumengidam-idamkan calon teman hidup yang penuh toleransi dan dapat dipercaya.", "Kesukaan kamu warna kuning menandakan bahwa kamu memiliki sifat optimis. Kamu tipe periang dan senangbergaul, tidak memiliki penampilan yang loyo. Sifat tolong-menolong selalu ada dalam diri kamu, karena menolongmerupakan suatu kewajiban mutlak bagi kamu. Kamu orang yang tidak pernah meremehkan siapapun juga,walaupun seseorang itu dungu atau bloon.", "Kamu adalah orang yang dilahirkan ke dunia dengan sempurna, jika menyukai warna putih, banyak orangmengagumi kamu karena sifat angun, sifat idealis dan moral kamu yang teramat tinggi. Tak pernah angkuh, senangmenolong siapa saja yang membutuhkan bantuan kamu.", "Warna Ungu adalah pribadi dengan tipe yang benar-benar luar biasa. Selalu optimis, dalam menghadapi masadepan kamu tidak pernah ragu-ragu, apa yang dikerjakan kamu adalah yang terbaik. Kamu pandai benar dalammengikuti perkembangan jaman. Dalam bercinta, hanya merekalah yang kuat mental yang bisa mendekati danmenjadi kekasih kamu"};
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Warna yang ada sukai: ");
        String input = sc.nextLine();
        for (int i = 0; i < warna.length; i++){
            if (input.equals(warna[i])){
                System.out.println("Karakter anda: ");
                System.out.println(sifat[i]);
            }
        }
    }
}
