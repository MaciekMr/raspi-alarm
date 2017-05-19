#ifndef CCONNECTION_H
#define CCONNECTION_H


#include <unistd.h>
#include <sys/types.h>
#include <utility>
#include <netinet/in.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netdb.h>
#include <arpa/inet.h>


#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/x509_vfy.h>

struct client_connection{
    sockaddr        *p_addr_client;
    socklen_t       size;
};

class CConnection
{
protected:
    int                 m_port_no;
    sockaddr_in         *p_s_addr;
    client_connection   *p_s_client;
    SSL                 *m_ssl;
    int                 n_socket_descriptor;
public:
    CConnection();
    CConnection(CConnection *);
    ~CConnection();
protected:
    CConnection * operator = (CConnection *);
    void initialize(CConnection *);
};

#endif // CCONNECTION_H
