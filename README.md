# Esp-32-Minecraft-server-status
Monitoring Minecraft server status using esp32 and LCD display

Deskripsi Proyek:
Proyek ini adalah implementasi sederhana untuk menampilkan status server Minecraft pada LCD 16x2 menggunakan Arduino. Proyek ini memungkinkan Anda untuk melihat status server Minecraft, seperti apakah server sedang online, berapa jumlah pemain yang online, dan daftar pemain yang sedang online. data ini diambil dari endpoint api yang diberikan oleh https://mcstatus.io/

Komponen Utama:

    LCD 16x2 dengan I2C: LCD digunakan untuk menampilkan informasi server Minecraft dengan tampilan teks yang mudah dibaca.
    Arduino atau ESP8266/ESP32: Mikrokontroler ini digunakan untuk mengendalikan LCD dan berkomunikasi dengan server Minecraft melalui API.

Fitur Utama:

    Tampilan Status Server: LCD akan menampilkan status server Minecraft, termasuk apakah server online atau offline, IP server, dan port yang digunakan.
    Daftar Pemain Online: Jika server Minecraft sedang online, LCD akan menampilkan daftar pemain yang sedang online.

Cara Kerja:

    Arduino atau ESP8266/ESP32 terhubung ke server Minecraft melalui API untuk mengambil status server dan daftar pemain.
    Data JSON dari server Minecraft diurai dan ditampilkan pada LCD.
    LCD akan menampilkan status server dan daftar pemain online.
    Setelah menampilkan daftar pemain, LCD akan kembali menampilkan status server.

Cara Penggunaan:

    Sambungkan komponen yang LCD 16x2 dengan I2C dan  ESP8266/ESP32.
    anda bisa mengikuti tutorial dari sini "https://randomnerdtutorials.com/esp32-esp8266-i2c-lcd-arduino-ide/"
    Unggah kode yang telah disediakan ke Arduino atau ESP8266/ESP32.
    Sesuaikan konfigurasi proyek untuk mengakses server Minecraft yang diinginkan.
    untuk api url anda bisa mengambil dari sini "https://mcstatus.io/"
    atau mengunakan https://api.mcstatus.io/v2/status/java/yourServerip:portoraddress
    

Catatan:

    Pastikan untuk mengganti nilai variabel response dalam kode dengan respons JSON aktual dari API server Minecraft yang Anda gunakan.
    Anda mungkin perlu menginstal pustaka ArduinoJson dan LiquidCrystal_I2C jika belum terinstal.

Powered By chatGPT
