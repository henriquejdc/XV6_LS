//A test for the Scheduling, later become Lottery Scheduling


#include "types.h"      //maybe needed to use some types of variables
#include "user.h"       //functios like printf and syscalls

#define STDOUT 1        
#define PROCESS 40
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
        if(i<(PROCESS/4)){//1/4 das entradas
            pid=fork(100); 
        }else if(i>=(PROCESS/4) &&  i<(2*(PROCESS/4))){ //1/2 das entradas
            pid=fork(0);
        }else if(i>=(2*PROCESS/4) &&  i<(3*(PROCESS/4))){ //3/4 das entradas
            pid=fork(100); 
        }else{//ultimas entradas
            pid=fork(-10); 
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
