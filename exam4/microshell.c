#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

//fd_msg
void fd_msg(char *str)
{
	while (*str)
		write(2, str++, 1);
}

//cd
//i !=2 -> err
//chdir fail -> err
int cd(char *av[], int i)
{
	if (i != 2)
		return (fd_msg("error: cd: wrong argument\n"), 1);
	if (chdir(av[1]) == -1)
	{
		fd_msg("error: cd: cannot change directory to ");
		fd_msg(av[i]);
		fd_msg("\n");
		return (1);
	}
	return (0);
}
	
//set_pipe
//fail -> exit(1)
void set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		fd_msg("error: fatal\n"), exit(1);
}

//exec
//no pipe, just cd -> call cd
//has pipe, pipe fail -> err
//fork fail -> err
//in child process (!pid) loop 
//child process stop -> back to mother process -> waitpid, set_pipe
//return (WIFEXITED(status) && WEXITSTATUS(status));
int exec(char *av[], int i, char *env[])
{
	int has_pipe;
	int fd[2];
	int pid;
	int status;

	has_pipe = av[i] && !strcmp(av[i], "|");
	if (!has_pipe && !strcmp(*av, "cd"))
		return (cd(av, i));
	if (has_pipe && pipe(fd) == -1)
		fd_msg("error: fatal\n"), exit(1);
	if ((pid = fork()) == -1)
		fd_msg("error: fatal\n"), exit(1);
	if (!pid)
	{
		av[i] = 0; //set NULL
		set_pipe(has_pipe, fd, 1);
		if (!strcmp(*av, "cd"))
			exit(cd(av, i));
		execve(*av, av, env);
		fd_msg("error: cannot execute "), fd_msg("*av"), fd_msg("\n"), exit(1);
	}
	waitpid(pid, &status, 0);
	set_pipe(has_pipe, fd, 0);
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

//main
//loop av[i]
//|, ; -> i++;
int main(int ac, char *av[], char *env[])
{
	int status = 0;
	int i = 0;

	(void)ac;
	while (av[i])
	{
		av += i + 1;
		i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (i)
			status = exec(av, i, env);
	}
	return (status);
}

/* ------------------------------- TEST --------------------------------------

						> Commands that should work <

Simple command execution:
./a.out /bin/echo Hello, World!
Expected output: Hello, World!

--
Change directory with cd:
./a.out cd /tmp ";" /bin/pwd
Expected output: /tmp

--
Piping between commands:
./a.out /bin/echo Hello, World! "|" /usr/bin/grep World
Expected output: Hello, World!

--
Multiple pipes:
./a.out /bin/echo Hello, World! "|" /usr/bin/tr ' ' '\n' "|" /usr/bin/grep Hello
Expected output: Hello

--
Multiple commands with pipes and separators:
./a.out /bin/echo Hello ";" /bin/echo World "|" /usr/bin/grep o
Expected output:
Hello
World

--
Chaining commands with ;:
./a.out /bin/echo First command ";" /bin/echo Second command
Expected output:
First command
Second command

--
Complex pipeline with mixed commands:
./a.out /bin/echo "microshell is cool" "|" /usr/bin/grep microshell "|" /usr/bin/wc -c ";" /bin/echo "Done"
Expected output:
19 (or any number of characters counted)
Done

"microshell": 10 characters
" is cool": 8 characters (space before "is" is also counted)
Newline \n: 1 character

						> Commands that shouldn;t work <

Incorrect usage of cd:
./a.out cd
Expected output: error: cd: bad arguments
--

Nonexistent directory with cd:
./a.out cd /nonexistent_directory
Expected output: error: cd: cannot change directory to /nonexistent_directory

--
Nonexistent executable:
./a.out /nonexistent_command
Expected output: error: cannot execute /nonexistent_command

*/