#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string>

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

int main(){
    std::string ip = "10.71.193.158";

    std::cout << "Scanner has Started." << std::endl;

    for(int port = 1; port <= 1024; port++){
        if(scan_port(ip, port)){
            std::cout << "Port " << port << " is OPEN\n";
        }
    }

    std::cout << "Scanning Completed" << std::endl;

    return 0;
}