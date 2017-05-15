//A test for the Scheduling, later become Lottery Scheduling


#include "types.h"      //maybe needed to use some types of variables
#include "user.h"       //functios like printf and syscalls

#define STDOUT 1        
#define PROCESS 30
#define T 112345678

void tempo(){ //função para gastar tempo 
    int i,j;
    i=j=T;
    while(j--){}
    while(i--){}
}

int main(){
    int pid;
    int i;
    for (i=0;i<PROCESS;i++){ //cria processos filhos
        if(i<(PROCESS/3)){//fork do int 1 
            pid=fork(1); 
        }else if(i>=(PROCESS/3) &&  i<(2*(PROCESS/3))    ){ //fork do int 4
            pid=fork(4);
        }else{
            pid=fork(8); //fork do int  8
        }if(pid == 0){
            tempo(); //gasta tempo
            exit();
        }
        
    }
    //while (wait() != -1);
    while(1){
        pid=wait();
        if(pid<0)break;
        printf(STDOUT,"Processo filho %d acabou\n",pid );
        
    }
    
    
    exit();
}
