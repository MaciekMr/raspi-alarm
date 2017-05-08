#ifndef SERVER_H
#define SERVER_H

#endif // SERVER_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <utility>
#include <string>
#include <list>

using namespace std;

typedef pair<string, int> t_connection;
typedef list<t_connection *> t_links;

class CServer {

private:
    char                *p_destination;
    BIO                 *p_cert_bio;
    BIO                 *p_out_bio;
    X509                *p_x509_cert;
    X509_NAME           *p_cert_name;
    const SSL_METHOD    *p_method;
    SSL_CTX             *p_ctx;
    SSL                 *p_ssl;
    int                 server_no;

    int                 n_socket_descriptor;
    struct sockaddr_in  *p_sock_addr;
    int                 n_port_no;

public:

    CServer();
    ~CServer();

    void openListener(int port_no);
    bool isRoot(){
      return(!getuid());
    }

    void initServerCTX(void);
    void loadCertificates(SSL_CTX* ctx, char* CertFile, char* KeyFile);
    void showCertificates(SSL *ssl);
    void serveConnection(SSL *ssl);
};
