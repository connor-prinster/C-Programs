#include <iostream>
#include <regex>

/*
 * This program shows you how you might write a regular expression to extract
 * the protocol specifier and domain name from a url
 */

// extract the protocol and domain name from a URL
std::string extractDomain(std::string url) {
    std::regex re("^http.?://[^/]+");
    std::smatch m;

    std::string ret("");

    if (std::regex_search(url, m, re)) {
        ret = m[0].str();
    }
    //std::cout << "I found '" << ret << "'\n"; // DELETE ME
    return ret;
}

int main(int, char**) {
    std::string urls[] = {
        "http://example.com",
        "http://example.com/",
        "http://example.com/walka/walka",
        "http://example.com/walka/walka/?q=derp+herkson&fimmer+fabber",
        "http://example.com/walka/walka/?q=derp+herkson&fimmer+fabber",

        "https://example.com",
        "https://example.com/",
        "https://example.com/walka/walka",
        "https://example.com/walka/walka/?q=derp+herkson&fimmer+fabber",
        "https://example.com/walka/walka/?q=derp+herkson&fimmer+fabber",
    };

    size_t len = sizeof(urls) / sizeof(std::string);
    for (size_t i = 0; i < len; ++i) {
        std::cout << urls[i] << " => '";
        std::string domain = extractDomain(urls[i]);
        std::cout << domain << "'\n";
    }
}
