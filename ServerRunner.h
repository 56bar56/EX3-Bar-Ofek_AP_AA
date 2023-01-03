//
// Created by newba on 29/12/2022.
//

#ifndef EX3_BAR_OFEK_AP_AA_SERVERRUNNER_H
#define EX3_BAR_OFEK_AP_AA_SERVERRUNNER_H
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include "FileClass.h"
#include "DistanceList.h"
void runServerNew(string file, int port);
int main(int argc, char *argv[]);


#endif //EX3_BAR_OFEK_AP_AA_SERVERRUNNER_H
