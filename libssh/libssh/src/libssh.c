/*
 ============================================================================
 Name        : libssh.c
 Author      : Mert PEHLİVANCIK
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <libssh/libssh.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sodium.h>
#include "free_channel.h"
#include "free_session.h"
#include "error.h"
#include "shell_session.h"
#include "new_session.h"
#include "execute_command.h"
#include "interactive_shell_session.h"
#include  "setHTTPHeader.h"
#include "report.h"
#include "server.h"
#include "ConnectServerAndSSHSession.h"
#include "recursive.h"

#define SIZE 1024
/*sudo service ssh status*/
int main(int argc, char** argv) {

	int server_port;
	char* IP;
		if (argc > 1)
			IP = argv[1];
		if (argc > 2)
			server_port = strtoul(argv[2], NULL, 10);

	//printf("Please Enter HTTP Server Port");
	recursive(server_port, IP);

	free_channel(channel);
	free_session(session);

	return 0;
}
