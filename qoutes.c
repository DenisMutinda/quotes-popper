#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFFER 1024

char produce_notification(char notification[], char qoute[]);
int controlwhole();
 
int main(void)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	size_t read;
 
	stream = fopen("qoutes.txt", "r");
	if (stream == NULL){
		exit(EXIT_FAILURE);
    }
 
	while ((read = getline(&line, &len, stream)) != -1) {
        int sleep_time = controlwhole();
        sleep(sleep_time);
        char notification[BUFFER] = "notify-send --icon=bash \"REMEMBER\" ";
		produce_notification(notification, line);
	}
 
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}

char produce_notification(char notification[], char qoute[]){
    
    strcat(notification, qoute);
    system(notification);

}

int controlwhole(){
    int lower = 600, upper = 900; // Sleep time that ranges between 10 minutes to one quarter of an hour
    srand(time(0));
    int pause_time = (rand() % (upper - lower + 1)) + lower;
    return pause_time;
}
