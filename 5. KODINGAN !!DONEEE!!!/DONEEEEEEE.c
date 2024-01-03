#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// DEKLARASI FUNGSI
int main ();
void loginAdmin();
void menuAdmin();
void pencarianCepat ();
void menuTambah();
void lihatMenuAdmin();
void tambahMenu();
int  cariMenu ();
void hapusData ();
void ubahHarga ();
void tambahStok ();
void lihatPesanan();
void hapusPesanan();
void lihatMember ();
void hapusMember();
void loginUser();
void regisUser();
void User();
void menuUser();
void lihatMenu();
void Pesan();
void pemesanan();
void cls();
void pause();
void Pembayaran();

struct dataPelanggan
{
    char nama[20], alamat[100], nomorHP[20], username[20], password[20];
};

struct nonMember
{
    char nama[20];
};

struct Menu
{
    char namaMenu[50];
    int harga, stok;
};

struct Pesanan
{
    char namaMenu[50], nama[25];
    int banyakMenu, hargaMenu;
};

int harga = 0;

void cls(){system ("cls");}
void pause(){system("pause");}

//PROGRAM UTAMA
int main () {
    cls ();
    int pilih;

    printf ("Pilih role :\n1. Admin\n2. User\n3. Keluar\n\nPilih menu : ");
    scanf ("%i", &pilih);

    // Membersihkan Layar
    cls ();    

    switch (pilih)
    {
    case 1:
        loginAdmin();
        break;
    
    case 2:
        User ();
        break;

    case 3:
        printf ("\nTerima kasih telah menggunakan program kami :)");
        break;

    default:
        printf("Maaf pilihan menu tidak ada");
        main ();
        break;
    }

    return 0;
}

    //PROSES LOGIN ADMIN
void loginAdmin () {

    // Deklarasi Variabel
        int x = 0;
        char username[20], password[20];

        // Looping hingga x < 3
        while (x < 3)
        {
            printf ("\nMasukkan username : ");
            scanf ("%s", username);
            printf ("Masukkan password : ");
            scanf ("%s", password);
            // Membersihkan layar
            cls ();

            // Cek username dan password
            if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0)
            {
                printf ("Anda berhasil login!\n\n");
                
                // Memanggil fungsi menuAdmin() setelah login berhasil
                menuAdmin();
                break; // Keluar dari loop jika login berhasil
            } else {
                printf ("Username atau password salah. Kesempatan tersisa: %i\n", 2 - x);
                x++;
            }
        }
        
        // Kesempatan habis
        if (x == 3)
        {
            printf ("\nKesempatan Anda habis. Silahkan coba lagi nanti.");
        }

}

        //ADMIN BERHASIL LOGIN
void menuAdmin(){
    int pilih;
    printf("===== Selamat datang di Menu Admin =====\n");
    printf("1. Tambah menu baru\n");
    printf("2. Pencarian cepat (Menghapus, Mengubah harga, Update stok menu makanan/minuman)\n");
    printf("3. Lihat menu makanan/minuman\n");
    printf("4. Lihat Pesanan\n");
    printf("5. Hapus Pesanan\n");
    printf("6. Lihat Member\n");
    printf("7. Keluar dari Menu Admin\n\n");
    printf("Pilih menu [1-7] : "); scanf("%d", &pilih);
    cls();
    switch (pilih)
    {
    case 1:
        menuTambah ();
        break;
    
    case 2: 
        pencarianCepat();
        break;

    case 3:
        lihatMenuAdmin ();
        printf ("\n");
        pause ();
        cls ();
        menuAdmin ();
        break;
    
    case 4:
        lihatPesanan();
        pause();
        cls();
        menuAdmin();
        break;

    case 5:
        hapusPesanan();
        break;

    case 6: 
        lihatMember();
        break;

    case 7:
        main ();
        cls ();
        break;

    default:
        printf ("Pilihan tidak valid, silahkan pilih ulang\n\n");
        pause ();
        cls ();
        menuAdmin ();
        break;
}

}
        //MENU 1 ADMIN : TAMBAH MAKANAN ATAU MINUMAN
