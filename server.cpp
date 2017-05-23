
#include <string.h>
#include "server.h"


#define cert_path "../bcm/certificates/server2_cert.pem\0"
#define key_path  "../bcm/certificates/server2.pem\0"

CServer::CServer(){

    p_s_addr = NULL;
    p_s_addr = new sockaddr_in;

    p_cert_file = new char [strlen(cert_path) +1 ];
    p_key_file  = new char [strlen(key_path) +1 ];

    memset(p_cert_file, 0, strlen(cert_path) +1);
    memset(p_key_file, 0, strlen(key_path) +1);

    memcpy(p_cert_file,cert_path,strlen(cert_path));
    memcpy(p_key_file,key_path,strlen(key_path));
}


CServer::~CServer(){

    if(p_s_addr)
        delete(p_s_addr);
    delete(p_cert_file);
    delete(p_key_file);
}

void CServer::openListener(int port_no){

    m_port_no = port_no;
    n_socket_descriptor = socket(PF_INET, SOCK_STREAM, 0);
    memset(p_s_addr, 0, sizeof(sockaddr_in));
    p_s_addr->sin_family = AF_INET;
    p_s_addr->sin_port = htons(m_port_no);
    p_s_addr->sin_addr.s_addr = INADDR_ANY;
    if ( bind(n_socket_descriptor, (const sockaddr*) p_s_addr, sizeof(sockaddr_in)) != 0 )
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
    m_p_ctx = SSL_CTX_new(p_method);   /* create new context from method */
    if ( m_p_ctx == NULL )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
}

void CServer::loadCertificates(){

    /* set the local certificate from CertFile */
    if ( SSL_CTX_use_certificate_file(m_p_ctx, p_cert_file, SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    /* set the private key from KeyFile (may be the same as CertFile) */
    if ( SSL_CTX_use_PrivateKey_file(m_p_ctx, p_key_file, SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    /* verify private key */
    if ( !SSL_CTX_check_private_key(m_p_ctx) )
    {
        fprintf(stderr, "Private key does not match the public certificate\n");
        abort();
    }
}

void CServer::showCertificates(/*SSL *ssl*/){

    X509 *cert;
    char *line;

    cert = SSL_get_peer_certificate(m_p_ssl); /* Get certificates (if available) */
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



void CServer::serveConnection(/*SSL *ssl*/){

    /*
     * The correct sequence of calls is:
     * 1.socket
     * 2.bind
     * 3.listen
     * 4.accept
     * 5.SSL_new
     * 6.SSL_set_fd
     * 7.SSL_accept
     */
    int res = SSL_library_init();
    this->openListener(3060);
    this->initServerCTX();  //initiate p_ctx
    this->loadCertificates();


    char buf[1024];
    char reply[1024];
    const char* HTMLecho="<html><body><pre>%s</pre></body></html>\n\n";
    CProtocol *protocol = new CProtocol();
    m_connections.push_back(new t_connection(protocol,m_connections.size()));

    handleConnection();


}


void CServer::handleConnection(){

    /*
     * client - output from accept function
     * http://simplestcodings.blogspot.com/2010/08/secure-server-client-using-openssl-in-c.html
     */
    //SSL_CTX ctx;
    //m_p_ssl = SSL_new(m_p_ctx);
    //SSL_set_fd(m_ssl, n_socket_descriptor);
    this->showCertificates();

    while (1){
        p_s_client = new client_connection;
        p_s_client->p_addr_client = new sockaddr;

        p_s_client->client_descriptor = accept(n_socket_descriptor, p_s_client->p_addr_client, &p_s_client->size);

        doCommunicationWithClient(p_s_client);

        delete(p_s_client);
    }

   close(n_socket_descriptor);          /* close connection */
}


void * CServer::execute(){

    //create a struct with all session parameters
    //pass the connection to new thread
    //keep thread running until connected

    return 0;
}


void CServer::doCommunicationWithClient(client_connection * client){

    /*
     * Required parameters
     * SSL *
     * CTX *
     * socket descriptor
     * connection *
     *
     */

    SSL * ssl;
    CProtocol *prot = new CProtocol(client);
    prot->addNewThread();
}
