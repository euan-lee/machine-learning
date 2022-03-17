#include <stdio.h>

//텍스트 파일 읽기
//읽은 함수 데이터에 집어 넣기
//결과값 y 아웃풋 데이터에 넣기
//변수 선언
double Sum=0.0;
double w1=0.0;
double w2=0.0;
double setha=0.0;

struct data{
    double x1;
    double x2;
};
//


int F_layer_perceptron(float x1,float x2,float w1,float w2,float setha){
    printf("first layer perceptron");
    Sum=x1*w1+x2*w2;
    if(Sum>=1){
        printf("1\n");
        return 1;    
    }
    else{
        printf("0\n"); 
        return 0;
    }
  
}

void input_data_on_text_and_file_open(){
    FILE *fp;
    fp = fopen("data.txt", "w");//없으면 만듦
    
    if(fp == NULL){
        printf("file open failed\n");
    }

    else{
        printf("file open success\n");
        
        for(double i=-1.0;i<1.0;i=i+0.1){ 
            for(double j=-1.0;j<1.0;j=j+0.1){
                    fprintf(fp,"%.1lf %.1lf\n",i,j);
            }
        }
    }
     fclose(fp);
}


void input_w1_w1_setha(){
        printf("plz put w1 and w2");
        //입력값 범위 조정해줘잉
        scanf("%lf %lf %lf",&w1,&w2,&setha);
        printf("w1,w2,setha is %f %f %f",w1,w2,setha);
    }

void read_file_and_find_y(){
     
    FILE *fp_2= fopen("result.txt", "w");//없으면 만듦
    FILE *fp = fopen("data.txt", "r");    // hello.txt 파일을 읽기 모드(r)로 열기. 
    struct data data;
    if(fp == NULL){
        printf("file open failed\n");
    }
    else{
        printf("file open success (for read)\n");
        while(!((fscanf(fp, "%lf %lf",&data.x1,&data.x2))==EOF)){
            if(F_layer_perceptron(data.x1,data.x2,w1,w2,setha)){
                 fprintf(fp_2," %d\n",1);
            }else{
                fprintf(fp_2," %d\n",0);
            }
            
        }
        fclose(fp);
        fclose(fp_2);
    }                                
    
}

int main (){

    input_data_on_text_and_file_open();
  
    input_w1_w1_setha();
    
    read_file_and_find_y();
}



