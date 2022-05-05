#include <stdio.h>
#include <math.h>
#define eta 1
#define epoch 300
#define show 0

int neuron_num=0;

double sum=0;

double first_weight[2][10]={
    {-0.5, -0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4 },//x1(0)->neuron
    {-0.5, -0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4 }//x2(1)->neuron
};

double second_weight[10][1]={{-0.5},{-0.5},{-0.5},{-0.5},{-0.5},{-0.5},{-0.5},{-0.5},{-0.5},{-0.5}};    

double input__layer_bias_weight[10]={-0.5, -0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4};

double first__layer_bias_weight=0.5;

double U[2][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};

int bias_mode=0;

double delta[2][10]={{0,},{0,}};//[layer][neuron_number]

void ChooseMode(){
    printf("choose mode 1:with bias 2:without bias\n");
    scanf("%d",&bias_mode);
    if(bias_mode==1){
        printf("with bias\n");
    }else{
        printf("without bias\n");
    }
       
}

void ChooseNeuron(){
    printf("choose the number of neuron\n");
    scanf("%d",&neuron_num);
    printf("neuron_num:%d\n",neuron_num);
}

double Sigmoid(double sum){
    double result=0;
    result=1/(1 + exp(-sum));
      return result;
}

void FeedForward(double x1,double x2,double target){
      //1st hidden layer 순회

        for(int i=0;i<neuron_num;i++){

            if(show==1){
                printf("------first layer u[0][%d]------\n",i);
                printf("first_weight[0][%d]:%lf\n",i, first_weight[0][i]);   
                printf("first_weight[1][%d]%lf\n",i, first_weight[1][i]);  
                printf("input__layer_bias_weight[%d]%lf\n",i,input__layer_bias_weight[i]);  
            }
            
            sum=x1*first_weight[0][i]+x2*first_weight[1][i];  
            
            if(bias_mode==1){
                sum=sum+1*input__layer_bias_weight[i];
            }
            
            if(show==1){
                printf("sum:%lf\n",sum);
            }

            U[0][i]=Sigmoid(sum);
            
            if(show==1){
                printf("u[0][%d] is %lf\n",i,U[0][i]);
            }
        
        }
            //last layer
        sum=0;
        for(int j=0;j<neuron_num;j++){
            if(show==1){
                printf("------result  u[1][0]------\n");
                printf("U[0][%d]:%lf\n",j,U[0][j]);
                printf("second_weight[%d][0]%lf\n",j,second_weight[j][0]);
                printf("U[0][%d]*second_weight[%d][0]:%lf\n",j,j,U[0][j]*second_weight[j][0]);   
            }
            sum=sum+U[0][j]*second_weight[j][0];
           
        }

        if(bias_mode==1){
            sum=sum+1*first__layer_bias_weight;
        }
        if(show==1){
            printf("sum:%lf\n",sum);
        }
        U[1][0]=Sigmoid(sum);
      
        if(show==1){
            printf("result:U[1][0]:%lf\n",U[1][0]);
            printf("-----feedforward end!-------------\n");
        } 
    }
  
void FeedBackward(double x1,double x2,double target){
    if(show==1){
        printf("-------------feed backward---------------\n");
    }
  
    //last delta(find delta)-ok
    delta[1][0]=(target-U[1][0])*U[1][0]*(1-U[1][0]);

    if(show==1){
        printf("updated delta[1][0]:%lf\n",delta[1][0]);
    }

    //1-layer
    for(int j=0;j<neuron_num;j++){
    
        delta[0][j]=U[0][j]*(1-U[0][j])*second_weight[j][0]*delta[1][0];
    
        if(show==1){
            printf("updated delta[0][%d]:%lf\n",j,delta[0][j]);
        }
    }

    //update second_weight
    for(int i=0;i<neuron_num;i++){
           // printf("delta weight[%d][0] %lf\n",i,eta*delta[1][0]*U[0][i]);
            second_weight[i][0]= second_weight[i][0]+eta*delta[1][0]*U[0][i];
    
            if(show==1){
                printf("updated second_weight[%d][0]:%lf\n",i,second_weight[i][0]);
            }
    
    }

    if(bias_mode==1){
    
        first__layer_bias_weight=first__layer_bias_weight+eta*delta[1][0]*1;
    
    }

    for(int i=0;i<neuron_num;i++){
        first_weight[0][i]=first_weight[0][i]+eta*delta[0][i]*x1;
        first_weight[1][i]=first_weight[1][i]+eta*delta[0][i]*x2;
        if(show==1){
            printf(" first_weight[0][%d]:%lf\n",i,first_weight[0][i]);
            printf(" first_weight[1][%d]:%lf\n",i,first_weight[1][i]);
        }
    }

    if(bias_mode==1){
        for(int i=0;i<neuron_num;i++){
            input__layer_bias_weight[i]=input__layer_bias_weight[i]+eta*delta[0][i]*1;
            if(show==1){
                printf(" input__layer_bias_weight[%d]:%lf\n",i,input__layer_bias_weight[i]);
            }
        }
    }
    if(show==1){
        printf("------backward end----------\n");
    }
 
}
  
