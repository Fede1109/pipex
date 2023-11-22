/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:44:40 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/22 17:25:39 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main (int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 5)
		ft_error();
	while (argv[0][i])
		i++;
	ft_init_pipe();
	// ft_execve();
}

// //*DUP2
// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>

// int main()
// {
// 	int fd;
 
// 	fd = open("./src/example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
// 	dup2(fd, STDOUT_FILENO);
// 	close(fd);
// 	printf("This is printed in example.txt!\n");
 
// 	return (0);
// }

//*ACCESS
// #include <stdio.h>
// #include <unistd.h>
 
// int main()
// {
// 	if (access("./src/example.txt", R_OK) != -1)
// 		printf("I have permission\n");
// 	else
// 		printf("I don't have permission\n");
 
// 	return (0);
// }

//* EXECVE
// #include <unistd.h>
// #include <stdio.h>
 
// int main()
// {
// 	char *args[3];
 
// 	args[0] = "ls";
// 	args[1] = "-l";
// 	args[2] = NULL;
// 	execve("/bin/ls", args, NULL);
// 	printf("This line will not be executed.\n");
 
// 	return (0);
// }

//* FORK
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
 
// int main()
// {
// 	pid_t pid;
 
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
 
// 	if (pid == 0)
// 		printf("This is the child process. (pid: %d)\n", getpid());
// 	else
// 		printf("This is the parent process. (pid: %d)\n", getpid());
 
// 	return (0);
// }

//*FORK + EXECVE
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
 
// int main()
// {
// 	pid_t pid;
// 	char *args[3];
 
// 	pid = fork();
// 	// pid = -1;
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
//  	args[0] = "ls";
// 	args[1] = "-la";
// 	args[2] = NULL;
// 	if (pid == 0)
// 		printf("This is the child process. (pid: %d)\n", getpid());
// 	else
// 		printf("This is the parent process. (pid: %d)\n", getpid());
// 	execve("/bin/ps", args, NULL);
 
// 	return (0);
// }

//*PIPE
/* 
The array pipefd is used to
return two file descriptors referring to the ends of the pipe.
pipefd[0] refers to the read end of the pipe.  pipefd[1] refers
to the write end of the pipe.
*/
/* #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main()
{
	int fd[2];
	pid_t pid;
	char buffer[13];
 
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
 
	if (pid == 0)
	{
		close(fd[0]); // close the read end of the pipe		
		printf("a\n");
		write(fd[1], "Hello parent!", 13);
		close(fd[1]); // close the write end of the pipe
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]); // close the write end of the pipe
		read(fd[0], buffer, 13);
		close(fd[0]); // close the read end of the pipe
		printf("Message from child:'%s'\n", buffer);
		exit(EXIT_SUCCESS);
	}
}  */

//*UNLINK
/* 
#include <stdio.h>
#include <unistd.h>
 
int main()
{
	if (unlink("./src/example.txt") == 0)
		printf("File successfully deleted");
	else
		printf("Error deleting file");
 
	return (0);
} */

//*WAIT
/* #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main(void)
{
	pid_t pid;
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		printf("I am the child process.\n");
		sleep(2);
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("I am the parent process.\n");
		wait(NULL);
		printf("Child process terminated after a 2s delay.\n");
	}
 
	return (EXIT_SUCCESS);
} */