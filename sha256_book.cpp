#include <iostream>
#include <string>
#include <curl/curl.h>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

// Callback function for cURL
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    size_t totalSize = size * nmemb;
    userp->append((char*)contents, totalSize);
    return totalSize;
}

// Function to fetch content from a URL
std::string fetch_url_content(const std::string& url) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

// Function to compute SHA-256 hash
std::string sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

int main() {
    std::string url = "https://quod.lib.umich.edu/cgi/k/kjv/kjv-idx?type=DIV1&byte=4520748";

    // Fetch the text content
    std::string text = fetch_url_content(url);

    // Normalize the text (remove excessive spaces)
    text.erase(remove(text.begin(), text.end(), '\n'), text.end());
    text.erase(remove(text.begin(), text.end(), '\r'), text.end());

    // Compute the SHA-256 hash
    std::string hash_result = sha256(text);

    // Print the SHA-256 hash of the Book of Mark
    std::cout << "SHA-256 Hash of the Book of Mark: " << hash_result << std::endl;

    return 0;
}
