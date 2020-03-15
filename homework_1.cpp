#include <iostream> 
#include <unistd.h> 
#include<sys/wait.h> 
using namespace std; 
int main() 
{ 
    pid_t n1 = getpid();
    cout << "P1\n" << getppid() << endl;
    cout << "P2\n" << getpid() << endl;
    pid_t n2 = fork();

    if (n2 == 0) 
    {  
        for (int i = 0; i < 2; i++);
        {
        pid_t P3 = fork();    
        cout << "P3 & P4:\n" << getpid() <<endl;
        }
        
    }
    wait(NULL);
    return(0);
} 