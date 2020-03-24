#include <iostream> 
#include <unistd.h> 
#include<sys/wait.h> 
using namespace std; 
int main() 
{ 
    cout << "P1\n" << getppid() << endl;
    cout << "P2\n" << getpid() << endl;
    pid_t P3 = fork();
    if(P3 == 0)
    {
        cout << "P3\n" << getpid() << endl;
    }
    wait(NULL);
    pid_t P4 = fork();
    if(P4 == 0)
    {
    cout << "P4\n" << getpid() <<endl;
    }
    wait(NULL);
    return(0);
} 