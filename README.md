# praktikum-itp-ta

## Praktikum ITP TA

### No 1

Buatlah game PACMAN. Berikut adalah tampilan utama:

```
##########
#p.......#
#.##.###.#
..........
#.#.####.#
#.#...M..#
#.##.#.#.#
#.o#.#.#.#
##.....m.#
##########
```

Sebelum masuk game program akan memberi pilihan map yang mau dimainkan, map yang dimainkan ada 3 yaitu:

```
map 1        map 2        map 3
##########   #.########   ..........
#........#   #........#   .##....##.
#.##.###.#   #.##.###.#   .#......#.
..........   #.#....#.#   ...####...
#.#.####.#   #.#.##...#   .#.#o.#.#.
#.#......#   #...##.#.#   .#.#..#.#.
#.##.#.#.#   #.#...o#.#   ...##.#...
#.o#.#.#.#   #.###.##.#   .#......#.
##.......#   #........#   .##.##.##.
##########   #.########   ..........
```

Player\
Player adalah bidak user yang dilambangkan sebagai (p). User bisa menggerakan player dengan menggunakan WASD. Posisi awal player akan dirandom dalam map.

Musuh\
Musuh terdapat 1 jenis yaitu: (m). m adalah musuh yang bergerak random atas bawah kiri kanan. Posisi awal enemy akan dirandom

Makanan\
Makanan dilambangkan sebagai titik (.). Makanan hanya dapat dimakan oleh Player ketika player berada di satu posisi yang sama dengan makanan. Pada saat makanan dimakan maka score player akan bertambah 1.

Power Up\
Power Up dilambangkan sebagai (o). Powerup adalah makanan yang memberikan player kekuatan, pada saat powerup dimakan oleh player maka tambahkan skor player sebanyak 1, ubah bidak player (p jadi P besar) dan player akan mendapat kekuatan berupa memakan enemy. Ketika player memakan enemy maka tambahkan score player sebesar 5. Power Up hanya akan berjalan pada 10 pergerakan pertama. Ketika powerup berakhir maka kekuatan player akan terhapus dan bidak player menjadi p kecil.

```
Score: 8
##########
#........#
#.##.###.#
..........
#.#.####.#
#.#M...m.#
#.##.#.#.#
#.P#.#.#.#
##.......#
##########
```

Seperti pada pacman pada umumnya, player dan enemy tidak bisa menembus tembok. Selain itu juga terdapat fitur teleport. Ketika bidak berada pada ujung map dan hendak keluar map maka bidakakan langsung dipindahkan ke ujung lainnya.

```
Score: 53
##########
#        #
# ## ### #
p        .
# #.#### #
# #      #
# ## #.# #
#  # #.# #
##       #
##########

Score: 54
##########
#        #
# ## ### #
         p
# #.#### #
# #      #
# ## #.# #
#  # #.# #
##       #
##########
```

Ketika game over, maka program akan menampilkan skor akhir player dan pesan sesuai kondisi. Contoh jika player menang (semua makanan habis) maka program akan menampilkan "Congratulations! You Win! Final Score: 57". Contoh Jika player kalah (dimakan oleh enemy) maka program akan menampilkan "Game Over! You Lose! Final Score: 1".

### No 2

Buatlah program minimarket sederhana untuk ITP MART. Berikut adalah tampilan dari program.

```
itp mart
========
1. create transaction
2. view transaction
3. save & exit
>>>
```

Create transaction\
Pada menu ini program akan meminta inputan berupa nama customer. Setelah itu program akan meminta data barang yang dibeli oleh customer. Data barang yaitu: nama barang, harga barang dan jumlah barang. Program akan meminta barang kepada user tersebut hingga user memasukan "-" pada nama barang. Program juga terdapat pengecekan apakah harga dan jumlah barang diatas 0. Jika tidak valid maka program akan langsung meminta inputan harga / jumlah hingga inputan valid.

```
>>> 1
customer name: Davin Dj
barang #1: pensil
harga: 10000
jumlah: 1

barang #2: penghapus
harga: -10000
harga tidak valid!
harga: 20000
jumlah: 2

barang #3: penggaris
harga: 30000
jumlah: 0
jumlah tidak valid!
jumlah: 3

barang #4: -
bye :)
```

View transaction\
Pada menu ini program akan menampilkan semua transaksi yang pernah dilakukan oleh customer. Pada setiap transaksi data yang ditampilkan adalah: nama customer, semua barang yang dibeli customer beserta data barang, dan total harga keseluruhan.

```
>>> 2
Davin Dj
======================
pensil - 1 - 10000
penghapus - 2 - 20000
penggaris - 3 - 30000
----------------------
Total: 140000

Laa
======================
mochi - 10 - 5000
es krim - 1 - 7500
----------------------
Total: 57500
```

Save & exit\
Pada menu ini program akan menyimpan semua transaksi yang terdaftar ke dalam .txt dan langsung menutup program.

```
>>> 3
transaksi berhasil tersimpan!
```

Pada saat program dijalankan maka program akan meload semua transaksi yang sudah pernah disimpan dalam .txt, Jika ternyata belum ada filenya maka kondisi awal transaksi adalah kosong.
