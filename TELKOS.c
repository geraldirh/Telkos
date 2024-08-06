#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Customer
{
    char nama[20], pass[20],status[30];
} dataCus;

struct Owner
{
    char Namaa[20], Passs[20];
} dataOwner;

struct Kost
{
    char namakost[50], alamatkost[50], jarakkost[20], wakost[100], fasilitas[100], kapasitaskost[20];
    float hargakost;
} data;

int a, b, c, pilihanOwner;
int x = 3;
int nomor = 0;

void login();
void Customer();
void Owner();
void Admin();
void CustomerLogin(int x);
void CustomerRegist();
void OwnerLogin(int x);
void OwnerRegist();
void menuAdmin();
void menuCustomer();
void menuOwner();
void manageakun();
void lihatdaftarkos();
void lihatkoscust();
void lihatkosowner();
void lihatdaftaracc();
void hapusacc();
void lihatpenjual();
void lihatpenyewa();
void lihatjarak();
void lihatkosnama();
void TambahKost();
void PermintaanSewa();
void PassOwner();
void hapusAkunOwner();
void hapusAkunCustomer();
void carikos();
void cariKosJarak();
void cariKosNama();
void pesanKos();
void riwayatpemesanan();




int main()
{
    system("cls");
    login();
    return 0;
}

void login()
{
    system("cls");
    printf("== LOGIN ==\n");
    printf("1. Customer\n");
    printf("2. Kost Owner\n");
    printf("3. Admin\n");
    printf("4. Keluar\n");
    printf("Pilih opsi: ");
    scanf("%d", &a);
    getchar();
    switch (a)
    {
    case 1:
        Customer();
        break;
    case 2:
        Owner();
        break;
    case 3:
        Admin(3);
        break;
    case 4:
        printf("Thank You !!");
        return 0;
        break;
    default:
        printf("Data yang anda masukan tidak valid, silahkan coba kembali\n");
        login();
        break;
    }
}

void Customer()
{
    system("cls");
    printf("== Customer Menu ==\n");
    printf("1. Login\n2. Registrasi\n3. Kembali\n");
    printf("Pilih opsi: ");
    scanf("%d", &b);
    getchar();
    switch (b)
    {
    case 1:
        CustomerLogin(3);
        break;
    case 2:
        CustomerRegist();
        break;
    case 3:
        login();
        break;
    default:
        printf("Data yang anda masukan tidak valid, silahkan coba kembali\n");
        Customer();
    }
}

