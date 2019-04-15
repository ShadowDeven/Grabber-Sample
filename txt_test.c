#include <stdio.h>
#include <string.h>
#define MAXCHR   80

char ln[MAXCHR];

int main() {
    
    FILE *f_txt;
    FILE *f_random;
    FILE *f_mutation;
    FILE *f_crossover;
    
    int case_num=-1;
	int j, k, i;
	int flag = -1;
    double cover;
    int count=1;

	
    f_txt=fopen("log-5.txt","r");
    f_random=fopen("random.txt","w");
    f_mutation=fopen("mutation.txt","w");
    f_crossover=fopen("crossover.txt","w");
    
    if (NULL==f_txt) {
        printf("Can not open file log.txt!\n");
        return 1;
    }
    
    while (1) {
        
        if (NULL==fgets(ln, MAXCHR, f_txt)) break;
        
        if (0==strcmp(ln,"stage 1:\n")){
            flag = 0;}
        else if (0==strcmp(ln,"stage 2:\n")){
        	flag = 1;}
        else if (0==strcmp(ln,"stage 3:\n")){
         	flag = 2;}
        
        if(3==sscanf(ln,"I:0, Grans:1 ,covered size:%d ,total:%d, coverage:%lf",&j,&i,&cover)){
            printf("%d %lf\n",count,cover);
            count++;
            
        }

        if (flag==0){
            if (2 == sscanf (ln,"Find uncovered pairs: cwnd:%d ssth:%d",&j,&i))
                //if(k==3)
                    fprintf(f_random,"%d\t%d\n",j,i);}
        else if (flag==1){
        	if (2 == sscanf (ln,"Find uncovered pairs: cwnd:%d ssth:%d",&j,&i))
        		//if(k==3)
                    fprintf(f_mutation,"%d\t%d\n",j,i);}
        else if (flag==2){
        	if (2 == sscanf (ln,"Find uncovered pairs: cwnd:%d ssth:%d",&j,&i))
        		//if(k==3)
                    fprintf(f_crossover,"%d\t%d\n",j,i);}
    }
    
    fclose(f_txt);
    fclose(f_random);
    fclose(f_mutation);
    fclose(f_crossover);

    return 0;
}
