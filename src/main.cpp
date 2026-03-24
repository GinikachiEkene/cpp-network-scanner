#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string>
#include"scanner.hpp"


int main(){
    std::cout << "Program has Started...\n";
    std::string ip = "10.169.14.158";

    if(is_host_alive(ip)){
        std::cout << ip << " is ALIVE\n";
    }else{
        std::cout << ip << " is NOT reachable\n";
    }

    std::cout << "Scanner has Started." << std::endl;

    for(int port = 1; port <= 1024; port++){
        if(scan_port(ip, port)){
            std::cout << "Port " << port << " is OPEN\n";
        }
    }

    std::cout << "Scanning Completed" << std::endl;

    return 0;
}