#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// This scan for open ports
bool scan_port(const std::string& ip, int port){
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(port);

    inet_pton(AF_INET, ip.c_str(), &target.sin_addr);

    int result = connect(sock, (sockaddr*)&target, sizeof(target));

    close(sock);

    return result == 0;
}