#include "csapp.h"

int main(){
    
    int n;
    rio_t rio;
    char buf[MAXBUF];
    Rio_readinitb(&rio, STDIN_FILENO);
    while ((n = Rio_readnb(&rio, buf, MAXBUF)) != 0) {
        Rio_writen(STDOUT_FILENO, buf, n);
    }
    return 0;
}