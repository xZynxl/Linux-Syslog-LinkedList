#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* * TEKNİK AÇIKLAMA: 
 * Neden Çift Yönlü Bağlı Liste? 
 * Syslog verileri sürekli eklenen verilerdir. Çift yönlü liste sayesinde
 * hem en eski kayıttan en yeniye, hem de en yeni hatadan geriye doğru 
 * hızlıca gezinebiliriz (O(1) zaman karmaşıklığı ile son düğüme erişim).
 */
// Düğüm yapısı: Her bir log kaydını temsil eder
typedef struct LogNode {
    int logID; // Kayıt numarası
    char timestamp[32]; // Zaman bilgisi
    char level[12];     // INFO, ERROR, WARN , hata seviyesi
    char message[256]; // Mesaj içeriği
    struct LogNode* next; // Sonraki düğümün adresi
    struct LogNode* prev; // Önceki düğümün adresi
} LogNode;

// Yeni bir log düğümü oluşturma fonksiyonu
LogNode* createLogNode(int id, const char* level, const char* msg) {
    LogNode* newNode = (LogNode*)malloc(sizeof(LogNode));
    newNode->logID = id;
    strcpy(newNode->level, level);
    strcpy(newNode->message, msg);
    
    // Zaman damgasını otomatik ekle
    time_t now = time(NULL);
    strftime(newNode->timestamp, 32, "%Y-%m-%d %H:%M:%S", localtime(&now));
    
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Listeyi ekrana yazdırma (Baştan Sona)
void displayLogs(LogNode* head) {
    LogNode* temp = head;
    printf("\n--- SISTEM GUNLUKLERI (SYSLOG) ---\n");
    while (temp != NULL) {
        printf("[%s] ID: %d | SEVIYE: %s | MESAJ: %s\n", 
                temp->timestamp, temp->logID, temp->level, temp->message);
        temp = temp->next;
    }
}

int main() {
    // Liste başı
    LogNode* head = createLogNode(1, "INFO", "Sistem baslatildi.");
    
    // Manuel bir iki log daha ekleyelim (Örnek amaçlı)
    LogNode* log2 = createLogNode(2, "ERROR", "Baglanti hatasi olustu.");
    head->next = log2;
    log2->prev = head;

    // Logları göster
    displayLogs(head);

    return 0;

}
