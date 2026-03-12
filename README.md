# Linux İşletim Sistemi Syslog Yönetimi

Bu proje, Linux sistem günlüklerini (syslog) simüle eden ve bu verileri **Çift Yönlü Bağlı Liste (Doubly Linked List)** veri yapısı kullanarak işleyen bir C uygulamasıdır.

## Projenin Amacı
Sistemdeki olayları (INFO, WARN, ERROR) dinamik bir şekilde hafızada tutmak, listelemek ve analiz etmek amacıyla geliştirilmiştir.

## Teknik Detaylar
- **Veri Yapısı:** Çift Yönlü Bağlı Liste (Doubly Linked List)
- **Neden Bu Yapı?** - Syslog verileri belirsiz sayıda ve sürekli aktığı için sabit boyutlu diziler yerine **dinamik bellek yönetimi** sağlayan bağlı liste tercih edilmiştir.
  - **Çift yönlü yapı** sayesinde loglar arasında hem kronolojik (baştan sona) hem de ters-kronolojik (sondan başa) hızlıca gezinebilmekteyiz. Özellikle en güncel hataları (tail) görmek için bu yapı avantajlıdır.

## Kullanılan Fonksiyonlar
- `createLogNode`: `malloc` kullanarak bellekte yeni bir log alanı oluşturur.
- `displayLogs`: Listeyi baştan sona (eskiden yeniye) yazdırır.
- `displayReverse`: Listeyi sondan başa (yeniden eskiye) yazdırır.

## Nasıl Çalıştırılır?
1. Terminali açın.
2. `gcc main.c -o syslog_app` komutu ile derleyin.
3. `./syslog_app` komutu ile çalıştırın.
