#include<fcntl.h>			
#include<dirent.h>					
#include<stdio.h>						
#include<sys/stat.h>
#include<string.h>			
#include<errno.h>
#include <stdlib.h>
#include <unistd.h>
				

off_t dir_du(char * dirname, char *path)
{
	off_t dirsize=0;			
	DIR *dir;
	struct dirent *ent;				
	struct stat filstat;	
		
	dir=opendir(dirname);	
	
	int fd = open(dirname, O_RDONLY);
	
	if(fstat(fd, &filstat)==-1)	
		{
			fprintf(stderr, "Error getting info %s\n", dirname);
			exit(1);
		}
		
		
	dirsize+=filstat.st_blocks*512;
	
	close(fd);	
		
	if(chdir(dirname)==-1)		
	{
		fprintf(stderr, "Error switching to directory %s\n", dirname);
		exit(1);
	}
		
	while((ent=readdir(dir))!=NULL)
	{	
		fd=open(ent->d_name, O_RDONLY);
		
		if(fstat(fd, &filstat)==-1)	
		{
			fprintf(stderr, "Error getting info for file %s\n", ent->d_name);
			exit(1);
		}
		
		if(!S_ISDIR(filstat.st_mode))	
			dirsize+=filstat.st_blocks*512;
		else if((strcmp(ent->d_name, "..")==0)||(strcmp(ent->d_name, ".")==0))	
			continue;
		else
		{	
			
			char temp[1000];
			strcpy(temp, path);			
			dirsize+=dir_du(ent->d_name, strcat(strcat(temp, "/"), ent->d_name));
													 
		}
		
		close(fd);
			
	}
	
	printf("%ld", (long) dirsize/1024);
	printf("\t%s\n",path);
	
	if(chdir("..")==-1)			
	{
		fprintf(stderr, "Error switching to parent directory %s\n", dirname);
		exit(1);
	}
	closedir(dir);								
	return dirsize;
}			

int main(int argc, char** argv)				
{
	struct stat file;	
	off_t size;			
	char path[100];						
	
	if(argc==1)
	{
		size=dir_du(".", ".");
		return;
	}

	if(argc!=2)
	{
		printf("Format : %s <filename>\n", argv[0]);
		exit(1);
	}
	
	if(stat(argv[1], &file)<0)	
	{
		fprintf(stderr, "Error opening file %s \n", argv[1]);
		exit(1);
	}
	
	if(!S_ISDIR(file.st_mode))				
	{
		printf("%ld", (long) (512*file.st_blocks)/1024);
		printf("\t%s\n", argv[1]);
	}
	
	else 									
		size=dir_du(argv[1], argv[1]);
		
	return 0;
}


			
		
		
	
	
