#include <curl/curl.h>


static size_t write_data(void *content, size_t size, size_t nmemb,
                             struct str *str)
{
    size_t total_size = size*nmemb;

    str->data = realloc(str->data, str->len + total_size + 1);
    if (!str->data)
    {
        printf("Not enough memory to realloc");
        return 0;
    }

    memcpy(&(str->data[str->len]), content, total_size);
    str->len += total_size;
    str->data[str->len] = 0;

    return total_size;
}

int https_get(char *url, char *buffer)
{
    CURL *curl;

    CURLcode result = curl_global_init(CURL_GLOBAL_ALL);
    if(result != CURLE_OK)
        return (int)result;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data); //Callb
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

        result = curl_easy_perform(curl);
    }
    curl_easy_cleanup(curl);

    curl_global_cleanup();
}
