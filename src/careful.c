/* suicide.c --- 
 * Filename: suicide.c
 * Description: 
 * Author: harisankarh
 * Email:  harisankarh@gmail.com
 * Organization:  IIT Madras
 * Created: Fri Aug 24 22:18:34 2012 (+0530)
 * Last-Updated: Fri Aug 24 23:08:38 2012 (+0530)
 *           By: harisankarh
 *     Update #: 72
 */
#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define NORMAL       0
#define PREFAIL      1
#define SHUTDOWN     3

int main(int argc, char **argv)
{
  int ret;
  char powernode[40];
  int state;
  int pingret;
  int normaltime;
  int waittime;
  if(argc <=3)
    {
      printf("USAGE: ./suicide <IP of power node> <normal time> <wait time>");
      exit(0);
    }
  strcpy(powernode,argv[1]);
  normaltime = atoi(argv[2]);
  waittime = atoi(argv[3]);
  state = NORMAL;
  while(1)
    {
      switch(state)
	{
	case NORMAL:
	  usleep(normaltime*60*1000*1000);
	  pingret = ping(powernode);
	  if(pingret == 0)
	    {
	      state = NORMAL;
	    }
	  else
	    {
	      state=PREFAIL;
	    }
	  break;
	case PREFAIL:
	  usleep(waittime*60*1000*1000);
	  pingret = ping(powernode);
	  if(pingret == 0)
	    {
	      state = NORMAL;
	    }
	  else
	    {
	      state = SHUTDOWN;
	    }
	  break;
	case SHUTDOWN:
	  system("sudo poweroff");
	  break;
	}
    }

  return 0;
}

int ping(char* host) {
        int ret;
        char cmd[35];
        sprintf(cmd, "ping -c 3 %s > /dev/null", host);
        ret = system(cmd);
	return ret;
}
