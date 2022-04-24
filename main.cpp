#include <cassert>
#include <string>
#include <curl/curl.h>

int main(int argc, char **argv)
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    assert(curl);
    curl_easy_setopt(curl, CURLOPT_URL, "https://google.de");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /**
     * Creates a CURLE_OUT_OF_MEMORY when run on Windows with WinSSL enabled.
     * OpenSSL on windows works.
     **/
    curl_easy_setopt(curl, CURLOPT_CERTINFO, 1L);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
    {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl);
    return 0;
}