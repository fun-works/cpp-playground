#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <cstring>

#define NTHREADS 50

int runStats = 1;
long pId = 0;
size_t totalThreads = 0;

#define isspace(v) (v == ' ')
#define issnewline(v) (v == '\n')

void *
dummy_thread(void *arg) {
  int id = *(int *)arg;
  totalThreads++;
  printf("Started thread: %d\n",id);
  sleep(4);
  totalThreads--;
  printf("Finished thread: %d\n",id);
  pthread_exit(NULL);  
  return (void *) 0;
}

char* trim(char*s)
{
    char *end = s + strlen(s)-1;
    while(*s && isspace(*s))
        *s++ = 0;
    while(isspace(*end))
        *end-- = 0;
    return s;
}

void trim_newline(char*s)
{
    for(size_t itr = 0; itr < strlen(s); itr++)
    {
        if(issnewline(s[itr]))
        {
            s[itr] = 0;
            break;
        }
        else
        {
            continue;
        }
    }
}

void print_status(long tgid) {
    char path[40], line[100], vmData[100] = {0}, vmRss[100] = {0}, *pVmData, *pVmRss;
    FILE* statusf;

    snprintf(path, 40, "/proc/%ld/status", tgid);

    statusf = fopen(path, "r");
    if(!statusf)
        return;

    while(fgets(line, 100, statusf)) {
        line[99] = 0;
        if(strncmp(line, "VmData:", 7) == 0)
		{
			strncpy(vmData, line + 8, 100);
			trim_newline(vmData);
			pVmData = trim(vmData);
		}
			
		if(strncmp(line, "VmRSS:", 6) == 0)
        {
			strncpy(vmRss, line + 8, 100);
			trim_newline(vmRss);
			pVmRss = trim(vmRss);	
		}
		if(pVmData == nullptr || pVmRss == nullptr)
		{
		    continue;
		}
        // Ignore "State:" and whitespace
        printf("%6d(%u Threads) VIRT: %s, RES: %s\n", tgid, totalThreads, pVmData, pVmRss);
        pVmData = pVmRss = nullptr;
        break;
    }
    fclose(statusf);
}

void *
stats_thread(void *arg) {
	while(runStats)
	{
		if(pId)
		{
			print_status(pId);
		}
		sleep(5);
	}
	return NULL;
}

int
main(int argc,char *argv[]) {
  pthread_t t[NTHREADS];
  int idx[NTHREADS];
  pthread_t statsThId;
  int sleeptime = 1;
  
  printf("Program started with pid=%d. Waiting %ds to start first thread.\n", sleeptime, getpid());
  pId = getpid();
  pthread_create(&statsThId, NULL, stats_thread, NULL);
  
  for(int i=0; i < NTHREADS; ++i) {
    sleep(sleeptime);
    idx[i] = i+1;
    (void)pthread_create(&t[i], NULL, dummy_thread, (void *) &idx[i]);
  }
  sleep(NTHREADS + 5);
  exit(EXIT_SUCCESS);
}