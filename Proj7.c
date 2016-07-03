#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

#define SLEEP_TIME   500000
pid_t  	parent;//parent process id
pid_t child;//child process id

static char *G_signames[] = {"NONE",
                         	"SIGHUP",
                         	"SIGINT",
                         	"SIGQUIT",
                         	"SIGILL",
                         	"SIGTRAP",
                         	"SIGABRT",
                         	"SIGEMT",
                         	"SIGFPE",
                         	"SIGKILL",
                         	"SIGBUS",
                         	"SIGSEGV",
                         	"SIGSYS",
                         	"SIGPIPE",
                         	"SIGALRM",
                         	"SIGTERM",
                         	"SIGURG",
                         	"SIGCHLD",
                         	"SIGTSTP",
                         	"SIGCONT",
                         	"SIGCHLD",
                         	"SIGTTIN",
                         	"SIGTTOU",
                         	"SIGIO",
                         	"SIGXCPU",
                         	"SIGXFSZ",
                         	"SIGVTALRM",
                         	"SIGPROF",
                         	"SIGWINCH",
                         	"SIGINFO",
                         	"SIGUSR1",
                         	"SIGUSR2",
                         	NULL};
///This method forks the current process in the cases that it is either a child or a parent.
void fork_this()
{
     pid_t  	pid;
    pid = fork();
    if(pid == 0){
   	 parent = getpid();
   	 child = pid;
    }
    else if(pid !=0){
   	 child = getpid();
   	 parent = getppid();
    }

}

void handler(int sig) {
	if (sig == 17) {
   	printf("%d has received signal %d (%s)\n",
           	getpid(),
           	sig, G_signames[sig]);
		fork_this();
    
	} 
	else if(sig == 15) {
	   	printf("%d has received signal %d (%s)\n",
           	getpid(),
           	sig, G_signames[sig]);
		if(child == getpid()){
			kill(parent,9);
			kill(child,9);
		}
		else{
			kill(child,9);
			kill(parent,9);
		}
		
	}
}


int main() {
	int    	nap = SLEEP_TIME;
	time_t 	now;
	struct tm *t;
	int    	remains = 0;
	int    	sig;
	char   	whoami[50];
	pid_t  	pid;
	int  temp;

	for (sig = 1; sig < 32; sig++) {
  	(void)signal(sig, handler);
	}
	fork_this();
	sprintf(whoami, "parent (%d)", getpid());
    
	//if (pid == 0) {
	//  sprintf(whoami, "child (%d)", getpid());
	//}
	while (1) {
    
    if(child == getpid()){
   	 temp = kill(parent, 0);
   	 if(temp == -1){
   		 fork_this();
   	 }
   	 else{
   		 usleep(SLEEP_TIME);
   	 }    
    }
    else{
   	 if (remains == 0) {
     		 now = time(NULL);
     		 t = localtime(&now);
     		 printf("%s %02d:%02d:%02d beep!\n",
              	whoami,
              	t->tm_hour, t->tm_min, t->tm_sec);
     		 remains = usleep(nap);
      
    	}
   	 else {
   	   remains = usleep(remains - 100000);
   	 }
    }
  	 
	}
	return 0;
}