void menuTambah () {

    int pilih;

    printf ("\n==================\n");
    printf ("1. Menambah menu makanan\n");
    printf ("2. Menambah menu minuman\n");
    printf ("3. Kembali\n\n");
    printf ("Pilih : ");
    scanf ("%i", &pilih);
    cls ();

    switch (pilih)
    {
    case 1:
        tambahMenu ("makanan.dat", "makanan");
        break;
    
    case 2:
        tambahMenu ("minuman.dat", "minuman");
        break;

    case 3:
        menuAdmin ();
        break;

    default:
        printf ("Pilihan tidak valid, silahkan pilih ulang.\n\n");
        pause();
        cls();
        menuTambah ();
        break;
    }
}

        //MENU 1 ADMIN : PROSES TAMBAH MAKANAN / MINUMAN
void tambahMenu (const char *fileMenu, const char *jenis) {

    struct Menu tambah;
    int n;    
    FILE *fp = fopen (fileMenu, "ab");

    if (fp == NULL)
    {
        printf ("File tidak ada");
    }

    printf ("\n=== Menambahkan menu %s ===\n\n", jenis);
    printf ("Banyak menu %s : ", jenis);
    scanf ("%i", &n);
    cls ();

    for (int i = 0; i < n; i++)
    {
       fflush (stdin); 
       printf ("Menu %s ke-%i\n\n", jenis, i + 1);
       printf ("Nama %s  : ", jenis); gets (tambah.namaMenu);
       printf ("Harga %s : ", jenis); scanf ("%i", &tambah.harga);
       printf ("Stok %s  : ", jenis); scanf ("%i", &tambah.stok);
       printf ("\n");

       fwrite (&tambah, sizeof(struct Menu), 1, fp); 
    }

    // FILE CLOSE
    fclose(fp);
    
    printf ("\nMenu makanan berhasil ditambahkan\n\n");
    pause ();
    cls ();
    menuAdmin ();
}

//FUNGSI EDIT DATA MAKANAN/MINUMAN
        //MENU 2 ADMIN : PENCARIAN CEPAT
void pencarianCepat()
{
    char menuCari[25];
    int cari;

    //melhat menu
    lihatMenuAdmin ();

    fflush (stdin);
    printf("1. Makanan\n2. Minuman\n3. Kembali\n\n Masukkan Pilihan : "); scanf("%i", &cari); 
    switch (cari)
    {
    case 1:
    fflush(stdin);
        printf("Masukkan jenis Makanan : "); gets(menuCari);
        if (cariMenu("makanan.dat", "Makanan", menuCari))
        {
            printf("Apa yang ingin anda lakukan dengan %s", menuCari);
            int pilih;
            printf("\n1. Ubah Harga \n2. Tambah Stok \n3. Hapus Menu \n4. Kembali\n\nPilih : ");
            scanf("%d",&pilih);
            
            cls();
            switch(pilih)
            {
                case 1:ubahHarga(menuCari,"makanan.dat","Makanan");break;
                case 2:tambahStok(menuCari,"makanan.dat","Makanan");break;
                case 3:hapusData(menuCari,"makanan.dat","Makanan");break;
                case 4:menuAdmin();break;
                default:printf("Pilihan tidak ada!"); pause(); pencarianCepat();
            }
        }
        break;
    case 2:
    fflush(stdin);
        printf("Masukkan jenis Minuman : "); gets(menuCari);
        if (cariMenu("minuman.dat", "Minuman", menuCari))
        {
            printf("Apa yang ingin anda lakukan dengan %s", menuCari);
            int pilih;
            printf("\n1. Ubah Harga \n2. Tambah Stok \n3. Hapus Menu \n4. Kembali \n\nPilih : ");
            scanf("%d",&pilih);
            
            cls();
            switch(pilih)
            {
                case 1:ubahHarga(menuCari,"minuman.dat","Minuman");break;
                case 2:tambahStok(menuCari,"minuman.dat","Minuman");break;
                case 3:hapusData(menuCari,"minuman.dat","Minuman");break;
                case 4:menuAdmin();break;
                default:printf("Pilihan tidak ada!"); pause(); pencarianCepat();
            }
        }
            break;

    case 3:
    menuAdmin ();
    break;

    default:
        printf("Pilihan Tidak Ada!\n");
        fflush(stdin);
        pause();
        menuAdmin();
        break;
    }
}
            //PENCARIAN CEPAT : PROSES MENCARI
