#include <stdio.h>
#include <math.h>
#include <time.h>
#define epoch 1

int hidden=0;
int output_count=0;
int bias = 1;
double eta = 0.025;

int hidden_N[10] = {0,0,0,0,0,0,0,0,0,0};

double w[10][15] = { {0,}, };
double w_middle[10][15][15] = { { {0,},} , };
double w_last[2][15] = { { 0,} , };
double w_bias[10][15] = { {0,}, };
double w_bias_output[2] = { 0, };



int n = 0;

double U[10][15] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, };
double U_last[2] = { 0 , 0 };
double delta[10][15] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, };
double last_delta[2] = { 0, 0 };


void Input_num(){
    printf("enter input number\n");
    scanf("%d",&n);
     printf("input x number is %d\n",n);
}


void Error_Back_Propagation(double x[], double t[]) {
	double S = 0;

	for (int i = 0; i < hidden_N[0]; i++) {
		S = 0;
		for (int j = 0; j < n; j++) {
			S += x[j] * w[j][i];
		}
		if (bias == 1) S += w_bias[0][i];

		U[0][i] = 1 / (1 + exp(-S));
	}

	for (int i = 0; i < hidden - 1; i++) {
		for (int j = 0; j < hidden_N[i + 1]; j++) {
			S = 0;
			for (int k = 0; k < hidden_N[i]; k++) {
				S += U[i][k] * w_middle[i][k][j];
			}
			if (bias == 1) S += w_bias[i + 1][j];

			U[i + 1][j] = 1 / (1 + exp(-S));
		}
	}

	for (int i = 0; i < output_count; i++) {
		S = 0;
		for (int j = 0; j < hidden_N[hidden - 1]; j++) {
			S += U[hidden - 1][j] * w_last[i][j];
		}
		if (bias == 1) S += w_bias_output[i];

		U_last[i] = 1 / (1 + exp(-S));
	}


	for (int i = 0; i < output_count; i++) {
		last_delta[i] = (t[i] - U_last[i]) * U_last[i] * (1 - U_last[i]);
	}


	for (int i = 0; i < hidden_N[hidden - 1]; i++) {
		double allDelta = 0;
		for (int j = 0; j < output_count; j++) {
			allDelta += last_delta[j] * w_last[j][i];
		}
		delta[hidden - 1][i] = U[hidden - 1][i] * (1 - U[hidden - 1][i]) * allDelta;
	}


	for (int i = hidden - 1; i > 0; i--) {
		for (int j = 0; j < hidden_N[i - 1]; j++) {
			double allDelta = 0;
			for (int k = 0; k < hidden_N[i]; k++) {
				allDelta += delta[i][k] * w_middle[i - 1][j][k];
			}
			delta[i - 1][j] = U[i - 1][j] * (1 - U[i - 1][j]) * allDelta;
		}
	}

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < hidden_N[0]; j++) {
			w[i][j] += eta * delta[0][j] * x[i];
		}
	}

	for (int i = 0; i < hidden - 1; i++) {
		for (int j = 0; j < hidden_N[i]; j++) {
			for (int k = 0; k < hidden_N[i + 1]; k++) {
				w_middle[i][j][k] += eta * delta[i + 1][k] * U[i][j];
			}
			w_bias[i][j] += eta * delta[i][j];
		}
	}

	for (int i = 0; i < hidden_N[hidden - 1]; i++) {
		w_bias[hidden - 1][i] += eta * delta[hidden - 1][i];
	}

	for (int i = 0; i < output_count; i++) {
		for (int j = 0; j < hidden_N[hidden - 1]; j++) {
			w_last[i][j] += eta * last_delta[i] * U[hidden - 1][j];
		}
		w_bias_output[i] += eta * last_delta[i];
	}
}

int GridTest(double x[], double t[]) {
	double S = 0;
	double U_tmp[10][15] = { {0,}, {0,} };
	double U_last_tmp[2] = { 0, };


	for (int i = 0; i < hidden_N[0]; i++) {
		S = 0;
		for (int j = 0; j < n; j++) {
			S += x[j] * w[j][i];
		}
		if (bias == 1) S += w_bias[0][i];

		U_tmp[0][i] = 1 / (1 + exp(-S));
	}


	for (int i = 0; i < hidden - 1; i++) {
		for (int j = 0; j < hidden_N[i + 1]; j++) {
			S = 0;
			for (int k = 0; k < hidden_N[i]; k++) {
				S += U_tmp[i][k] * w_middle[i][k][j];
			}
			if (bias == 1) S += w_bias[i + 1][j];

			U_tmp[i + 1][j] = 1 / (1 + exp(-S));
		}
	}


	for (int i = 0; i < output_count; i++) {
		S = 0;
		for (int j = 0; j < hidden_N[hidden - 1]; j++) {
			S += U_tmp[hidden - 1][j] * w_last[i][j];
		}
		if (bias == 1) S += w_bias_output[i];

		U_last_tmp[i] = 1 / (1 + exp(-S));
	}
}


