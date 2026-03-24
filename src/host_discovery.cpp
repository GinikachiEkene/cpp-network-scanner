#include <vector>
#include <string>
#include <cstring>
#include "scanner.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

bool try_connect(const std::string& ip, int port){
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock < 0) return false;

    sockaddr_in target{};
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &target.sin_addr);

    int result = connect(sock, (sockaddr*)&target, sizeof(target));

    close(sock);

    if (result == 0) return true;


    if (errno == ECONNREFUSED){
        return true; // host is alive, port just closed
    }

    return false;

}

// Checking for different port connections to determine that host is alive
bool is_host_alive(const std::string& ip){
    std::vector<int> common_ports = {80, 443, 22, 21};

    for(int port : common_ports){
        if(try_connect(ip, port)){
            return true;
        }
    }

    return false;
}
 
