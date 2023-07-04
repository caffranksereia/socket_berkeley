// ConsoleApplication1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include "iostream"
#include <winsock.h>
using namespace std;

#define PORT 9090;
struct sockaddr_in srv;
int main()
{   
    int nRet = 0;
    //Initialize the WSA variables
    WSADATA ws;
    int nStatus = WSAStartup(MAKEWORD(2, 2), &ws);
    if (nStatus < 0)
    {
        cout << endl << "WSA Failed to initialize";
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << endl << "WSA initialized";
    }

    //initialize the socket tcp
    int nSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (nSocket < 0)
    {
        cout << endl << "The socket not opened";
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << endl << "The socket opened successfully " << nSocket;
    };

   

    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = INADDR_ANY;
    srv.sin_port = htons(9090);
    memset(&(srv.sin_zero), 0, 8);

    nRet = bind(nSocket,(sockaddr*)&srv,sizeof(sockaddr));
    if (nRet < 0) {
        cout << endl << "Fail to bind to local port";
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << endl << "SucessFuly bind to local port" << nRet;
    }
    return 0;
}

