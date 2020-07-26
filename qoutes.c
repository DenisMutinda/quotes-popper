#include <stdio.h>
#include <stdlib.h>

#define BUFFER 1024

void produce_notification(char notification[], char qoute[]);
 
int main(void)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	size_t read;
 
	stream = fopen("qoutes.txt", "r");
	if (stream == NULL)
		exit(EXIT_FAILURE);
 
	while ((read = getline(&line, &len, stream)) != -1) {
		//printf("Retrieved line of length %u :\n", read);
        char notification[BUFFER] = "notify-send --icon=google-chrome \"Test\" ";
		produce_notification(notification, line);
	}
 
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}

void produce_notification(char notification[], char qoute[]){
    
    strcat(notification, qoute);
    system(notification);
    printf("%s\n", notification);   

}