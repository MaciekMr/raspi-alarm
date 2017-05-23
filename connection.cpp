#include "connection.h"

CConnection::CConnection(){

}

CConnection::CConnection(client_connection *con)
    :p_s_client(con){


}

CConnection::CConnection(CConnection * connection){

    /*this = connection;*/
    initialize(connection);

}

CConnection::~CConnection(){

}

void CConnection::initialize(CConnection * con){

    this->n_socket_descriptor = con->n_socket_descriptor;
    this->m_port_no = con->m_port_no;
    this->p_s_addr = con->p_s_addr;
    this->m_p_ssl = con->m_p_ssl;
    this->m_p_ctx = con->m_p_ctx;
}

CConnection * CConnection::operator = (CConnection * con){

    initialize(con);
    return this;
}

void CConnection::setCTX(SSL_CTX * ctx){

    this->m_p_ctx = ctx;
}

void CConnection::setSSL(SSL * ssl){

    this->m_p_ssl = ssl;
}

SSL_CTX *CConnection::getCTX(){

    return(this->m_p_ctx);
}

SSL * CConnection::getSSL(){

    return(this->m_p_ssl);
}

client_connection * CConnection::getClientCon(){

    return(this->p_s_client);
}