void CustomerLogin(int x)
{
    int login = 0;
    const int loadingTime = 3;
    if (x > 0)
    {
        system("cls");
        FILE *daftarCus = fopen("akuncus.dat", "rb");
        if (daftarCus == NULL)
        {
            printf("Error: Tidak bisa membuka file akuncus.dat.\n");
            return;
        }
        char username[50], password[50];
        printf("== LOGIN ==\n");
        printf("Masukkan Username : ");
        gets(username);
        printf("Masukkan Password : ");
        gets(password);
        printf("Loading ");
        for (int i = 0; i < loadingTime; i++)
        {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
        system("cls");
        while (fread(&dataCus, sizeof(dataCus), 1, daftarCus) == 1)
        {
            if (strcmp(username, dataCus.nama) == 0 && strcmp(password, dataCus.pass) == 0)
            {
                printf("Login berhasil!!\n");
                fclose(daftarCus);
                system("pause");
                system("cls");
                printf("Selamat Datang Tuan / Nyonya %s\n", username);
                login = 1;
                menuCustomer();
                return;
            }
        }
        fclose(daftarCus);
        if (login != 1)
        {
            printf("Username atau Password Salah, kesempatan anda tersisa %d lagi\n", x - 1);
            system("pause");
            CustomerLogin(x - 1);
        }
    }
    else
    {
        printf("Kesempatan login habis\n");
        return 0;
    }
}

void CustomerRegist()
{
    system("cls");
    printf("== Registrasi Customer ==\n");
    FILE *daftarCus = fopen("akuncus.dat", "ab");
    if (daftarCus == NULL)
    {
        printf("Error: Tidak bisa membuka file akuncus.dat.\n");
        fclose(daftarCus);
        return;
    }
    printf("Username baru : ");
    gets(dataCus.nama);
    printf("Password baru : ");
    gets(dataCus.pass);
    fwrite(&dataCus, sizeof(dataCus), 1, daftarCus);
    fclose(daftarCus);
    system("cls");
    printf("Berhasil Membuat Akun!! \n");
    system("pause");
    Customer();
}

void Owner()
{
    system("cls");
    printf("== Owner Menu ==\n");
    printf("1. Login\n2. Registrasi\n3. kembali\n");
    printf("Pilih opsi: ");
    scanf("%d", &c);
    getchar();
    switch (c)
    {
    case 1:
        OwnerLogin(3);
        break;
    case 2:
        OwnerRegist();
        break;
    case 3:
        login();
        break;
    default:
        printf("Data yang anda masukan tidak valid, silahkan coba kembali\n");
        system("pause");
        Owner();
    }
}

void OwnerRegist()
{
    system("cls");
    printf("== Registrasi ==\n");
    FILE *daftarOwner = fopen("akunOwner.dat", "ab");
    if (daftarOwner == NULL)
    {
        printf("Error: Tidak bisa membuka file akunOwner.dat.\n");
        return;
    }
    printf("Username baru : ");
    gets(dataOwner.Namaa);
    printf("Password baru : ");
    gets(dataOwner.Passs);
    fwrite(&dataOwner, sizeof(dataOwner), 1, daftarOwner);
    fclose(daftarOwner);
    system("cls");
    printf("Berhasil Membuat Akun!! \n");
    system("pause");
    Owner();
}

void OwnerLogin(int x)
{
    int login = 0;
    const int loadingTime = 4;
    if (x > 0)
    {
        system("cls");
        FILE *daftarOwner = fopen("akunOwner.dat", "rb");
        if (daftarOwner == NULL)
        {
            printf("Error: Tidak bisa membuka file akunOwner.dat.\n");
            return;
        }
        char username[50], password[50];
        printf("== LOGIN ==\n");
        printf("Masukkan Username : ");
        gets(username);
        printf("Masukkan Password : ");
        gets(password);
        printf("Loading ");
        for (int i = 0; i < loadingTime; i++)
        {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
        system("cls");
        while (fread(&dataOwner, sizeof(dataOwner), 1, daftarOwner) == 1)
        {
            if (strcmp(username, dataOwner.Namaa) == 0 && strcmp(password, dataOwner.Passs) == 0)
            {
                printf("Login berhasil!!\n");
                fclose(daftarOwner);
                system("pause");
                system("cls");
                printf("Selamat Datang Tuan / Nyonya %s\n", username);
                login = 1;
                menuOwner();
                return;
            }
        }
        fclose(daftarOwner);
        if (login != 1)
        {
            printf("Username atau Password Salah, kesempatan anda tersisa %d lagi\n", x - 1);
            system("pause");
            OwnerLogin(x - 1);
        }
    }
    else
    {
        printf("Kesempatan login habis\n");
        return 0;
    }
}

void Admin(int x)
{
    int login = 0;
    system("cls");
    char admin[100], password[100];
    printf("=== LOGIN ADMIN ===\n");
    printf("Username : ");
    gets(admin);
    printf("Password : ");
    gets(password);
    if (strcmp(admin, "admin") == 0 && strcmp(password, "admin") == 0)
    {
        printf("Login anda berhasil !!!\n");
        system("pause");
        menuAdmin();
    }
    else
    {
        if (x > 1)
        {
            printf("Login gagal, anda memiliki %d percobaan lagi!!\n", x - 1);
            Admin(x - 1);
        }
        else
        {
            printf("Anda telah melebihi batas percobaan login!!\n");
        }
    }
}

void menuAdmin()
{
    system("cls");
    printf("== MENU ADMIN ==\n");
    printf("1. Manage akun user\n");
    printf("2. Lihat daftar kos\n");
    printf("3. Kembali ke menu utama\n");
    printf("Pilih menu: ");
    int pilihan;
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
    case 1:
        manageakun();
        break;
    case 2:
        lihatdaftarkos();
        break;
    case 3:
        login();
        break;
    default:
        printf("Data yang anda masukan tidak valid, silahkan coba kembali");
        system("pause");
        menuAdmin();
        break;
    }
}

void manageakun()
{
    system("cls");
    printf("== Manage Akun User ==\n");
    printf("1. Lihat daftar akun\n");
    printf("2. Hapus akun\n");
    printf("3. Kembali ke menu admin\n");
    printf("Pilih menu: ");
    int pilihan;
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
    case 1:
        lihatdaftaracc();
        break;
    case 2:
        hapusacc();
        break;
    case 3:
        menuAdmin();
        break;
    default:
        printf("Data yang anda masukan tidak valid, silahkan coba kembali");
        system("pause");
        break;
    }
}

