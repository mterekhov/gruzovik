#include <iostream>
#include <fcgio.h>
#include <string>

std::string createUI(const FCGX_Request& request) {
	return "<html><center>GRUZOVIK approaching</center></html>";
}

void launchServer() {
    std::streambuf * cin_streambuf  = std::cin.rdbuf();
    std::streambuf * cout_streambuf = std::cout.rdbuf();
    std::streambuf * cerr_streambuf = std::cerr.rdbuf();

    FCGX_Init();

    FCGX_Request request;
    FCGX_InitRequest(&request, 0, 0);
    
    while (FCGX_Accept_r(&request) == 0) {
        fcgi_streambuf cin_fcgi_streambuf(request.in);
        fcgi_streambuf cout_fcgi_streambuf(request.out);
        fcgi_streambuf cerr_fcgi_streambuf(request.err);

        std::cin.rdbuf(&cin_fcgi_streambuf);
        std::cout.rdbuf(&cout_fcgi_streambuf);
        std::cerr.rdbuf(&cerr_fcgi_streambuf);

        std::cout << createUI(request);
    }

    // restore stdio streambufs
    std::cin.rdbuf(cin_streambuf);
    std::cout.rdbuf(cout_streambuf);
    std::cerr.rdbuf(cerr_streambuf);
}

void launchDebug() {
    printf("%s\n", "<html><center>GRUZOVIK approaching</center></html>");
}

int main() {
#ifdef APPLE_DEBUG
    launchDebug();
#else
    launchServer();
#endif

    return 0;
}

