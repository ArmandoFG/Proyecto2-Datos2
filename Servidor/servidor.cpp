#include <string>
using namespace std;

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Templo.h"
#include "Matrix.h"

#define PORT 12345

#include <poll.h>          // For poll()



int strf(char **rbuf);
string DatosEnviar;
Templo* templo=new Templo;
/**
 * @return void
 * Metodo que maneja las llamadas del cliente
 */
void manageCalls(int socket,int server_fd, struct sockaddr_in address, int addrlen){
    std::ofstream outfile ("datos.json",std::ofstream::binary);
    char buffer[4096];
    string message;
    read(socket, buffer, 4096);
    message = buffer;
    int len = message.length();
    outfile.write(buffer, len);
    outfile.close();

    templo->startCiclo();

    char *rbuf;
    int len2 = strf(&rbuf);
    cout<<rbuf<<endl;
    send(socket, rbuf, len2, 0);

}



/**
 * Main para el programa, inicializa el server
 */
int main()
{

    auto p= Matrix::toMatrixPosition(0,0,5, Matrix::generateMatrix5());
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0)
    {
        perror("Socket has failed");
        exit(EXIT_FAILURE);
    }

    bool socketToPort= setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt));
    if (socketToPort)
    {
        perror("Port not asigned to the socket");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    int bindResult = bind(server_fd, (struct sockaddr *)&address,sizeof(address));
    if (bindResult<0)
    {
        perror("Bind has failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("Listening has failed");
        exit(EXIT_FAILURE);
    }
    int socket;
    while(true) {
        socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen);
        templo=new Templo;
        while (true) {
            manageCalls(socket, server_fd, address, addrlen);
        }
    }
    return 0;
}

/**
 *
 *
 * @param rbuf Datos del json
 * @return int tamaño del json
 */

int strf(char **rbuf){

    int len;
    std::ifstream is;
    is.open ("datos.json", std::ios::binary);
    is.seekg (0, std::ios::end);
    len = is.tellg();
    is.seekg (0, std::ios::beg);
    *rbuf = new char [len];
    is.read (*rbuf, len);
    is.close();
    return len;
}