void lihatdaftarkos()
{
    int liatkos;
    system("cls");
    printf("1. Berdasarkan Jarak\n");
    printf("2. Berdasarkan nama\n");
    printf("3. Kembali\n");
    printf("Pilih: ");
    scanf("%d", &liatkos);
    getchar();
    switch (liatkos)
    {
    case 1:
        lihatjarak();
        break;
    case 2:
        lihatkosnama();
        break;
    case 3:
        main();
        break;
    default:
        printf("Data yang anda masukan tidak valid, silahkan coba kembali");
        system("pause");
        lihatdaftarkos();
        break;
    }
}

void lihatjarak()
{
    FILE *daftarKost;
    struct Kost kostArray[100];
    int count = 0;

    daftarKost = fopen("daftarkost.dat", "rb");
    if (daftarKost == NULL)
    {
        printf("Data belum tersedia\n");
        fclose(daftarKost);
        system("pause");
        lihatdaftarkos();   
    }
    while (fread(&kostArray[count], sizeof(struct Kost), 1, daftarKost) == 1)
    {
        count++;
    }
    fclose(daftarKost);

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(kostArray[j].jarakkost, kostArray[j + 1].jarakkost) > 0)
            {
                struct Kost temp = kostArray[j];
                kostArray[j] = kostArray[j + 1];
                kostArray[j + 1] = temp;
            }
        }
    }

    printf("Daftar Kos Berdasarkan Jarak:\n");
    for (int i = 0; i < count; i++)
    {
       printf("\nNama Kost\t= %s\nAlamat Kost\t= %s\nJarak\t= %s km\n", kostArray[i].namakost, kostArray[i].alamatkost, kostArray[i].jarakkost);
        printf("--------------------------------------------");
    }
    system("pause");
    menuAdmin();
}
void lihatkosnama()
{
    FILE *daftarKost;
    struct Kost kostArray[100];
    int count = 0;

    daftarKost = fopen("daftarkost.dat", "rb");
    if (daftarKost == NULL)
    {
        printf("Data belum tersedia\n");
        fclose("daftarkost.dat");
        system("pause");
        lihatdaftarkos();   
    }
    while (fread(&kostArray[count], sizeof(struct Kost), 1, daftarKost) == 1)
    {
        count++;
    }
    fclose(daftarKost);

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(kostArray[j].namakost, kostArray[j + 1].namakost) > 0)
            {
                struct Kost temp = kostArray[j];
                kostArray[j] = kostArray[j + 1];
                kostArray[j + 1] = temp;
            }
        }
    }

    printf("Daftar Kos Berdasarkan Nama:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s === %s === %s km\n", kostArray[i].namakost, kostArray[i].alamatkost, kostArray[i].jarakkost);
    }
    system("pause");
    menuAdmin();
}
void lihatdaftaracc()
{
    system("cls");
    printf("Anda ingin melihat akun user apa?\n");
    printf("1. Akun Penjual\n");
    printf("2. Akun Penyewa\n");
    printf("3. Kembali ke menu admin\n");
    printf("Pilih menu: ");
    int pilihan;
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
    case 1:
        lihatpenjual();
        system("pause");
        menuAdmin();
        break;
    case 2:
        lihatpenyewa();
        system("pause");
        menuAdmin();
        break;
    case 3:
        menuAdmin();
        break;
    default:
        printf("Data yang anda masukan tidak valid, silahkan coba kembali");
        system("pause");
        lihatdaftaracc();
        break;
    }
}

