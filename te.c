#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int ar,char **args )
{
    const char* PATH = args[1];

    struct stat fileStat;
    int file=0;
    if((file=open(PATH,O_RDONLY)) < -1)
          {

    if(fstat(file,&fileStat) > 0)
        return 1;}
    else
    printf ("%d %s\n",(int) fileStat.st_blocks,PATH);

    DIR *dir = opendir(PATH);

    struct dirent *entry = readdir(dir);

    while (entry != NULL)
    {
        if ((entry->d_type == DT_DIR)){// && (strcmp(entry->d_name,"..")>0)){
             int file=0;
        if((file=open(entry->d_name,O_RDONLY)) < -1)
          {

    if(fstat(file,&fileStat) > 0)
        ;
else
    printf ("%d %s\n",(int) fileStat.st_blocks,entry->d_name);
}
}
        entry = readdir(dir);
    }

    return 0;
}



