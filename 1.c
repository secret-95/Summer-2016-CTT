#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//-----------------------------------------------------------------------------------------
#define N 5
#define maxsize 16
FILE *fp1,*fp2,*fp3;
//-----------------------------------------------------------------------------------------
//PRINT ADDRESSES IN A FILE INTIALLY
void fileinput(int a[N][N], int b[N][N], int c[N][N])
{
	int i,j,k,*p,*q,*r;
    fp1=fopen("cache.txt","w");
	for(i=0;i<N;i++)
	for(j=0;j<N;j++)
	{
		c[i][j]=0;
		for(k=0;k<N;k++)
		{
			c[i][j]+=a[i][k]*b[k][j];
			p=&a[i][j];
			q=&b[i][j];
			r=&c[i][j];
			fprintf(fp1,"%p\n",p);
	    	fprintf(fp1,"%p\n",q);
	    	fprintf(fp1,"%p\n",r);
	    }
	}
	fclose(fp1);
}
//-----------------------------------------------------------------------------------------
//PRINTS TAG VALUES IN A FILE "tag.txt"
void modmaxsize(long long unsigned int decimal)
{
//	fp3=fopen("tag.txt","a");
	int modmaxsize;
	modmaxsize=decimal%maxsize;
//	fprintf(fp3,"%d\n",mod8);
//	fclose(fp3);
	printf("%d--\n",modmaxsize);
}
//-----------------------------------------------------------------------------------------
//TO GENERATE A^B USED IN "hex()" FUNCTION
long long unsigned int power(int x,long long unsigned int y)
{
    if( y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);
 
}
//-----------------------------------------------------------------------------------------
//CONVERT HEX TO DEC
void hex(char hexa[12])
{
	long long unsigned int i,val,decimal=0,len;
	len=strlen(hexa);
	len--;
	for(i=0; hexa[i]!='\0'; i++)
    {
        
        switch(hexa[i])
        {
            case '0':
                val = 0;
                break;
            case '1':
                val = 1;
                break;
            case '2':
                val = 2;
                break;
            case '3':
                val = 3;
                break;
            case '4':
                val = 4;
                break;
            case '5':
                val = 5;
                break;
            case '6':
                val = 6;
                break;
            case '7':
                val = 7;
                break;
            case '8':
                val = 8;
                break;
            case '9':
                val = 9;
                break;
            case 'a':
            case 'A':
                val = 10;
                break;
            case 'b':
            case 'B':
                val = 11;
                break;
            case 'c':
            case 'C':
                val = 12;
                break;
            case 'd':
            case 'D':
                val = 13;
                break;
            case 'e':
            case 'E':
                val = 14;
                break;
            case 'f':
            case 'F':
                val = 15;
                break;
        }
 
        decimal += val * power(16, len);
        len--;
    }
    modmaxsize(decimal);
}

//-----------------------------------------------------------------------------------------
//GENERATES ADDRESS IN HEX FROM FULL ADDRESS 
void generate(char buf[15])
{
	char tempbuf[12];
	int i;
	for (i = 0; i < 12; ++i)
	tempbuf[i]=buf[i+2];
	printf("%s---\t",tempbuf );
	hex(tempbuf);

}
//-----------------------------------------------------------------------------------------
//BASICALLY CALLS OTHER FUNCTIONS
void functioncall()
{
	char buf[15];
	fp2=fopen("cache.txt","r");
	if (fp2) 
	{
    	while (fscanf(fp2, "%s", buf)!=EOF)
    	generate(buf);       	
	}	
	fclose(fp2);
}
//-----------------------------------------------------------------------------------------
//MAIN
int main()
{
	int a[N][N],b[N][N],c[N][N];	
	//1
	fileinput(a,b,c);	//FUNCTION TO INPUT RANDOM ADDRESSES INTO A FILE "cache.txt"
    functioncall();		//CALLS OTHER FUNCTION BASICALLY
	return 0;
}
//-----------------------------------------------------------------------------------------
