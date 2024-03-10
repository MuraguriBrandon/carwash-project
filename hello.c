#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

// Callback function to provide email data
size_t read_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    // Email subject
    const char *subject = "Subject: Test email from libcurl\n";
    size_t subject_len = strlen(subject);

    // Email body
    const char *body = "\nThis is a test email sent using libcurl.\n";
    size_t body_len = strlen(body);

    // Copy subject and body to the buffer
    size_t total_len = subject_len + body_len;
    memcpy(ptr, subject, subject_len);
    memcpy(ptr + subject_len, body, body_len);

    // Return total length
    return total_len;
}

int main(void)
{
    CURL *curl;
    CURLcode res = CURLE_OK;
    struct curl_slist *recipients = NULL;

    curl = curl_easy_init();
    if (curl) {
        // Set SMTP server and port
        curl_easy_setopt(curl, CURLOPT_URL, "smtps://smtp.gmail.com:465");

        // Set sender email and password (avoid hardcoding password)
        curl_easy_setopt(curl, CURLOPT_USERNAME, "mwangibrandon2@gmail.com");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "iybs sdgk ekyz kldx");

        // Set recipient email
        recipients = curl_slist_append(recipients, "nipsalvin@gmail.com");
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        // Set callback function to provide email data
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);

        // Perform the send operation
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        // Clean up
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }

    return (int)res;
}
