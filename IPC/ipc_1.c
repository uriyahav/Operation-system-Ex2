#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

//p2c= catch2
//c2p==catch
 int fd[2];
 int num = 0;
 pid_t pid ;

// ping recieved from parent to child and send
 void SIGUSR1_P2C(int sig){ 

//read the number from the pipe
    read(fd[0], &num, sizeof(num));
    printf("Child(%d) received the number: %d\n", getpid(), num);

    if( num >= 5 ){
        printf("Child is going to be terminted\n");
        kill(getppid(),SIGUSR1);
      
    }
	//add 1 to num
    num++;
	//num = num+1
	//write to pipe and alter
    write(fd[1], &num, sizeof(num));
    kill(getppid(),SIGUSR1);
    
   }
  // ping recieved from child to parent and send
 void SIGUSR1_C2P(int sig){

    //read from the pipe the number
    read(fd[0], &num, sizeof(num));
    if(num >= 5){
      printf("Parent is going to be terminted\n");
      kill(pid, SIGKILL);
      exit(0);
    }
    printf("Parent(%d) received the number: %d\n", getpid(), num);
	//add 1 to num	
	num++;
//  num = num+1;
	//write to pipe and alter
     write(fd[1], &num, sizeof(num));
     sleep(3);
     kill(pid,SIGUSR1);
    
    
}
int main()
{
  int size;

    signal(SIGUSR1,SIGUSR1_C2P);
	//create pipe
  if (pipe(fd) < 0) {
    printf("pipe failed");
    return -1;
  }
  //create son
    pid = fork();
  
  if (pid < 0) {
    printf("fork failed");
    return -1;
  }
  
  if (pid==0) {
	//we are in son proccess- child srite to pipe and alter
      signal(SIGUSR1,SIGUSR1_P2C);
      write(fd[1], &num, sizeof(num));
      kill(getppid(),SIGUSR1);
      while(1){}
    
    
    }
   else {
	//we are in parent proccess , stay untill get into son and send , then parent read from pipe
 
      while(1){}
    
  }
  //close pipe
  close(fd[0]);
  close(fd[1]);
  return 0;
}
