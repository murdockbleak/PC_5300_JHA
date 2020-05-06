#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<sys/types.h>
#include<unistd.h> 

  
int main(int argc, char *argv[]) 
{  
    int p[2];    
    pid_t pid; 
  	char *a = argv[1]; 
    int n = atoi(a);
    if (pipe(p) < 0) 
        exit(1); 
    if ((pid = fork()) > 0)
    {   
        close(p[0]);
    	//printf("give a number:");
    	//atoi(argv[1],"%d", &n);
        write(p[1], &n, 100); 
        close(p[1]); 
        wait(NULL);  
    } 
  
    else if (pid ==0)
    { 
        close(p[1]);
        //int n; 
        float sum;
        read(p[0], &n, 100);
        int sign = 1;
    	for (int i = 0; i < n; ++i) 
    	{           
        sum += sign/(2.0*i+1.0);
        sign *= -1;
    	}
        printf("%lf\n",4*sum);
    }  
    return 0; 
} 
