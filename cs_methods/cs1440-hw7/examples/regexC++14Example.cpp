// http://www.cplusplus.com/reference/regex/regex_search/

/*
 * This program demonstrates how the C++ regular expression library works.
 *
 * It searches for the substring "sub" within a large string that contains many
 * occurrences. This is similar to what you'll do to search for hyperlinks
 * within an HTML document.
 */

#include <iostream>
#include <string>
#include <regex>

int main () {
    // TODO: put some HTML <a> tags in here for testing with the hrefRegexSource regex
    std::string haystack("this subject has a submarine as a subsequence\n"
            "subbing. submitting\n"
            "submission, substitute\n"
            "semper ubi? sub! ubi subversion"
            );

    // Here is the regex we built in class. It may not be completely correct, but it should be
    // good enough for your assignment. Do feel free to improve it, if you wish :D
    //
    std::string hrefRegexSource("<[ \n\t]*a[ \n\t]+.*href=\"(https*://)*([^/]+)*\/*([^\"]+)\"");
    
    // Here's an alternative regex with 5 capture groups which you may have better luck using:
    
    // https://bitbucket.org/snippets/hhenrichsen/xeerEd
    //regex href_re("<a .*?href=\"(((https?://)([^/]+)?|/)([^\"#]*))\".*?>"); // Hunter's regex

    std::string regexSourceCode("\\b(sub)([^ \n\t]*)");   // matches words beginning by "sub"
    std::regex needle(regexSourceCode);
    std::smatch match;

    std::cout << "Regex source code (the needle):" << regexSourceCode  << std::endl;
    std::cout << "Target sequence (the haystack): " << haystack << std::endl << std::endl;
    std::cout << "The following matches and submatches were found:" << std::endl;

    while (std::regex_search(haystack, match, needle)) {
        int i = 0;
        for (auto submatch : match) {
            // This line of code illustrates that you can use the match object as though it's an 
            // array or a map through the subscript operator []
            std::cout << "\t[" << i << "] " << match[3] << " ";
            i++;
        }
        std::cout << std::endl;
        haystack = match.suffix().str();
    }
    std::cout << std::endl;
}
