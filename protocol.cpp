#include "protocol.h"

CProtocol::CProtocol()
{

}

CProtocol::CProtocol(client_connection * con)
    :CConnection(con){


}

CProtocol::~CProtocol(){


}

int CProtocol::doAction(){

    /*
     * Receive a packet of command (defined structure)
     * Decode command
     * Execute command
     * return status
     */
    _command    command;

    /* Read command from socket */


    return 0;
}


void * CProtocol::execute(){

    printf("Protocol running %p!!!\n", dynamic_cast<void *>(this));
    /*TODO:
     * missing CTX context
     */

    SSL_CTX * ctx  = getCTX();

    assert (ctx!= nullptr);

    setSSL(SSL_new(ctx));
    SSL_set_fd(getSSL(), getClientCon()->client_descriptor);
    if(SSL_accept(getSSL()) <= 0){
        printf("SSL_accept error!\n");
        ERR_print_errors_fp(stderr);
    }else{
        /*
         * Main loop to communicate with with client
         *
         * 1. Wait for hello from client
         * 2. Send ACKN/DENY - connection ok/nok
         * 3. Wait for command
         * 4. calculate cr32 of command
         * 5. Response ACKN/REPT - approved/repeat please (error)
         * 6. back to po.3
         */

    }
    char txt[] = "Hello :) \n\0";
    SSL_write(getSSL(), txt, static_cast<int>(strlen(txt)));
    int sd = SSL_get_fd(getSSL());       /* get socket connection */
    //assert(prot->getClientCon()->client_descriptor!= sd);
    SSL_free(getSSL());  /* release SSL state */
    close(getClientCon()->client_descriptor);

    return nullptr;
}
