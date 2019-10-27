 #include"readpower.h"
 
void readpower()
{
	FILE* fp;
    char ch,filename[100];
    printf("Input the file name:");
    scanf("%s",filename);
	if( access(filename, F_OK)==0 )
	{
		if(access(filename, R_OK)==0 )
		{
			printf( "File [ %s ] can be read!\n", filename);
		}
		else
		{
			printf( "File [ %s ] can not be read!\n", filename);
		}
        if( access(filename, W_OK)==0 )
		{
			printf( "File [ %s ] can be writed!\n", filename);
		}
		else
		{
			printf( "File [ %s ] can not be writed!\n", filename);
		}
        if( access(filename,X_OK )==0 )
		{
			printf( "File [ %s ] can be executed!\n", filename);
		}
		else
		{
			printf( "File [ %s ] can not be executed!\n", filename);
		}
	}
	else
	{
		printf( "File [ %s ] don't exists\n", filename);
	}
}
/*
       if(access("./access_demo.c",X_OK)==0)
       {
              printf("file can beexecuted!\n");
       }
       if(access("./access_demo.c",W_OK)==0)
       {
              printf("file can bewritten!\n");
       }
       if(access("./access_demo.c",R_OK)==0)
       {
              printf("file can beread!\n");
       }*/
