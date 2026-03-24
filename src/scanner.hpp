#ifndef SCANNER_H
#define SCANNER_H

#include<string>

bool scan_port(const std::string& ip, int port);

bool try_connect(const std::string& ip, int port);

bool is_host_alive(const std::string& ip);

#endif