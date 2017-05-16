#ifndef CCONNECTION_H
#define CCONNECTION_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <utility>
#include <netinet/in.h>

/*
 * struct sockaddr_in myaddr;
 * int s;

myaddr.sin_family = AF_INET;
myaddr.sin_port = htons(3490);
inet_aton("63.161.169.137", &myaddr.sin_addr.s_addr);

s = socket(PF_INET, SOCK_STREAM, 0);
bind(s, (struct sockaddr*)myaddr, sizeof(myaddr));

*/

/*
 * Protocol structure
 * 1-st field - int  - command mode
 * 2-nd field - long - parameter
 * 3-rd field - long - add parameter
 */

struct _command{

    int     field_1;
    long    field_2;
    long    field_3;
};

class CConnection
{
protected:
    int             m_port_no;
    sockaddr_in     *p_s_addr;
public:
    CConnection();
    ~CConnection();
    int doAction();
};

#endif // CCONNECTION_H
