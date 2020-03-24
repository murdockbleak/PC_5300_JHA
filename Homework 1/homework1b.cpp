#include <iostream> 
#include <unistd.h> 
#include<sys/wait.h> 
using namespace std; 
int main() 
{ 
    cout << "P1\n" << getppid() << endl;
    pid_t P2 = fork();
    if(P2 == 0)
    {
    	for(int i=0; i<2; i++)
        cout << "P2&P3\n" << getpid() << endl;
    }
    wait(NULL);
    pid_t P3 = fork();
    if(P3 == 0)
    {
    cout << "P4\n" <<getpid() <<endl;
    }
    wait(NULL);
    return(0);
} 