double Error_back_propagation(double x1, double x2, double target) {
    FeedForward(x1,x2,target);
    FeedBackward(x1,x2,target);
}

void GridTest(double x1,double x2){
         //1st hidden layer 순회

        for(int i=0;i<neuron_num;i++){
            if(show==1){
                printf("------first layer u[0][%d]------\n",i);
                printf("first_weight[0][%d]:%lf\n",i, first_weight[0][i]);   
                printf("first_weight[1][%d]%lf\n",i, first_weight[1][i]);  
                printf("input__layer_bias_weight[%d]%lf\n",i,input__layer_bias_weight[i]);  
            }
            sum=x1*first_weight[0][i]+x2*first_weight[1][i];  
            
            if(bias_mode==1){
                sum=sum+1*input__layer_bias_weight[i];
            }
            
            if(show==1){
                printf("sum:%lf\n",sum);
            }

            U[0][i]=Sigmoid(sum);
            
            if(show==1){
                printf("u[0][%d] is %lf\n",i,U[0][i]);
            }
        
            
        }
            //last layer
        sum=0;
        for(int j=0;j<neuron_num;j++){
            if(show==1){
                printf("------result  u[1][0]------\n");
                printf("U[0][%d]:%lf\n",j,U[0][j]);
                printf("second_weight[%d][0]%lf\n",j,second_weight[j][0]);
                printf("U[0][%d]*second_weight[%d][0]:%lf\n",j,j,U[0][j]*second_weight[j][0]);   
            }
            sum=sum+U[0][j]*second_weight[j][0];
        }
        if(bias_mode==1){
            sum=sum+1*first__layer_bias_weight;
        }
        if(show==1){
            printf("sum:%lf\n",sum);
        }
        U[1][0]=Sigmoid(sum);
      
        if(show==1){
            printf("result:U[1][0]:%lf\n",U[1][0]);
            printf("-----gridtest end!-------------\n");
        } 
             printf("result:U[1][0]:%lf\n",U[1][0]);
            printf("-----gridtest end!-------------\n");
            if(U[1][0]>0.5){
                printf("correct\n");
            }
            else{
                printf("wrong\n");
            }
}


int main(){
    double x1,x2,target=0;
    double error=0;
    ChooseMode();
    ChooseNeuron();

    FILE *fp2 = fopen("result.txt","w"); 


    for(int i=0;i<epoch;i++){  
        FILE *fp = fopen("data.txt","r");    // hello.txt 파일을 읽기 모드로 열기.  
        error=0;
        
        if(fp == NULL){
            printf("file open failed\n");
        }

        while(!((fscanf(fp, "%lf %lf %lf \n",&x1,&x2,&target))==EOF)){
            Error_back_propagation(x1,x2,target);
            error=error+fabs(target-U[1][0]);
        }
        fclose(fp);   
        fprintf(fp2, "%d %lf\n",i,error);
    }   
    fclose(fp2);   
    FILE *grid = fopen("gird.txt","w"); 
    FILE *fp = fopen("data.txt","r");    // hello.txt 파일을 읽기 모드로 열기.  
    while(!((fscanf(fp, "%lf %lf %lf \n",&x1,&x2,&target))==EOF)){
        GridTest(x1,x2);
        if(U[1][0]>0.5){
             fprintf(grid, "%lf %lf %d\n",x1,x2,1);
        }else{
             fprintf(grid, "%lf %lf %d\n",x1,x2,0);
        }
    }
   /*
   Error_back_propagation(1,1,0);
   */
    fclose(fp);
    fclose(grid);    
}