void set_w(int write) {
	srand(1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < hidden_N[0]; j++) {
			writeChoose(write, &w[i][j]);
		}
	}

	for (int i = 0; i < hidden - 1; i++) {
		for (int j = 0; j < hidden_N[i]; j++) {
			for (int k = 0; k < hidden_N[i + 1]; k++) {
				writeChoose(write, &w_middle[i][j][k]);
			}
		}
	}

	for (int i = 0; i < output_count; i++) {
		for (int j = 0; j < hidden_N[hidden - 1]; j++) {
			writeChoose(write, &w_last[i][j]);
		}
	}

	for (int i = 0; i < hidden; i++) {
		for (int j = 0; j < hidden_N[i]; j++) {
			writeChoose(write, &w_bias[i][j]);
		}
	}

	for (int i = 0; i < output_count; i++) {
		writeChoose(write, &w_bias_output[i]);
	}
}


int main() {
    double x[10]={0,},t[2]={0};
    int variable=0;
    int cnt=0;
    Input_num();
	FILE* architecture = fopen("architecture.dat", "r");
    if(NULL !=architecture)
    {
        printf("architecture.dat opened\n");
    }
    else
    {
        printf(" architecture.dat open failed\n");
    }
    //architecture.dat를 읽고 파일 수정
    while (fscanf(architecture,"%d,",&variable)!= EOF) {
    printf("variable:%d\n",variable);
    hidden_N[cnt]=variable;
    cnt++;
    }

    output_count=hidden_N[cnt-1];
    hidden_N[cnt-1]=0;
    hidden=cnt-1;

    for(int i=0;i<10;i++){
        printf("hidden[%d]:%d\n",i,hidden_N[i]);
    }

    printf("output_count%d\n",output_count);
    printf("hidden:%d\n",hidden);
    
    fclose(architecture);
    
    //--------------architecture read end
    
    //총 인풋 개수 구하기 시작(인풋 데이터 몇줄인지)//x1,,x2,x3..데이터 수정할것 이로직에서 데이터 줄 뽑아야함
    int input_total_cnt=0;//총 인풋 데이터 개수

    FILE* input= fopen("input.txt","r");
    while (fscanf(input, "%lf %lf %lf\n",&x[0],&x[1],&t[0]) != EOF) {
         input_total_cnt++;
	}
    fclose(input);
    
    printf("input_total_cnt:%d\n",input_total_cnt);
    //총 인풋 개수 구하기 끝
    
    //데이터에서 validation data,training data추출하기
    printf("input_total_cnt:%d\n",input_total_cnt);
    printf("extract_num:%d\n",input_total_cnt/10);
    rewind(input);
    int extract_num=0;
    int cnt_2=0;
    input= fopen("input.txt","r");
    FILE* validationdata=fopen("validationdata.txt","w");
    FILE* trainingdata=fopen("trainingdata.txt","w");
    while (fscanf(input,"%lf %lf %lf\n",&x[0],&x[1],&t[0])!=EOF){
        if((extract_num<input_total_cnt/10)&&(cnt_2%10==0)){
           // printf("x[0]:%lf,x[1]:%lf,t[0]:%lf\n",x[0],x[1],t[0]);
            //validation data에 넣기
            fprintf(validationdata,"%lf %lf %lf\n",x[0],x[1],t[0]);   
           // printf("cnt_2:%d\n",cnt_2);
            extract_num++;
        }
        else{
        //training data에 넣기
        //printf("trainging:x[0]:%lf,x[1]:%lf,t[0]:%lf\n",x[0],x[1],t[0]);
        fprintf(trainingdata,"%lf %lf %lf\n",x[0],x[1],t[0]);
        }
        cnt_2++;
	}
    fclose(input);
    fclose(validationdata);
    fclose(trainingdata);
    //weight setting





    //추출 데이터 ebp로 training
    double err = 0;
    trainingdata=fopen("trainingdata.txt","r");
    for(int i=0;i<epoch;i++){
        err = 0;
        while (fscanf(trainingdata,"%lf %lf %lf\n",&x[0],&x[1],&t[0])!=EOF){
                    printf("x[0]:%lf,x[1]:%lf,t[0]:%lf\n",x[0],x[1],t[0]);
                    Error_Back_Propagation(x,t);
                    for (int i = 0; i < output_count; i++) {
                    err += fabs(t[i] - U_last[i]);
                    }
            }
    }
    fclose(trainingdata); 
    //training시 특정 epoch마다 error,time이 적힌 error.dat을 작성


    return 0;
}