void lihatpenjual()
{
    FILE *daftarOwner = fopen("akunOwner.dat", "rb");
    struct Owner dataOwner[100];
    struct Owner temp;
    int count = 0;

    system("cls");

    if (daftarOwner == NULL)
    {
        printf("Error : Data belum tersedia\n");
        system("pause");
        lihatdaftaracc();
        return;
    }

    while (fread(&dataOwner[count], sizeof(struct Owner), 1, daftarOwner) == 1)
    {
        count++;
    }
    fclose(daftarOwner);

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (strcmp(dataOwner[j].Namaa, dataOwner[j + 1].Namaa) > 0) {
                temp = dataOwner[j];
                dataOwner[j] = dataOwner[j + 1];
                dataOwner[j + 1] = temp;
            }
        }
    }

    printf("Daftar Pengguna (Penjual):\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n",i+1, dataOwner[i].Namaa);
    }

    system("pause");
    lihatdaftaracc();
}

void lihatpenyewa()
{
    FILE *daftarCus = fopen("akuncus.dat", "rb");
    struct Customer dataCus[100];
    struct Customer temp;
    int count = 0;

    system("cls");

    if (daftarCus == NULL)
    {
        printf("Error: Data akun belum tersedia\n");
        system("pause");
        lihatdaftaracc();
        return;
    }

    while (fread(&dataCus[count], sizeof(struct Customer), 1, daftarCus) == 1)
    {
        count++;
    }
    fclose(daftarCus);

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (strcmp(dataCus[j].nama, dataCus[j + 1].nama) > 0) {
                temp = dataCus[j];
                dataCus[j] = dataCus[j + 1];
                dataCus[j + 1] = temp;
            }
        }
    }

    printf("Daftar Pengguna (Penyewa):\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n",i+1, dataCus[i].nama);
    }

    system("pause");
    lihatdaftaracc();
}


void hapusacc()
{
    int pilihan;
    char username[50];
    system("cls");
    printf("Hapus akun pengguna:\n");
    printf("1. Hapus akun penjual\n");
    printf("2. Hapus akun penyewa\n");
    printf("3. Kembali ke menu sebelumnya\n");
    printf("Pilih opsi: ");
    scanf("%d", &pilihan);
    getchar();

    switch (pilihan)
    {
    case 1:
        hapusAkunOwner(username);
        system("pause");
        menuAdmin();
        break;
    case 2:
        hapusAkunCustomer(username);
        system("pause");
        menuAdmin();
        break;
    case 3:
        manageakun();
        return;
    default:
        printf("pilihan tidak ada\n");
        hapusacc();
        break;
    }
}

void hapusAkunOwner(char *username)
{

    FILE *daftarOwner = fopen("akunOwner.dat", "rb");
    FILE *tempFile = fopen("temp.dat", "wb");
    system("cls");
    printf("Masukkan username penjual yang ingin dihapus: ");
    gets(username);
    if (daftarOwner == NULL || tempFile == NULL)
    {
        printf("Error: Data tidak tersedia.\n");
        system("pause");
        fclose("akunOwner");
        hapusacc();
    }

    int found = 0;
    while (fread(&dataOwner, sizeof(dataOwner), 1, daftarOwner) == 1)
    {
        if (strcmp(username, dataOwner.Namaa) != 0)
        {
            fwrite(&dataOwner, sizeof(dataOwner), 1, tempFile);
        }
        else
        {
            found = 1;
        }
    }

    fclose(daftarOwner);
    fclose(tempFile);

    remove("akunOwner.dat");
    rename("temp.dat", "akunOwner.dat");

    if (found)
    {
        printf("Akun penjual berhasil dihapus.\n");
        system("pause");
        hapusacc();
    }
    else
    {
        printf("Akun penjual tidak ditemukan.\n");
        hapusacc();
    }
    system("pause");
    hapusacc();
}

