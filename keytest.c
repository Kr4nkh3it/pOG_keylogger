#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kif.h"



int main(){
	char line[8],filepath[30];//check a line of keys
	FILE *keystore;//where the keys from input are stored
	FILE *getkeys;
	keystore = fopen("keys.txt","w");//opening the file in write mode so it can be written to
	if(find(filepath)){
		puts(filepath);
		getkeys = fopen(filepath,"rw"); // opening the file in read mode so it can be read from
	}
	else{
		exit(1);
	}
	int key,keys =  0; 
	while((key=getc(getkeys))!=EOF){
		line[keys] = key;
		putc(key,keystore);
		keys++;
		if(keys >= 8)
			keys = 0;
			if(!strcmp(line,"t-series"))
				fprintf(getkeys,"pewdiepie\n");
		}
		fclose(keystore);
		fclose(getkeys);

		
		
}
