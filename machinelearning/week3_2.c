#include <stdio.h>
#include <math.h> 
#define etha 0.5

int x1[4]={0,0,1,1};
int x2[4]={0,1,0,1};
int target[4]={0};
double w1=2.0;
double w2=0.0;
double tetha=0.0;
int line_check[4]={0,};
double err_sum=0;
int cnt=0;

struct data{
    double w1;
    double w2;
};

void input_w1_w2_on_text_and_file_open(){
    FILE *fp;
    fp = fopen("w1w2.txt", "w");//없으면 만듦
    
    if(fp == NULL){
        printf("file open failed\n");
    }

    else{
        printf("file open success\n");
        
        for(double i=-10;i<=10;i=i+1){ 
            for(double j=-10;j<=10;j=j+1){
                    fprintf(fp,"%.1lf %.1lf\n",i,j);
            }
        }
    }
     fclose(fp);
}

void Input_tetha(){
        printf(" tetha");
        scanf("%lf",&tetha);
        printf("setha is %lf \n",tetha);
    }

void And(){
	for(int line=0;line<4;line++){
		printf("x1 is %d",x1[line]);
		printf("x2 is %d",x2[line]);
		target[line]=x1[line]*x2[line];
		printf("y is %d\n",target[line]);
	}
};

void Or(){
	for(int line=0;line<4;line++){
		printf("x1 is %d",x1[line]);
		printf("x2 is %d",x2[line]);
		target[line]=x1[line]+x2[line];
		if(target[line]>0){
			target[line]=1;
		}
		printf("y is %d\n",target[line]);
	}
};
	
void Perceptron(int x1,int x2,double w1,double w2,int target){

	double sum=0.0;
	int y_cal=0;
	sum=x1*w1+x2*w2;

	if(sum>=tetha){
    	y_cal=1;
    }
    else{
        y_cal=0;
    }  
	
	if(y_cal==target){
        printf("x1,x2 w1,w2,setha is%d %d %f %lf %lf\n",x1,x2,w1,w2,tetha);
		printf("correct\n");
	}
	else{
		printf("x1,x2 w1,w2,setha is%d %d %lf %lf %lf\n",x1,x2,w1,w2,tetha);
		err_sum=err_sum+(0.5)*(target-y_cal)*(target-y_cal);
		printf("err_desu %lf\n",err_sum);
        printf("error\n");
	}
}

void Choose_or_and(){
    int choice=4;
    printf("press 1 :or press2 :and\n");
    scanf("%d",&choice);
    if(choice==1){
        printf("or\n");
        Or();
    }
    else if(choice==2){
        printf("and\n");
        And();
    }
}

int main(){
    Choose_or_and();
    input_w1_w2_on_text_and_file_open();//ok
	Input_tetha();//ok
    FILE *fp = fopen("w1w2.txt", "r");//ok
    FILE *fp2 = fopen("err.txt", "w");//ok
    struct data data;//ok
    while(!((fscanf(fp, "%lf %lf",&data.w1,&data.w2))==EOF)){
       printf("new w1,w1\n");
        printf("w1,w2 is new %lf %lf\n",data.w1,data.w2);
        for(int i=0;i<4;i++){
            Perceptron(x1[i],x2[i],data.w1,data.w2,target[i]);
        }

    printf("w1,w2,err_sum is new %lf %lf %lf\n",data.w1,data.w2,err_sum);
    //printf("w1:%lf w2:%lf err_sum: %lf\n",w1,w2,err_sum);
    fprintf(fp2,"%.1lf\n",err_sum);
    err_sum=0;    
	}
	fclose(fp);
    fclose(fp2);
    }

	
