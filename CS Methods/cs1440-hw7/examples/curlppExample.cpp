/*
 *    Copyright (c) <2002-2005> <Jean-Philippe Barrette-LaPierre>
 *    
 *    Permission is hereby granted, free of charge, to any person obtaining
 *    a copy of this software and associated documentation files 
 *    (curlpp), to deal in the Software without restriction, 
 *    including without limitation the rights to use, copy, modify, merge,
 *    publish, distribute, sublicense, and/or sell copies of the Software,
 *    and to permit persons to whom the Software is furnished to do so, 
 *    subject to the following conditions:
 *    
 *    The above copyright notice and this permission notice shall be included
 *    in all copies or substantial portions of the Software.
 *    
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 *    OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 *    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 *    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 *    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 *    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <sstream>
#include <cstdlib>
#include <unistd.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

int main(int argc, char *argv[]) {

    // Visit the webpage of your choice, or Dr. Donald Knuth's homepage
    char *url = argc > 1 ? argv[1] : (char *)"http://www-cs-faculty.stanford.edu/~knuth/";

    try {

        // Create this object so that the curlpp stuff is automagically
        // cleaned-up upon termination of the program
        curlpp::Cleanup cleaner;

        // This curlpp::Easy object provides a nice, user-friendly interface to cURL
        curlpp::Easy request;

        // We configure our curlpp::Easy object by setting "options" on it.
        // Here we create a cURL URL option which will configure our easy cURL
        // object to visit our specified URL
        curlpp::options::Url curlUrl(url);

        // Setting the URL to retrive.
        request.setOpt(curlUrl);

        // We also want our cURL object to be able to follow redirects (HTTP response 3xx)
        curlpp::options::FollowLocation follow(true);
        request.setOpt(follow);


        std::cout << "Sending the request object to a stringstream" << std::endl
            << "This performs the HTTP request automatically for us," << std::endl
            << "no need to call .perform() on the request object!" << std::endl
            << "====================================================" << std::endl;
        for (int i = 3; i > 0; sleep(1), --i) 
            std::cout << i << "... " << std::flush;

        // We create a stringstream object to capture the output of the HTTP response.
        // Inserting our curlpp::Easy request object into the stream is all we need to
        // do. That's easy!
        std::ostringstream os;
        os << request << std::endl;

        // Let's put this response into a string variable:
        std::string html(os.str());
        std::cout << html << std::endl;


        return EXIT_SUCCESS;
    }
    catch ( curlpp::LogicError & e ) {
        std::cout << e.what() << std::endl;
    }
    catch ( curlpp::RuntimeError & e ) {
        std::cout << e.what() << std::endl;
    }

    return EXIT_FAILURE;
}
