//
// Created by newba on 29/12/2022.
//


#include "ServerRunner.h"

using namespace std;

/**
 * a function that run our server.
 * @param fileRead the nam of the file we get
 * @param port the port we bind to
 */
void runServerNew(string fileRead, int port) {
    string lineUser;
    std::string file = fileRead;
    DistanceList list = DistanceList();
    std::ifstream myfile;
    myfile.open(file);
    std::string myline;
    if (myfile) {
        std::getline(myfile, myline);
        while (myfile) { // equivalent to myfile.good()
            list.addItem(myline);
            std::getline(myfile, myline);
        }
    } else {
        std::cout << "Couldn't open file\n";
        exit(1);
    }
    const int server_port = port;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    while (true) {
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
        bool flagStop = true;
        while (flagStop) {
            bool isValid = true;
            int j = 0;
            while (buffer[j] != '\0') {
                buffer[j] = '\0';
                j++;
            }
            j = 0;
            read_bytes = recv(client_sock, buffer, expected_data_len, 0);
            if (read_bytes == 0) {
                perror("error sending to client");
            } else if (read_bytes < 0) {
                perror("error accepting client");
            } else {
            }
            while (buffer[j] == ' ') {
                j++;
            }
            if (buffer[j++] == '-') {
                if (buffer[j++] == '1') {
                    bool ifSpace = true;
                    int i;
                    for (i = j; i < strlen(buffer) && ifSpace; i++) {
                        if (buffer[i] != ' ') {
                            ifSpace = false;
                        }
                    }
                    if (ifSpace) {
                        flagStop = false;
                    } else {
                        flagStop = true;
                    }
                }
            }
            string result;
            if (flagStop) {
                //getting vector
                int i = 0;
                while (buffer[i] == ' ') {
                    i++;
                }
                string vec = ""; //need to get the vector from the buffer
                while (isdigit(buffer[i]) || buffer[i] == ' ' || buffer[i] == '-' || buffer[i] == '.' ||
                       buffer[i] == 'E') {
                    vec += buffer[i];
                    i++;
                }
                vector<float> vector;
                if (vec == "") {
                    result = "invalid input";
                } else {


                    vector = MyVector::returnNewNumb(vec);
                    if (vector[0] == '\0') {
                        isValid = false;
                        result = "invalid input";
                    }
                    //getting distance name
                    string distanceName = ""; //need to get the distance name from the buffer
                    while (buffer[i] == ' ') {
                        i++;
                    }
                    while (isalpha(buffer[i])) {
                        distanceName += buffer[i];
                        i++;
                    }
                    while (buffer[i] == ' ') {
                        i++;
                    }
                    //we already have the file
                    //char result[4096];
                    int k;
                    string kstr = "";
                    while (buffer[i] != ' ' && buffer[i] != '\0') {
                        kstr += buffer[i];
                        i++;
                    }
                    if (kstr == "") {
                        result = "invalid input";
                        isValid = false;
                    }
                    for (i = 0; i < kstr.size(); i++) {
                        if (!std::isdigit(kstr[i])) {
                            result = "invalid input";
                            isValid = false;
                        }
                    }
                    if (isValid) {
                        k = std::stoi(kstr);
                        if (k >
                            list.getV().size()) { //if the k is a number we cant use we set him to the size of the list
                            k = list.getV().size() - 1;
                        }
                        result = FormerMainRunner(k, distanceName, vector, list);
                    }
                }
            }
            if (flagStop) {
                int i = 0;
                while (bufferReturn[i]) {
                    bufferReturn[i] = '\0';
                    i++;
                }
                for (i = 0; i < result.length(); i++) {
                    bufferReturn[i] = result[i];
                }
                int sent_bytes = send(client_sock, bufferReturn, expected_data_len2, 0);
                if (sent_bytes < 0) {
                    perror("error sending to client");
                }
            } else {
                break;
            }
        }
        close(client_sock);
    }
    close(sock);
}

/**
 * the main of the server.
 * @param argc the number of arguments
 * @param argv the arguments we get in the command line
 * @return default 1
 */
int main(int argc, char *argv[]) {
   /*string file = "iris_classified.csv";
    int port = 5555;*/

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
    return 1;
}