int cariMenu(const char *fileMenu, const char *tipe, const char *jenis)
{
    FILE *cari = fopen(fileMenu, "rb");
    struct Menu cek;

    while (fread(&cek, sizeof(struct Menu),1,cari))
    {
        if (strcmp(jenis, cek.namaMenu)==0)
        {
            fclose(cari);
            return 1;
        }
    }
    fclose(cari);
    printf("%s tidak ada! Silahkan Coba lagi.\n", jenis);
    pause();
    cls();
    pencarianCepat();
    return 0; 
}
            //PENCARIAN CEPAT : UBAH HARGA
void ubahHarga (const char *cari, const char *fileMenu, const char *jenis)
{
    FILE *fp = fopen(fileMenu, "rb+");
    struct Menu hargaUbah;
    while (fread(&hargaUbah, sizeof (hargaUbah), 1, fp) == 1)
    {
        if (strcmp(cari,hargaUbah.namaMenu) == 0)
        {
            printf("Harga sebelum diubah : Rp. %d\n", hargaUbah.harga);
            printf("Harga Baru           : Rp. ");
            scanf("%i", &hargaUbah.harga);
            fseek(fp, -sizeof(hargaUbah),SEEK_CUR); // Mengembalikan posisi file ke awal record
            fwrite(&hargaUbah, sizeof(hargaUbah),1,fp); // Menuliskan data baru ke file
            break;
        }
    }
    fclose(fp);
    printf("Harga telah berhasil dirubah.\n");
    pause();
    menuAdmin();
}
            //PENCARIAN CEPAT : TAMBAH STOK
void tambahStok(const char *cari, const char *fileMenu, const char *jenis)
{
    FILE *fp = fopen(fileMenu, "rb+");
    struct Menu stokTambah;
    int tambahStok;
    while (fread(&stokTambah, sizeof (struct Menu), 1, fp))
    {
        if (strcmp(stokTambah.namaMenu, cari) == 0)
        {
            printf("\nJumlah Stok %s saat ini   : %d\n",cari, stokTambah.stok);
            printf("Jumlah yang ditambahkan : ");
            scanf("%d",&tambahStok);
            stokTambah.stok += tambahStok;
            fseek(fp,-sizeof(struct Menu), SEEK_CUR); // Kembali ke posisi awal field '
            fwrite(&stokTambah, sizeof(struct Menu),1,fp); // Simpan hasil perubah
            break;
        }
    }
    fclose(fp);
    printf("Stok telah berhasil ditambahkan.\n");
    pause();
    menuAdmin();
}
        //PENCARIAN CEPAT : HAPUS MAKANAN / MINUMAN
