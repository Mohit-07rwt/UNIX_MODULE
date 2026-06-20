#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>

int fd;  // file descriptor (global so signal handler can access)

void handler(int sig)
{
    printf("\nChild: Received SIGTERM, closing file...\n");

    if(fd > 0)
        close(fd);

    printf("Child: Exiting gracefully\n");
    exit(0);
}

int main()
{
    int p[2];
    char buffer[100];

    pipe(p);

    pid_t pid = fork();

    if(pid == 0)
    {
           signal(SIGTERM, handler);

        close(p[1]);  // close write end

        // open file
        fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

        if(fd < 0)
        {
            perror("open");
            exit(1);
        }

        while(1)
        {
            int r = read(p[0], buffer, sizeof(buffer));

            if(r > 0)
            {
                write(fd, buffer, r);
                write(fd, "\n", 1);

                printf("Child: Written to file\n");
            }
        }
    }
    else
    {
           close(p[0]);  // close read end

        printf("Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);

        write(p[1], buffer, strlen(buffer));

        printf("Parent: Sent data to child\n");

        sleep(10);

        printf("Parent: Sending SIGTERM to child\n");
        kill(pid, SIGTERM);

        close(p[1]);
    }

    return 0;
}
