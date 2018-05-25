#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <unistd.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

void crawlWrapper(std::string passUrl, int maxDepth, int currentDepth, std::map<std::string, int> &passMap);
std::string curlifyTheUrl(std::string url);
std::map<std::string, int> changeMap(std::string url, int timesSeen, std::map<std::string, int> passMap);   //erik
std::string extractDomain(std::string url); //erik

int main(int argc, char** argv) 
{
    //--------------------------------------------//
    //     variables changable with arguments     //
    //--------------------------------------------//
    std::string url = "http://cs.stanford.edu";
    int maxDepth = 3;
    //--------------------------------------------//
    
    //--------------------------------------//
    //     Dealing with extra arguments     //
    //--------------------------------------//
    if (argc > 1)
    {
        url = argv[1];
    }
    if (argc > 2)
    {
        maxDepth = atoi(argv[2]);
    }
    //--------------------------------------//
    
    //----------------------------------//
    //     for recursive assignment     //
    //----------------------------------//
    
    std::map<std::string, int> passMap; //origMap;
    passMap[url] = 1;//origMap[url] = 1;
    std::cout << "Recursively crawling the web to a depth of " << maxDepth << " links beginning from \n" << url << std::endl;
    crawlWrapper(url, maxDepth, 0, passMap); //origMap); //will call the function which will then recursively follow all links from there
    //----------------------------------//
    //===============================================//
    return 0;
}

std::string curlifyTheUrl(std::string url)
{
    try
    {   
        //--------------------------------------------------------------//
        //   If curlpp works, it will be lit and just need this try()   //
        //--------------------------------------------------------------//
        curlpp::Cleanup cleaner;
        curlpp::Easy request;
        curlpp::options::Url curlUrl(url);
        request.setOpt(curlUrl);
        curlpp::options::FollowLocation follow(true);
        request.setOpt(follow);
    
        std::ostringstream os;  //creates os
        os << request << std::endl; //fills os
        
        std::string html(os.str());
    
        return html; //creates the string 'html' based on the str() contents of os
        //--------------------------------------------------------------//
    }
    catch(curlpp::LogicError & e)   //it broke this way
    {
        std::cout << e.what() << std::endl;
    }
    catch(curlpp::RuntimeError e)   //it broke this other way
    {
        std::cout << e.what() << std::endl; 
    }
    
    return "Something Went Wrong\n";    //must return something or face destruction
}

void crawlWrapper(std::string url, int maxDepth, int currentDepth, std::map<std::string, int> &passMap)
{
    if(maxDepth == currentDepth) return;    //base case
    currentDepth++; //increment to avoid infinite loop
    std::string parentDomain = extractDomain(url);  //pulls the *.*.* out of the url
    std::string html = curlifyTheUrl(url); //
    
    std::string regexSourceCode("<\\s*a.*href=[\"|'](https?://)?([^# ]+?)[\"|']");
    std::regex needle(regexSourceCode); //the proverbial needle in the haystack
    std::smatch match;  //the regex match
    
    while (std::regex_search(html, match, needle)) 
    {
        std::string urlToBeCleansed;
        if(match.str(1) == "")
        {
            urlToBeCleansed = parentDomain + match.str(2);
        }
        else
        {
            urlToBeCleansed = match.str(1) + match.str(2);
        }
        
        if(passMap.count(urlToBeCleansed) > 0)
        {
            passMap = changeMap(urlToBeCleansed, 1, passMap);
        }
        else
        {
            passMap = changeMap(urlToBeCleansed, 1, passMap);
            for(int i = 1; i < currentDepth; i++)
            {
                std::cout << "    ";
            }
            std::cout << urlToBeCleansed << std::endl;
            crawlWrapper(urlToBeCleansed, maxDepth, currentDepth, passMap);
        }
        html= match.suffix().str(); //the most important line of code in this whole assignment that I forgot for *HOURS*
    }
}

std::map<std::string, int> changeMap(std::string url, int timesSeen, std::map<std::string, int> passMap)    //erik's code
{
    if(passMap.count(url) > 0)
    {
        passMap[url] += 1;
    }
    else
    {
        passMap[url] = timesSeen;
    }
    return passMap;
}

std::string extractDomain(std::string url)  //erik's code
{
    std::regex re("^http.?://[^/]+");
    std::smatch m;

    std::string ret("");

    if (std::regex_search(url, m, re)) 
    {
        ret = m[0].str();
    }
    return ret;
}