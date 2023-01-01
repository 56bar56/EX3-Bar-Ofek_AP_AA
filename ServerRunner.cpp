//
// Created by newba on 29/12/2022.
//

#include "ServerRunner.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include "FileClass.cpp"
#include "DistanceList.cpp"
using namespace std;

void runServerNew(string file, int port){
    const int server_port = port ;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0 ) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset( &sin, 0 , sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock, (struct sockaddr * ) &sin, sizeof(sin)) < 0 ) {
        perror("error binding socket");
    }
    while(true) {
        if (listen(sock, 5) < 0) {
            perror("error listening to a socket");
        }
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        char buffer[4096];
        char bufferReturn[4096];
        int expected_data_len = sizeof(buffer);
        int expected_data_len2 = sizeof(bufferReturn);
        int read_bytes;
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        //k cant be negetive
        bool flag = true;
        while (flag) {
            read_bytes = recv(client_sock, buffer, expected_data_len, 0);
            if (read_bytes == 0) {
                perror("error sending to client");
            } else if (read_bytes < 0) {
                perror("error accepting client");
            } else { //just to see the information the server get.
                cout << buffer;
            }
            //send with some defineder between like : k&vector&distance
            //getting k
            int k;
            if (buffer[0] == '-') {
                if (buffer[1] == '1') {
                    flag = false;
                } else {
                    k = int(buffer[1]);
                    k = k * -1;
                }
            } else {
                int counter = 0;
                while(buffer[counter] != ' '){
                    counter++;
                }
                string kstr = "";
                for(int i = 0; i <= counter; i++){
                    kstr += buffer[i];
                }
                k = std::stoi(kstr);
            }
            string result;
            if (k > 0 && flag) {
                //getting vector
                int i = 2;
                string vec = ""; //need to get the vector from the buffer
                while (isdigit(buffer[i]) || buffer[i] == ' ' || buffer[i] == '-' || buffer[i] == '.') {
                    vec += buffer[i];
                    i++;
                }
                vector<float> vector;
                vector = MyVector::returnNewNumb(vec);
                //getting distance name
                string distanceName = ""; //need to get the distance name from the buffer
                distanceName += buffer[i] + buffer[i + 1] + buffer[i + 2];
                //we already have the file
                //char result[4096];
                result = FormerMainRunner(k, distanceName, vector, file);
            } else {
                result = "invalid input";
            }
            if (flag) {
                for (int i = 0; i < result.length(); i++) {
                    bufferReturn[i] = result[i];
                }
                int sent_bytes = send(client_sock, bufferReturn, expected_data_len2, 0);
                if (sent_bytes < 0) {
                    perror("error sending to client");
                }
            }
        }
        close(client_sock);
    }
    close(sock);
}
int main(int argc, char *argv[]) {
    string file = argv[1];
    int i;
    for (i = 0; i < strlen(argv[2]); i++) {
        if (!std::isdigit(argv[2][i])) {
            std::cout << "the port isn't valid value";
            exit(1);
        }
    }
    int port = std::stoi(argv[2]);
    runServerNew(file, port);
}