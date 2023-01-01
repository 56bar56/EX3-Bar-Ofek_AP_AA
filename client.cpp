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
     * */
    const char * ip_address = "172.26.160.1" ;
    const int port_no = 5555 ;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0 ) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset( &sin, 0 , sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr * ) &sin, sizeof(sin)) < 0 ) {
        perror("error connecting to server");
    }
    char data_addr[4096];
    char buffer[4096];
    string scanner;
    char vector[4096];
    char disKind[3];
    char k[4096];
    int expected_data_len = sizeof(buffer);
    int i=0;
    while(true) {
        i=0;
        for(int i = 0; i < strlen(vector); i++){
            vector[i] = ' ';
        }
        for(int i = 0; i < strlen(disKind); i++){
            disKind[i] = ' ';
        }
        for(int i = 0; i < strlen(data_addr); i++){
            data_addr[i] = ' ';
        }
        for(int i = 0; i < strlen(k); i++){
            k[i] = ' ';
        }
        getline(cin, scanner);
        while(!isalpha(scanner[i])) {
            vector[i] = scanner[i];
            i++;
        }
        while(isalpha(scanner[i])) {
            disKind[i] += scanner[i];
            i++;
        }
        while(i<scanner.length()) {
            k[i] += scanner[i];
            i++;
        }
        int counter1 = 0;
        for(int i = 0; i < strlen(k); i++){
            data_addr[counter1] = k[i];
            counter1++;
        }
        for(int i = 0; i < strlen(vector); i++){
            data_addr[counter1] = vector[i];
            counter1++;
        }
        for(int i = 0; i < strlen(disKind); i++){
            data_addr[counter1] = disKind[i];
            counter1++;
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