void hapusAkunCustomer(char *username)
{
    FILE *daftarCus = fopen("akuncus.dat", "rb");
    FILE *tempFile = fopen("temp.dat", "wb");

    printf("Masukkan username penyewa yang ingin dihapus: ");
    gets(username);

    if (daftarCus == NULL || tempFile == NULL)
    {
        printf("Error: Tidak bisa membuka file.\n");
        system("pause");
        hapusacc();
        return;
    }

    int found = 0;
    while (fread(&dataCus, sizeof(dataCus), 1, daftarCus) == 1)
    {
        if (strcmp(username, dataCus.nama) != 0)
        {
            fwrite(&dataCus, sizeof(dataCus), 1, tempFile);
        }
        else
        {
            found = 1;
        }
    }

    fclose(daftarCus);
    fclose(tempFile);

    remove("akuncus.dat");
    rename("temp.dat", "akuncus.dat");

    if (found)
    {
        printf("Akun penyewa berhasil dihapus.\n");
        system("pause");
        hapusacc();
    }
    else
    {
        printf("Akun penyewa tidak ditemukan.\n");
        system("pause");
        hapusacc();
    }
    system("pause");
    hapusacc();
}
void menuCustomer()
{
    system("cls");
    int menuCust;
    printf("== MENU CUSTOMER ==\n");
    printf("1. Melihat daftar Kos\n");
    printf("2. Mencari Kos\n");
    printf("3. Pemesanan Kos\n");
    printf("4. Riwayat pemesanan Kos\n");
    printf("5. Keluar\n");
    printf("Pilih: ");
    scanf("%d", &menuCust);
    getchar();
    switch (menuCust)
    {
    case 1:
        lihatkoscust();
        break;
    case 2:
        carikos();
        break;
    case 3:
        pesanKos();
        break;
    case 4:
        lihatRiwayatPesanan();
        break;
    case 5:
        login();
        break;
    default:
        exit(0);
    }
}

void pesanKos() {
    system("cls");
    FILE *daftarKost, *pesanan_file;
    char nama_file[30];
    int jumlah, i, no;
    char uname[30];

    printf("Masukkan username Anda: ");
    gets(uname);

    strcpy(nama_file, uname);
    strcat(nama_file, "_pesanan.dat");

    pesanan_file = fopen(nama_file, "ab");
    if (pesanan_file == NULL) {
        printf("Error: Tidak bisa membuka file %s.\n", nama_file);
        return;
    }

    daftarKost = fopen("daftarkost.dat", "rb");
    if (daftarKost == NULL) {
        printf("Error: Tidak bisa membuka file daftarkost.dat.\n");
        fclose(pesanan_file);
        return;
    }

    printf("Daftar Kos:\n");
    int count = 0;
    while (fread(&data, sizeof(struct Kost), 1, daftarKost) == 1) {
        printf("\n%d. Nama Kost\t= %s\nAlamat Kost\t= %s\nJarak Kost\t= %s km\nHarga Kost\t= Rp %.3f\n", count + 1, data.namakost, data.alamatkost, data.jarakkost, data.hargakost);
        printf("--------------------------------------------------------------------");
        count++;
    }

    printf("\nMasukkan jumlah kamar kos yang ingin dipesan: ");
    scanf("%d", &jumlah);

    int pesanan[jumlah];
    for (i = 0; i < jumlah; i++) {
        printf("Pilih kos yang ingin dipesan (masukkan nomor): ");
        scanf("%d", &no);
        pesanan[i] = no;
    }

    fseek(daftarKost, 0, SEEK_SET);

    printf("\nPesanan Anda telah berhasil ditambahkan!\nTotal Pesanan:\n");
    printf("-----------------\n");
    printf("Jumlah = %d\n", jumlah);
    printf("Kos yang dipesan:\n");
    count = 0;
    while (fread(&data, sizeof(struct Kost), 1, daftarKost) == 1) {
        for (i = 0; i < jumlah; i++) {
            if (count + 1 == pesanan[i]) {
                strcpy(dataCus.status, "Belum Di Konfirmasi");
                fwrite(&data, sizeof(data), 1, pesanan_file);
                strcpy(dataCus.nama, uname);  
                fwrite(&dataCus, sizeof(dataCus), 1, pesanan_file);
                printf("%d. %s === %s === %s km === Rp %.3f === Status: %s\n", pesanan[i], data.namakost, data.alamatkost, data.jarakkost, data.hargakost, dataCus.status);
            }
        }
        count++;
    }
    printf("-----------------\n");
    system("pause");
    fclose(pesanan_file);
    fclose(daftarKost);
    menuCustomer();
}

