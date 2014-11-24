#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "utils.h"

int main(int argc, char **argv) {
	while(1) {
		//print out shell prompt
		printf("Sauron ");
		//get line that you type in 
		char *line = NULL;
		int capacity = 0;
		getline(&line, &capacity, stdin);
		//print what the user typed in
		printf("%s\n", line);
		//actually run the user commmands

	  	cmd_struct* c = parse_command(line);
	 	print_command(c);
		
		//takes over the process and ends the loop
		//doesn't start a new processs
	
		pid_t pid = fork();

		if (pid == 0) {
			if (strcmp(c->progname, "cd")==0) {
				chdir(c->args[1]);
			}
			else {
				execvp(c->progname, c->args); }
		}
		else {
			wait(NULL);
		}

	}

//  char command[] = "ls -a -l";
 // char pipeline[] = "ls -a -l | wc -l";


 //  pipeline_struct* p = parse_pipeline(pipeline);
 //  print_pipeline(p);
 //  return 0;
}
