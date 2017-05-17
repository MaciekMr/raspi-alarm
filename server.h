#ifndef SERVER_H
#define SERVER_H

#endif // SERVER_H

#include <stdio.h>
#include <string>
#include <list>
#include "connection.h"
#include "protocol.h"
//#include "thread_base.h"

using namespace std;

typedef pair<CProtocol *, int> t_connection;
typedef list<t_connection *> t_links;

class CServer:protected CConnection {

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
    sockaddr_in         *p_s_addr;
    char                *p_cert_file;
    char                *p_key_file;
    t_links             m_connections;
public:

    CServer();
    ~CServer();

    void openListener(int port_no);
    bool isRoot(){
      return(!getuid());
    }

    void initServerCTX();
    void loadCertificates();
    void showCertificates(SSL *ssl);
    void serveConnection(/*SSL *ssl*/);
    void handleConnection();

    void *execute();
};