void lihatRiwayatPesanan() {
    FILE *pesanan_file;
    char nama_file[30];
    char uname[30];
    system("cls");
    printf("Masukkan username Anda: ");
    gets(uname);

    strcpy(nama_file, uname);
    strcat(nama_file, "_pesanan.dat");

    pesanan_file = fopen(nama_file, "rb");
    if (pesanan_file == NULL) {
        printf("Error: Tidak bisa membuka file %s.\n", nama_file);
        return;
    }

    printf("Riwayat Pesanan:\n");
    printf("-----------------\n");
    while (fread(&data, sizeof(struct Kost), 1, pesanan_file) == 1 && fread(&dataCus, sizeof(struct Customer), 1, pesanan_file) == 1) {
        printf("%s === %s === %s km === Rp %.3f === Status: %s\n", data.namakost, data.alamatkost, data.jarakkost, data.hargakost, dataCus.status);
    }
    printf("-----------------\n");
    fclose(pesanan_file);
    system("pause");
    menuCustomer();
}

void lihatkoscust()
{
    FILE *daftarKost;
    struct Kost kostArray[100];
    int count = 0;

    daftarKost = fopen("daftarkost.dat", "rb");
    if (daftarKost == NULL)
    {
        printf("Data belum tersedia\n");
        fclose("daftarkost.dat");
        system("pause");
        lihatdaftarkos();
    }
    while (fread(&kostArray[count], sizeof(struct Kost), 1, daftarKost) == 1)
    {
        count++;
    }
    fclose(daftarKost);
    system("cls");
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(kostArray[j].jarakkost, kostArray[j + 1].jarakkost) > 0)
            {
                struct Kost temp = kostArray[j];
                kostArray[j] = kostArray[j + 1];
                kostArray[j + 1] = temp;
            }
        }
    }

    printf("Daftar Kos Berdasarkan Jarak:\n");
    for (int i = 0; i < count; i++)
    {
       printf("Nama Kost\t= %s\nAlamat Kost\t= %s\nJarak\t\t= %s km\n", kostArray[i].namakost, kostArray[i].alamatkost, kostArray[i].jarakkost);
    printf("----------------------------------------------------------------------------------\n");
    }
    system("pause");
    menuCustomer();
}
void lihatkosowner(){
    system("cls");
    FILE *daftarKost;
    struct Kost kostArray[100];
    int count = 0;

    daftarKost = fopen("daftarkost.dat", "rb");
    if (daftarKost == NULL)
    {
        printf("Data belum tersedia\n");
        fclose("daftarkost.dat");
        system("pause");
        lihatdaftarkos();   
    }
    while (fread(&kostArray[count], sizeof(struct Kost), 1, daftarKost) == 1)
    {
        count++;
    }
    fclose(daftarKost);

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(kostArray[j].jarakkost, kostArray[j + 1].jarakkost) > 0)
            {
                struct Kost temp = kostArray[j];
                kostArray[j] = kostArray[j + 1];
                kostArray[j + 1] = temp;
            }
        }
    }

    printf("Daftar Kos Berdasarkan Jarak:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Nama Kost\t= %s\nAlamat Kost\t= %s\nJarak\t\t= %s km\n", kostArray[i].namakost, kostArray[i].alamatkost, kostArray[i].jarakkost);
        printf("----------------------------------------------------------------------------------");
    }
    system("pause");
    menuOwner();
}
void carikos()
{
    int pilihanCari;
    system("cls");
    printf("Cari Kos berdasarkan:\n");
    printf("1. Nama\n");
    printf("2. Jarak\n");
    printf("Pilih opsi: ");
    scanf("%d", &pilihanCari);
    getchar();

    switch (pilihanCari)
    {
    case 1:
        cariKosNama();
        break;
    case 2:
        cariKosJarak();
        break;
    default:
        printf("Pilihan tidak valid, silakan coba lagi.\n");
        system("pause");
        carikos();
        break;
    }
}