void hapusData(const char *cari, const char *fileMenu, const char *jenis)
{
    struct Menu hapus;
    
    FILE *fp = fopen(fileMenu, "rb");
    FILE *fp1= fopen("temp.dat", "wb");
    while (fread(&hapus, sizeof(struct Menu), 1, fp))
    {
        if (strcmp(hapus.namaMenu, cari) != 0)
        {
            fwrite(&hapus, sizeof(struct Menu), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    remove(fileMenu);
    rename("temp.dat", fileMenu);
    printf("Menu telah dihapus.\n");
    pause();
    menuAdmin();
}

        //UNTUK ADMIN : MEMBACA DATA MAKANAN DAN MINUMAN DARI FILE
void lihatMenuAdmin () {

    struct Menu menu;
    FILE *fp = fopen ("makanan.dat", "rb");
    FILE *fp1 = fopen ("minuman.dat", "rb");

    printf ("%-20s%-20s%-20s\n\n", "Nama Makanan", "Stok", "Harga");
    
    while (fread(&menu, sizeof(struct Menu), 1, fp) == 1)
    {
        printf ("%-20s%-20i%-20i\n", menu.namaMenu, menu.stok, menu.harga);
    }
    
    printf ("\n");

    printf ("%-20s%-20s%-20s\n\n", "Nama Minuman", "Stok", "Harga");

    while (fread(&menu, sizeof(struct Menu), 1, fp1) == 1)
    {
        printf ("%-20s%-20i%-20i\n", menu.namaMenu, menu.stok, menu.harga);
    }
    
    fclose (fp);
    fclose (fp1);

    printf ("\n");
}
        //MENU ADMIN 4 : TAMPILKAN PESANAN
void lihatPesanan()
{
    cls();
    struct Pesanan tampilkan;
    FILE *fp = fopen("pesanan.dat", "rb");
    if(fp == NULL)
    {
        printf("BELUM ADA PESANAN");
    }
    printf ("%-20s%-20s%-20s\n\n", "Nama Pemesan", "Pesanan", "Banyak Pesanan");
    while (fread(&tampilkan, sizeof(struct Pesanan), 1, fp) == 1)
    {
        printf ("%-20s%-20s%-20i\n", tampilkan.nama, tampilkan.namaMenu, tampilkan.banyakMenu);
    }
    fclose(fp);
    printf("\n");
}
        //MENU ADMIN 5 : HAPUS PESANAN
void hapusPesanan()
{
    struct Pesanan hapus;
    char namaPemesan[25];
    FILE *fp = fopen("pesanan.dat", "rb");
    FILE *fp1= fopen("temp.dat", "wb");
    lihatPesanan();
    fflush(stdin);
    printf("Pesanan yang ingin dihapus : ");
    gets(namaPemesan);
    while (fread(&hapus, sizeof(struct Pesanan), 1, fp))
    {
        if (strcmp(hapus.nama, namaPemesan) != 0)
        {
            fwrite(&hapus, sizeof(struct Pesanan), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    remove("pesanan.dat");
    rename("temp.dat", "pesanan.dat");
    printf("Pesanan telah dihapus.\n");
    pause();
    menuAdmin();
}
        //MENU ADMIN 6 : LIHAT MEMBER
void lihatMember()
{
    char hapus[5];
    struct dataPelanggan lihat;
    FILE *fp = fopen ("data_pelanggan.dat", "rb");
    

    printf ("%-20s%-20s%-20s%-20s\n\n", "Nama Pelanggan", "Alamat", "Nomor HP", "Username");
    
    while (fread(&lihat, sizeof(struct dataPelanggan), 1, fp) == 1)
    {
        printf ("%-20s%-20s%-20s%-20s\n", lihat.nama, lihat.alamat, lihat.nomorHP, lihat.username);
    }

    printf ("\n");    
    fclose (fp);
    printf ("\n");
    printf("Apakah Anda Ingin Menghapus Member?(y/n)");
    fflush(stdin);
    
    scanf("%s", &hapus);
    if ((hapus[0]=='Y')||(hapus[0]=='y'))
    {
        fflush(stdin);
        hapusMember();
    }
    else if ((hapus[0] == 'N' || 'n'))
    {
        cls();
        fflush(stdin);
        menuAdmin();
    }
    else
    {
        printf("Pilihan Tidak Ada! Silahkan Coba Lagi");
        pause();
        fflush(stdin);
        cls();
        lihatMember();
    }
}
        //MENU ADMIN 6 : PROSES HAPUS?
void hapusMember()
{
    char member[25];
    struct dataPelanggan hapus;
    FILE *fp = fopen ("data_pelanggan.dat", "rb");
    FILE *fp1 = fopen("temp.dat","wb");
    printf("Masukkan Username Member Yang Ingin Dihapus : ");
    gets(member);

    while (fread(&hapus, sizeof(struct dataPelanggan),1,fp))
    {
        if(strcmp(hapus.username, member) != 0)
        {
            fwrite(&hapus, sizeof(struct dataPelanggan), 1, fp1);
        }   
    }
    fclose(fp);
    fclose(fp1);
    remove("data_pelanggan.dat");
    rename("temp.dat", "data_pelanggan.dat");
    printf("Member Berhasil Dihapus!");
    pause();
    menuAdmin();
}
//MENU USER
void User () {
    
    int pilih;
    
    printf ("=============\n1. Registrasi member\n2. Login member\n3. Pesan non member\n\nPilih menu : ");
    scanf ("%i", &pilih);
    // Membersihkan layar
    cls ();

    switch (pilih)
    {
    case 1:
        regisUser ();
        break;
    
    case 2:
        loginUser ();
        break;

    case 3:
        Pesan ();
        break;
    case 99:
        main();
        break;
    default:
        printf ("\nPilihan anda tidak valid, silahkan pilih ulang :)\n");
        User ();
        break;
    }    
}

        //MENU 1 USER : REGISTRASI USER BARU
void regisUser () {

    // Deklarasi Variabel
        struct dataPelanggan data;

        getchar();
        printf ("\n===REGISTRASI AKUN PELANGGAN===\n");
        printf ("Masukkan nama : "); gets (data.nama);
        printf ("Masukkan Alamat : "); gets (data.alamat);
        printf ("Masukkan NO.HP : "); scanf("%s", data.nomorHP);
        printf ("\nAKUN BERHASIL DIBUAT!\n");
        printf ("Masukkan username : "); scanf("%s", data.username);
        printf ("Masukkan password : "); scanf("%s", data.password);
        // FILE OPEN
        FILE *fp = fopen("data_pelanggan.dat", "ab");
        // Menulis data ke file data_pelanggan.dat
        fwrite(&data, sizeof(struct dataPelanggan), 1, fp);
        // FILE CLOSE
        fclose(fp); 

        cls ();
        // Memanggil fungsi loginUser() setelah User registrasi
        loginUser();
}

        //MENU 2 USER : LOGIN USER
void loginUser () {

    // Deklarasi Variabel
        struct dataPelanggan user;
        char inputUsername[20], inputPassword[20];
        int x = 0;
        
        // FILE OPEN
        FILE *fp = fopen("data_pelanggan.dat", "rb");

        while (x < 3)
        {
            printf ("\n===LOGIN PELANGGAN===\n");
            printf ("Masukkan username : "); 
            scanf ("%s", inputUsername);
            printf ("Masukkan password : "); 
            scanf ("%s", inputPassword);
            cls ();

            // Mengatur ulang posisi pointer file ke awal
            fseek(fp, 0, SEEK_SET);

            // Membaca data dari file
            while (fread(&user, sizeof(struct dataPelanggan), 1, fp) == 1)
            {

            // Cek username dan password
            if (strcmp(inputUsername, user.username) == 0 && strcmp(inputPassword, user.password) == 0)
            {
                printf ("Anda berhasil login!\n\n");

                // Memanggil fungsi menuUser() setelah login berhasil
                menuUser (user.nama);
                
                // FILE CLOSE
                fclose(fp); 
                return;
            } 
        }

        printf ("Username atau password salah. Kesempatan tersisa : %i\n", 2 - x);
        x++;
    }    
        // Kesempatan habis
        if (x == 3)
        {
            printf ("\nKesempatan Anda habis. Silahkan coba lagi nanti.");
        } 
        // FILE CLOSE
        fclose(fp);

}

        //MENU SETELAH LOGIN / PESAN LANGSUNG
void menuUser(const char *namaPemesan){

    int pilih;
    char jawaban[5];
    printf("===== Selamat datang %s =====\n",namaPemesan);
    printf("1. Lihat Menu makanan dan minuman\n");
    printf("2. Melakukan Pemesanan\n");
    printf("3. Keluar dari Menu Pesanan\n\n");
    printf("Pilih menu [1-3] : "); scanf("%d", &pilih);

    cls();

    switch (pilih)
    {
    case 1 :
        lihatMenu ();
        pause();
        cls();
        menuUser(namaPemesan);
        break;
    case 2: 
        pemesanan (namaPemesan);
        break;
    case 3:
        fflush(stdin);
        printf("Apakah Anda Yakin Ingin Keluar dari menu user? (y/n) : ");
        gets(jawaban);
        if ((jawaban[0] == 'y') || (jawaban[0] == 'Y'))
        {
            User();
        }
        else if ((jawaban[0] == 'n') || (jawaban[0] == 'N'))
        {
            cls();
            menuUser(namaPemesan);
        }
        else
        {
            printf ("Jawaban yang anda berikan tidak valid.\n\n");
            pause();
            cls();
            menuUser(namaPemesan);
        }
        main ();
    
    default:
        printf("Maaf Pilihan Tidak Ada, Silahkan Coba Lagi\n");
        menuUser (namaPemesan);
        break;
    }

}
        //MENU 1 SETELAH LOGIN / PESAN LANGSUNG : LIHAT MENU
void lihatMenu () {

    struct Menu menu;
    FILE *fp = fopen ("makanan.dat", "rb");
    FILE *fp1 = fopen ("minuman.dat", "rb");

    printf ("%-20s%-20s%-20s\n\n", "Nama Makanan", "Stok", "Harga");
    
    while (fread(&menu, sizeof(struct Menu), 1, fp) == 1)
    {
        printf ("%-20s%-20i%-20i\n", menu.namaMenu, menu.stok, menu.harga);
    }
    
    printf ("\n");

    printf ("%-20s%-20s%-20s\n\n", "Nama Minuman", "Stok", "Harga");

    while (fread(&menu, sizeof(struct Menu), 1, fp1) == 1)
    {
        printf ("%-20s%-20i%-20i\n", menu.namaMenu, menu.stok, menu.harga);
    }
    
    fclose (fp);
    fclose (fp1);

    printf ("\n");
}


void pemesanan (const char *namaPemesan) {

    struct Menu menu;
    struct Pesanan pesanan;
    char namaDicari[50];
    int jumlahPesanan;

    //menampilkan menu yang tersedia
    lihatMenu();
    printf ("\n");
       
    FILE *fp2 = fopen("makanan.dat", "rb+");
    if (fp2 == NULL)
    {
        printf("Gagal membuka file makanan.dat\n");
        exit(1);
    }
    fflush(stdin);

    char jenis[15];
    printf("Masukkan jenis menu yang ingin dipesan (makanan/minuman) : ");
    fgets(jenis, sizeof(jenis), stdin);
    jenis[strcspn(jenis, "\n")] = '\0';  // Menghilangkan karakter newline dari input

    if (strcmp(jenis, "makanan") == 0)
    {
        fflush(stdin);
        printf("Masukkan nama makanan : ");
        fgets(namaDicari, sizeof(namaDicari), stdin);
        namaDicari[strcspn(namaDicari, "\n")] = '\0';  // Menghilangkan karakter newline dari input

        while (fread(&menu, sizeof(struct Menu), 1, fp2) == 1)
        {
            if (strcmp(namaDicari, menu.namaMenu) == 0)
            {
                printf("Berapa banyak : ");
                scanf("%i", &jumlahPesanan);
                cls ();

                if (jumlahPesanan <= menu.stok)
                {
                    // Mengurangi stok makanan
                    menu.stok -= jumlahPesanan;

                    // Menggeser pointer posisi file untuk menulis kembali data
                    fseek(fp2, -sizeof(struct Menu), SEEK_CUR);
                fwrite(&menu, sizeof(struct Menu), 1, fp2);

                    fflush(fp2);  // Penting: Pastikan data terus ditulis ke file

                    // Menambah harga ke total pembayaran pembeli
                    
                    harga = harga + menu.harga * jumlahPesanan;
                    strcpy(pesanan.namaMenu, namaDicari);
                    pesanan.hargaMenu = menu.harga;
                    pesanan.banyakMenu = jumlahPesanan; 

                    // FILE OPEN
                    FILE *fp4 = fopen ("pesananSementara.dat", "ab+");

                    fwrite (&pesanan, sizeof(struct Pesanan), 1, fp4);

                    // FILE CLOSE
                    fclose (fp4);

                    printf("Pesanan berhasil!\n\n");

                    char jawaban[5];

                    fflush (stdin);
                    printf ("Apakah anda ingin memesan lagi (y/n) : ");
                    gets (jawaban);
                    cls ();

                    if ((jawaban[0] == 'y') || (jawaban[0] == 'Y'))
                    {
                        pemesanan(namaPemesan);
                    } 
                    else if ((jawaban[0] == 'n') || (jawaban[0] == 'N'))
                    {
                        Pembayaran (namaPemesan);
                    }
                    else
                    {
                        printf ("Jawaban yang anda berikan tidak valid. Silahkan kembali ke menu :}\n\n");
                        pause();
                        cls();
                        pemesanan(namaPemesan);
                    }
                    
                }
                else
                {
                    printf("Stok yang anda masukkan tidak mencukupi.\nSilahkan pesan ulang :)\n\n");
                    pause();
                    cls();
                    menuUser(namaPemesan);
                }

                fclose(fp2);
                return;
            }
        }

        cls ();
        printf("\nBarang tidak ditemukan.\nSilahkan coba lagi\n\n");
        pause ();
        cls ();
        menuUser (namaPemesan);
        fclose(fp2);

    }
    else if (strcmp (jenis, "minuman") == 0) 
    {
            FILE *fp3 = fopen("minuman.dat", "rb+");
            if (fp3 == NULL)
            {
            printf("Gagal membuka file makanan.dat\n");
            exit(1);
            }

        fflush(stdin);
        printf("Masukkan nama minuman : ");
        fgets(namaDicari, sizeof(namaDicari), stdin);
        namaDicari[strcspn(namaDicari, "\n")] = '\0';  // Menghilangkan karakter newline dari input

        while (fread(&menu, sizeof(struct Menu), 1, fp3) == 1)
        {
            if (strcmp(namaDicari, menu.namaMenu) == 0)
            {
                printf("Berapa banyak : ");
                scanf("%i", &jumlahPesanan);
                cls ();

                if (jumlahPesanan <= menu.stok)
                {
                    // Mengurangi stok makanan
                    menu.stok -= jumlahPesanan;

                    // Menggeser pointer posisi file untuk menulis kembali data
                    fseek(fp3, -sizeof(struct Menu), SEEK_CUR);
                    fwrite(&menu, sizeof(struct Menu), 1, fp3);

                    fflush(fp3);  // Penting: Pastikan data terus ditulis ke file

                    // Menambah harga ke total pembayaran pembeli
                    harga = harga + menu.harga * jumlahPesanan;
                    strcpy(pesanan.namaMenu, namaDicari);
                    pesanan.hargaMenu = menu.harga;
                    pesanan.banyakMenu = jumlahPesanan; 

                    // FILE OPEN
                    FILE *fp5 = fopen ("pesananSementara.dat", "ab+");

                    fwrite (&pesanan, sizeof(struct Pesanan), 1, fp5);

                    // FILE CLOSE
                    fclose (fp5);
                    printf("Pesanan berhasil!\n\n");
                    
                    char jawaban[5];
                    
                    fflush (stdin);
                    printf ("Apakah anda ingin memesan lagi (y/n) : ");
                    gets (jawaban);
                    cls ();

                    if ((jawaban[0] == 'y') || (jawaban[0] == 'Y'))
                    {
                        pemesanan(namaPemesan);
                    } 
                    else if ((jawaban[0] == 'n') || (jawaban[0] == 'N'))
                    {
                        Pembayaran (namaPemesan);
                    }
                    else
                    {
                        printf ("Jawaban yang anda berikan tidak valid. Silahkan kembali ke menu :}\n\n");
                        pause();
                        cls();
                        pemesanan(namaPemesan);
                    }
                    
                }
                else
                {
                    printf("Stok yang anda masukkan tidak mencukupi.\nSilahkan pesan ulang :)\n\n");
                    pause();
                    cls();
                    menuUser(namaPemesan);
                }

                fclose(fp3);
                return;
            }
        }

        cls ();
        printf("\nBarang tidak ditemukan.\nSilahkan coba lagi\n\n");
        pause ();
        cls ();
        menuUser (namaPemesan);
        fclose(fp3);

    }
    else
    {
        cls ();
        printf ("Jawaban tidak valid, silahkan coba lagi.\n\n");
        pause ();
        cls ();
        pemesanan (namaPemesan);
    }
}

void Pembayaran (const char *namaPemesan) {

    struct Pesanan tampilkan;
    int bayar, kembalian;

    FILE *fp = fopen ("pesananSementara.dat", "rb");
    FILE *fp1= fopen ("pesanan.dat", "ab+");

    printf ("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("\t%-20s%-26s%-20s\n\n", "Nama Menu", "Banyak", "Harga/porsi");

    while (fread(&tampilkan, sizeof(struct Pesanan), 1, fp) == 1)
    {
        printf ("\t%-20s%-26iRp. %-20i\n", tampilkan.namaMenu, tampilkan.banyakMenu, tampilkan.hargaMenu);
        strcpy(tampilkan.nama , namaPemesan);
    }

    printf ("\t                                                          +\n");
    printf ("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf ("\tTOTAL YANG HARUS DI BAYAR                   = Rp. %i\n", harga);
    printf ("\tMASUKKAN NOMINAL UANG YANG ANDA BAYARKAN    = Rp. ");
    scanf ("%i", &bayar);

    kembalian = bayar - harga;

    if (bayar >= harga)
    {
        printf ("\tUANG KEMBALIAN ANDA                         = Rp. %i\n", kembalian);
    }
    else
    {
        cls ();
        printf ("\tUANG ANDA KURANG                            = Rp. %i\n", harga - bayar);
        harga -= bayar;
        Pembayaran (namaPemesan);
    }
    
    printf ("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("\t\t\t\tTERIMA KASIH SUDAH MEMBELI MAKANAN DI WARTEG KAMI\n");
    printf ("\t\t\t\t    SEMOGA HARI ANDA MENYENANGKAN\n");

    printf ("\n\n");

    harga = 0;
    while(fread(&tampilkan, sizeof(struct Pesanan), 1, fp)==1); //membaca fp
    {
        fwrite(&tampilkan, sizeof(struct Pesanan), 1, fp1); //menulis data dari fp ke fp1
        fclose(fp1);
    }
    fclose(fp);
    fp = fopen("pesananSementara.dat", "wb");
    fclose(fp);
    pause ();
    User();
    
}

void Pesan ()
{

    struct nonMember data;

    fflush (stdin);
    printf ("Masukkan nama : ");
    gets (data.nama);
    cls ();
    menuUser (data.nama);

}