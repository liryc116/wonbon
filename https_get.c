#include <curl/curl.h>

int https_get(char *url, char *buffer)
{
    CURL *curl;

    CURLcode result = curl_global_init(CURL_GLOBAL_ALL);
    if(result != CURLE_OK)
        return (int)result;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        result = curl_easy_perform(curl);
    }
    curl_easy_cleanup(curl);

    curl_global_cleanup();
}