void cariKosNama()
{
    FILE *daftarKost;
    struct Kost kostArray[100];
    int count = 0;

    daftarKost = fopen("daftarkost.dat", "rb");
    if (daftarKost == NULL)
    {
        printf("TIDAK ADA FILE\n");
        return;
    }

    while (fread(&kostArray[count], sizeof(struct Kost), 1, daftarKost) == 1)
    {
        count++;
    }
    fclose(daftarKost);

    char namaKost[50];
    printf("Masukkan nama kos yang ingin dicari: ");
    gets(namaKost);

    printf("Hasil pencarian untuk kos dengan nama \"%s\":\n", namaKost);
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcasecmp(kostArray[i].namakost, namaKost) == 0)
        {
            printf("%s === %s === %s km === Rp %.3f\n", kostArray[i].namakost, kostArray[i].alamatkost, kostArray[i].jarakkost, kostArray[i].hargakost);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Tidak ada kos yang cocok dengan kriteria pencarian.\n");
    }

    system("pause");
    menuCustomer();
}

void cariKosJarak()
{
    FILE *daftarKost;
    struct Kost kostArray[100];
    int count = 0;

    daftarKost = fopen("daftarkost.dat", "rb");
    if (daftarKost == NULL)
    {
        printf("TIDAK ADA FILE\n");
        return;
    }

    while (fread(&kostArray[count], sizeof(struct Kost), 1, daftarKost) == 1)
    {
        count++;
    }
    fclose(daftarKost);

    char jarakKost[20];
    printf("Masukkan jarak kos yang ingin dicari (dalam km): ");
    gets(jarakKost);

    printf("Hasil pencarian untuk kos dengan jarak \"%s km\":\n", jarakKost);
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(kostArray[i].jarakkost, jarakKost) == 0)
        {
            printf("%s === %s === %s km === Rp %.3f\n", kostArray[i].namakost, kostArray[i].alamatkost, kostArray[i].jarakkost, kostArray[i].hargakost);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Tidak ada kos yang cocok dengan kriteria pencarian.\n");
    }

    system("pause");
    menuCustomer();
}

void menuOwner()
{
    system("cls");
    printf("== MENU OWNER ==\n");
    printf("1. Tambahkan Kost\n");
    printf("2. Permintaan Penyewaan\n");
    printf("3. Lihat Daftar Kos\n");
    printf("4. Ubah Password\n");
    printf("5. Keluar\n");
    printf("Pilih: ");
    scanf("%d", &pilihanOwner);
    getchar();
    switch (pilihanOwner)
    {
    case 1:
        TambahKost();
        break;
    case 2:
        PermintaanSewa();
        break;
    case 3:
        lihatkosowner();
    break;
    case 4:
        PassOwner();
        break;
    case 5:
        login();
        break;
    default:
        printf("Data yang anda inputkan tidak valid, silahkan coba ulangi\n");
        menuOwner();
        break;
    }
}

