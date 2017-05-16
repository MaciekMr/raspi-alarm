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

void CServer::initServerCTX(){

    OpenSSL_add_all_algorithms();  /* load & register all cryptos, etc. */
    SSL_load_error_strings();   /* load all error messages */
    p_method = TLSv1_2_server_method();  /* create new server-method instance */
    p_ctx = SSL_CTX_new(p_method);   /* create new context from method */
    if ( p_ctx == NULL )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
}

void CServer::loadCertificates(){

    /* set the local certificate from CertFile */
    if ( SSL_CTX_use_certificate_file(p_ctx, p_cert_file, SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    /* set the private key from KeyFile (may be the same as CertFile) */
    if ( SSL_CTX_use_PrivateKey_file(p_ctx, p_key_file, SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    /* verify private key */
    if ( !SSL_CTX_check_private_key(p_ctx) )
    {
        fprintf(stderr, "Private key does not match the public certificate\n");
        abort();
    }
}

void CServer::showCertificates(SSL *ssl){

    X509 *cert;
    char *line;

    cert = SSL_get_peer_certificate(ssl); /* Get certificates (if available) */
    if ( cert != NULL )
    {
        printf("Server certificates:\n");
        line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
        printf("Subject: %s\n", line);
        free(line);
        line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
        printf("Issuer: %s\n", line);
        free(line);
        X509_free(cert);
    }
    else
        printf("No certificates.\n");
}

void CServer::serveConnection(SSL *ssl){

    char buf[1024];
    char reply[1024];
    int sd, bytes;
    const char* HTMLecho="<html><body><pre>%s</pre></body></html>\n\n";

    if ( SSL_accept(ssl) == X509_LU_FAIL )     /* do SSL-protocol accept - X509_LU_FAIL */
        ERR_print_errors_fp(stderr);
    else
    {
        showCertificates(ssl);        /* get any certificates */
        bytes = SSL_read(ssl, buf, sizeof(buf)); /* get request */
        if ( bytes > 0 )
        {
            buf[bytes] = 0;
            printf("Client msg: \"%s\"\n", buf);
            sprintf(reply, HTMLecho, buf);   /* construct reply */
            SSL_write(ssl, reply, strlen(reply)); /* send reply */
        }
        else
            ERR_print_errors_fp(stderr);
    }
    sd = SSL_get_fd(ssl);       /* get socket connection */
    SSL_free(ssl);         /* release SSL state */
    close(sd);          /* close connection */
}

void * CServer::execute(){

    //create a struct with all session parameters
    //pass the connection to new thread
    //keep thread running until connected

    return 0;
}
