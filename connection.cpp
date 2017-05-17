#include "connection.h"

CConnection::CConnection()
{

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
    this->m_ssl = con->m_ssl;
}

CConnection * CConnection::operator = (CConnection * con){

    initialize(con);
    return this;
}
