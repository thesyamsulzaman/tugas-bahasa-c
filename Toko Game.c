
#include <stdio.h>

struct produk {
  char nama[100];
  int harga;
};

void spasi() {
  printf("\n");
}

void tukar(struct produk *t1, struct produk *t2) {
  struct produk temp = *t1;
  *t1 = *t2;
  *t2 = temp;
}

void buatDaftarProduk( struct produk array[], int panjangArray ) {

  printf("Id \t Nama \t \t \t Harga \n");
  printf("__ \t ____ \t \t \t _____ \n"); spasi();

  for (int i = 0; i < panjangArray; i++) {
    printf("%d \t %s \t %d \n", i, array[i].nama, array[i].harga);
  }
}


int sequentialSearch(struct produk array[], int n, int val) {
  int i; 
  for (i = 0; i < n; i++) {
    if (val == i) return i;
  }
  return -1;
}




int main() {

  typedef struct produk Game;

  Game sekiro            = {  "Sekiro,Duakiro      ", 28000 };
  Game detroit           = {  "Detroit Become Human", 30000 };
  Game the_walking_dead  = {  "The Walking Dead    ", 25000 };  
  Game resident_evil     = {  "Resident Evil       ", 16000 };
  Game god_of_war        = {  "God Of War          ", 17000 };
  Game dragon_age        = {  "Dragon Age          ", 94000 };
  Game skyrim            = {  "Skyrim              ", 20000 };
  Game lego              = {  "Lego Jurrasic World ", 16000 };
  Game call_of_duty      = {  "Call of duty        ", 27000 };

  struct produk daftar_produk[100] = {
    sekiro, detroit, the_walking_dead, resident_evil, 
    god_of_war, dragon_age, skyrim, lego, call_of_duty
  };


  struct produk keranjang_belanja[100]; 
  struct produk *pointer_keranjang_belanja = &keranjang_belanja[0];
  int jumlah_barang_keranjang_belanja = 0;
  int total_keranjang_belanja = 0;

  int produk_id;
  int checkout = 0;
  int sortType = 1;



  spasi();
  printf("Pilih Tampilan Daftar Produk \n");
  printf("0 : Dari yg termahal sampai yang termurah \n");
  printf("1 : Dari yang termurah sampai yang termahal \n");
  printf("Pilih [0 = Menurun / 1 = Menanjak ] : ");
  scanf("%d", &sortType);
  spasi();
  

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8 - (i + 1) ; j++ ) {
      if ( sortType == 0 ) {
        if (daftar_produk[j].harga < daftar_produk[j + 1].harga) {
          tukar(&daftar_produk[j], &daftar_produk[j + 1]);
        }
      }
      if ( sortType == 1 ) {
        if (daftar_produk[j].harga > daftar_produk[j + 1].harga) {
          tukar(&daftar_produk[j], &daftar_produk[j + 1]);
        }
      }
      
    }
  }

  while(checkout != 1) {

    buatDaftarProduk(daftar_produk, 8); spasi();

    printf("\t \t \t \t Keranjang Belanja : %d \n", jumlah_barang_keranjang_belanja); spasi();

    printf("TRANSAKSI - Pilih id produk yng ingin dibeli : ");
    scanf("%d", &produk_id);



    if (sequentialSearch(daftar_produk, 8, produk_id) == produk_id) {
      printf("TRANSAKSI - Ditambahkan %s  \n", daftar_produk[produk_id].nama);
      keranjang_belanja[jumlah_barang_keranjang_belanja] = daftar_produk[produk_id];
      jumlah_barang_keranjang_belanja++;
    } else {
      printf("TRANSAKSI - Produk dengan id %d tidak ditemukan", produk_id);
      spasi();
    }

    spasi();

    printf("Selesai Belanja ? [ya = 1 / tidak = 0] : ");
    scanf("%d", &checkout); spasi();
  }


  printf("-----------------------------------------------------"); spasi();
  printf("                 Keranjang Belanja               \n"); 
  printf("-----------------------------------------------------"); spasi();
  spasi();


  buatDaftarProduk(keranjang_belanja, jumlah_barang_keranjang_belanja);
  spasi();
  printf("-----------------------------------------------------"); spasi();

  struct produk *pointerKeranjangBelanja = &keranjang_belanja[0];

  for (int i = 0; i < jumlah_barang_keranjang_belanja; i++) {
   total_keranjang_belanja += (int) (pointerKeranjangBelanja + i)->harga;
  }

  spasi();
  printf("\t \t   Total Harga         : %d \n", total_keranjang_belanja);


  int lunas = 0;
  int bayar = 0;


  printf("\t \t   Masukan Jumlah Uang : ");
  scanf("%d", &bayar);


  printf("\t \t   Anda Membayar       : %d \n", bayar);
  printf("\t \t   Kembalian           : %d \n", bayar - total_keranjang_belanja);

  spasi();
  printf("-----------------------------------------------------"); spasi();
  printf("           Terima Kasih telah Bertransaksi ^_^ \n");
  printf("-----------------------------------------------------"); spasi();
  spasi();
  







  return 0;
}


