#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int pause(){
	int status;
	wait(&status);
	return status;
}

int main(){
	pid_t child_pid;
	int status;
	printf("O meu ID e (pai): %d\n", (int) getpid());
	printf("Criando um processo filho (ligando o despertador)\n");
	child_pid = fork();

	if(child_pid != 0){//Se for o pai
		printf("PAI: Vou dormir enquanto meu despertador não toca...\n");
		status = pause();
		printf("PAI: Opa, hora de acordar!\n");
		return 0;
	} else{
		printf("-------------------------------\n");
		printf("FILHO: Executando com id %d\n", (int) getpid());
		printf("FILHO: despertador tocando em 5 segundos...\n");
		sleep(5);
		printf("FILHO: VAI PAI!\n");
		printf("------------------------------\n");
		return 0;
	}

	return 0;
}