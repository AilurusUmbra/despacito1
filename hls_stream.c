//***********************************************************//
//***********************************************************//
//***  2017F 10/22. CS Project week6                 ********//
//***  Stream 2 media with HLS on nginx.             ********//
//***  HLS is supported by Edge & Safari browser.    ********//
//***                                                ********//
//***  line 44 & 48 should set                       ********//
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
	
    //start nginx with specific configuration
	//bind port 1935 as rtmp stream input & port 80 as stream output
    system("sudo /usr/local/nginx/sbin/nginx -c /usr/local/nginx/conf/nginx.conf");
	
	//you may check whether the ports are binded correct by script "sockstat -4 -l" (IPv4)
	
    //fork 2 streaming processes
    pid_t pid;
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
	
	//stop nginx
	system("sudo /usr/local/nginx/sbin/nginx -s stop");
    
	return 0;
}
