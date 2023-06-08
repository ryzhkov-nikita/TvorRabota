#include <curl/curl.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Функция обратного вызова для чтения данных
static size_t read_callback(void* ptr, size_t size, size_t nmemb, void* userp)
{
    const char* data = (const char*)userp;
    size_t length = strlen(data);
    size_t remaining = size * nmemb;

    if (remaining > length) {
        remaining = length;
    }

    memcpy(ptr, data, remaining);
    return remaining;
}

// Функция отправки письма на почту
void send_email(const char* from, const char* to, const char* subject, const char* body)
{
    CURL* curl;
    CURLcode res = CURLE_OK;
    struct curl_slist* recipients = NULL;
    struct curl_slist* headers = NULL;
    char error_buffer[CURL_ERROR_SIZE];

    curl = curl_easy_init();
    if (curl) {
        // Установка параметров
        curl_easy_setopt(curl, CURLOPT_URL, "smtp.gmail.com:587");
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_USERNAME, "nikitaryzhkov19092001@gmail.com");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "grulbxrputfrjndy");
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from);

        recipients = curl_slist_append(recipients, to);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        headers = curl_slist_append(headers, "Content-Type: text/plain");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_READDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error_buffer);

        // Отправка письма
        curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t)strlen(body));
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);
        curl_easy_setopt(curl, CURLOPT_READDATA, body);

        res = curl_easy_perform(curl);

        // Освобождение ресурсов
        curl_slist_free_all(recipients);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        fprintf(stderr, "Error: %s\n", error_buffer);
    }
}

int main()
{
    ifstream file0("C:/Users/TrueDetective/Documents/build-ARM-Desktop_Qt_5_12_12_MinGW_32_bit-Debug/sendmail/Debug/replace.txt");
    if (!file0.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }
    string line1;
    string fuel_type;
    while (getline(file0, line1)) {
        fuel_type += line1 + "\n";
    }
    file0.close();

    string replace_word = fuel_type;
    string search_word = "-template-";

    ifstream file_in("C:/Users/TrueDetective/Documents/build-ARM-Desktop_Qt_5_12_12_MinGW_32_bit-Debug/sendmail/Debug/example1.txt", std::ios::in);
    ofstream file_out("C:/Users/TrueDetective/Documents/build-ARM-Desktop_Qt_5_12_12_MinGW_32_bit-Debug/sendmail/Debug/temp.txt");

    if (!file_in.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string line((istreambuf_iterator<char>(file_in)), istreambuf_iterator<char>());

    size_t pos = line.find(search_word);
    while (pos != string::npos) {
        line.replace(pos, search_word.length(), replace_word);
        pos = line.find(search_word, pos + replace_word.length());
    }
    file_out << line;

    file_in.close();
    file_out.close();


    cout << "Word replaced successfully." << endl;
    const char* to = "uhbnuhbuh@gmail.com";
    const char* from = "nikitaryzhkov19092001@gmail.com";
    const char* subject = "Test email";
    ifstream file("C:/Users/TrueDetective/Documents/build-ARM-Desktop_Qt_5_12_12_MinGW_32_bit-Debug/sendmail/Debug/temp.txt", std::ios::in);
    string file_contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    const char* body = file_contents.c_str();

    send_email(from, to, subject, body);

    return 0;
}