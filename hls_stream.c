//***********************************************************//
//***********************************************************//
//***  2017F 10/22. CS Project week6                 ********//
//***  Stream 2 media with HLS on nginx.             ********//
//***  HLS is supported by Edge & Safari browser.    ********//
//***                                                ********//
//***  line 40 & 44 should set                       ********//
//***                video name and stream name      ********//
//***                                                ********//
//***  implement in 11.-1 RELEASED FreeBSD           ********//
//***                                                ********//
//***********************************************************//
//***********************************************************//



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
#define MAXLEN 1024

int main(){
    
    int status;
    system("sudo /usr/local/nginx/sbin/nginx -c /usr/local/nginx/conf/nginx.conf");
    pid_t pid;
            //simple fork
            if((pid = fork())<0){
                fprintf(stderr, "simple fork failed\n");
                exit(-1);
            }
            //child proc
            else if(pid==0){
                //simple exec
                //execvp(instr, argv1);
		system("ffmpeg -re -i 1.mp4 -vcodec libx264 -vprofile baseline -g 30 -acodec aac -strict -2 -f flv rtmp://localhost/show/stream1");
            }
            //parent proc
            else{
	        system("ffmpeg -re -i 2.mp4 -vcodec libx264 -vprofile baseline -g 30 -acodec aac -strict -2 -f flv rtmp://localhost/show/stream2 ");	    
                printf("pid=%d\n", waitpid(pid, &status, 0));
            }

    return 0;
}
