#include <sys/socket.h>
#include <resolv.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/x509_vfy.h>

#include "server.h"


CServer::CServer(){

    p_sock_addr = NULL;
    p_sock_addr = new sockaddr_in;
}


CServer::~CServer(){

    if(p_sock_addr)
        delete(p_sock_addr);
}

void CServer::openListener(int port_no){

    n_port_no = port_no;
    n_socket_descriptor = socket(PF_INET, SOCK_STREAM, 0);
    memset(p_sock_addr, 0, sizeof(sockaddr_in));
    p_sock_addr->sin_family = AF_INET;
    p_sock_addr->sin_port = htons(n_port_no);
    p_sock_addr->sin_addr.s_addr = INADDR_ANY;
    if ( bind(n_socket_descriptor, (const sockaddr*) p_sock_addr, sizeof(sockaddr_in)) != 0 )
    {
        perror("can't bind port");
        abort();
    }
    if ( listen(n_socket_descriptor, 10) != 0 )
    {
        perror("Can't configure listening port");
        abort();
    }
}
