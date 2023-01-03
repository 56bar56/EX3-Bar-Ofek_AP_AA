//
// Created by User on 29/12/2022.
//

#include "client.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std ;
int main(int argc, char *argv[]) {
    /* const char * ip_address=argv[1];
     * int i;
     * for (i = 0; i < strlen(argv[2]); i++) {
        if (!std::isdigit(argv[2][i])) {
            std::cout << "the port isn't valid value";
            exit(1);
        }
    }
    int port = std::stoi(argv[2]);
     * const int port_no=stoi(argv[2])
     */
    const char * ip_address = "127.0.0.1" ;
    const int port_no = 5555 ;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0 ) {
        perror("error creating socket");
        exit(1);
    }
    struct sockaddr_in sin;
    memset( &sin, 0 , sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr * ) &sin, sizeof(sin)) < 0 ) {
        perror("error connecting to server");
        exit(1);
    }
    char data_addr[4096];
    char buffer[4096];
    string scanner;
    int expected_data_len = sizeof(buffer);
    int i;
    while(true) {
        getline(cin, scanner);
        for(i=0;i<scanner.size();i++) {
            data_addr[i]=scanner[i];
        }
        int data_len = strlen(data_addr);
        int sent_bytes = send(sock, data_addr, data_len, 0);
        if (sent_bytes < 0 ) {
            // error
        }
        if(data_addr=="-1") {
            break;
        }
        int read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes == 0 ) {
            // connection is closed
        }
        else if (read_bytes < 0 ) {
            // error
        }
        else {
            cout << buffer;
        }
    }

    close(sock);
    return 0 ;
}