void TambahKost()
{
    FILE *Kost = fopen("daftarkost.dat", "ab");
    if (Kost == NULL)
    {
        printf("Error: Tidak bisa membuka file daftarkost.dat.\n");
        fclose("daftarkost.dat");
        return;
    }
    system("cls");
    printf("== Data Kost ==\n");
    printf("Masukkan Nama Kost anda\t\t\t\t: ");
    gets(data.namakost);
    printf("Masukkan Alamat Kost\t\t\t\t: ");
    gets(data.alamatkost);
    printf("Jarak Dari Kost Dengan Telkom (dalam km)\t: ");
    gets(data.jarakkost);
    printf("Nomor WhatsApp\t\t\t\t\t: ");
    gets(data.wakost);
    printf("Fasilitas (deskripsikan)\t\t\t: ");
    gets(data.fasilitas);
    printf("Harga per tahun\t\t\t\t\t: ");
    scanf("%f", &data.hargakost);
    getchar();
    printf("Kapasitas kos\t\t\t\t\t: ");
    gets(data.kapasitaskost);
    fwrite(&data, sizeof(data), 1, Kost);
    fclose(Kost);
    system("cls");
    printf("Anda berhasil menambahkan kost >_<\n");
    system("pause");
    menuOwner();
}

void PermintaanSewa() {
    FILE *approve, *approve2;
    char dicari[20];
    int menu;
    char tempStatus[50];
    char nama_file[30];

    system("cls");
    printf("============================================================\n");
    printf("------------------------ TELKOS -------------------------\n");
    printf("============================================================\n");

    printf("Masukkan Username akun yang ingin diupdate status: ");
    gets(dicari);

    strcpy(nama_file, dicari);
    strcat(nama_file, "_pesanan.dat");

    approve = fopen(nama_file, "rb");
    if (approve == NULL) {
        printf("Error: Tidak bisa membuka file %s.\n", nama_file);
        return;
    }

    approve2 = fopen("_pesanan2.dat", "wb");
    if (approve2 == NULL) {
        printf("Error: Tidak bisa membuka file sementara.\n");
        fclose(approve);
        return;
    }

    printf("Pilih Status Pesanan kos Baru:\n");
    printf("1. Diterima\n");
    printf("2. Ditolak\n");
    printf("Pilih menu: ");
    scanf("%d", &menu);
    getchar();
    switch (menu) {
        case 1:
            strcpy(tempStatus, "Diterima");
            system("cls");
            break;
        case 2:
            strcpy(tempStatus, "Ditolak");
            system("cls");
            break;
        default:
            printf("Pilihan tidak valid.\n");
            fclose(approve);
            fclose(approve2);
            menuOwner();
            return;
    }

    while (fread(&data, sizeof(data), 1, approve) == 1 && fread(&dataCus, sizeof(struct Customer), 1, approve) == 1) {
        if (strcmp(dataCus.nama, dicari) == 0) {
            strcpy(dataCus.status, tempStatus);
        }
        fwrite(&data, sizeof(data), 1, approve2);
        fwrite(&dataCus, sizeof(dataCus), 1, approve2);
    }

    fclose(approve);
    fclose(approve2);

    remove(nama_file);
    rename("_pesanan2.dat", nama_file);

    printf("Update Status Berhasil\n");
    system("pause");
    system("cls");
    menuOwner();
}

void PassOwner()
{
    system("cls");
    char username[50], new_pass[20];
    printf("Ubah Password\n");
    printf("Masukkan Username : ");
    gets(username);
    printf("Masukkan Password Baru : ");
    gets(new_pass);

    FILE *daftarOwner = fopen("akunOwner.dat", "rb");
    FILE *tempFile = fopen("temp.dat", "wb");

    int found = 0;
    while (fread(&dataOwner, sizeof(dataOwner), 1, daftarOwner) == 1)
    {
        if (strcmp(username, dataOwner.Namaa) == 0)
        {
            strcpy(dataOwner.Passs, new_pass);
            fwrite(&dataOwner, sizeof(dataOwner), 1, tempFile);
            found = 1;
        }
        else
        {
            fwrite(&dataOwner, sizeof(dataOwner), 1, tempFile);
        }
    }

    fclose(daftarOwner);
    fclose(tempFile);

    remove("akunOwner.dat");
    rename("temp.dat", "akunOwner.dat");

    if (found)
    {
        printf("Password berhasil diubah untuk pengguna: %s\n", username);
    }
    else
    {
        printf("Username tidak ditemukan.\n");
    }
    system("pause");
    menuOwner();
}