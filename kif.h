#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int find(char *s){
	char *indevfile = "/proc/bus/input/devices";
	FILE *idf = fopen(indevfile,"r");
	char string[21],event[8],rep[6] = "event",filepath[30] = "/dev/input/";
	int c,count = 0,keyboard_found = 0,event_found = 0,i,e;
	while((c=getc(idf)) != EOF && !keyboard_found){
		string[count++] = c;
		if(count == 20){
			string[++count] = '\0';
			if(strstr(string,"Keyboard") != NULL || strstr(string,"keyboard") != NULL)
				keyboard_found = 1;
			count = 0;
		}
	}
	if(keyboard_found){
		while((c=getc(idf)) != EOF && !event_found){ 
			string[count++] = c;
			if(count == 19){ 
				string[++count] = '\0';
				if(strstr(string,"event") != NULL || strstr(string,"Event") != NULL){
					for(i=3,e=0;i<19&&e<5;i++)
						if(string[i] == rep[e]){
							event[e] = string[i];
							e++;
						}
					for(;i<11;)
						event[e++] = string[i++];
					event[++e] = '\0';
					strcat(filepath,event);
					event_found = 1; 
					fclose(idf); 
					strcpy(s,filepath);
					return 1;
				}
				count = 0;
			}
		}
	}
	fclose(idf);
	return 0;
}	
