#include <stdio.h>
#include <math.h>
#define neuron_num 2
#define eta 0.4

double w1_input_val[2] ={-0.5,-0.4};
double w2_input_val[2] ={-0.5,-0.4};
double w_output_val[2] = {-0.5,-0.4};
double w_bias_val[3] = {-0.5,-0.4,-0.3};
int bias_mode=0;
double u[3] = {0,0,0};

void FeedForward(double x1,double x2){
    	double S = 0, S_output = 0; 
	for (int i = 0; i <neuron_num; i++) {
		S = x1* w1_input_val[i] + x2 * w2_input_val[i];
		if(bias_mode == 1) S += w_bias_val[i];
		printf("s[%d]:%lf\n",i,S);
		u[i] = 1 / (1 + exp(-S));
		S_output += u[i] * w_output_val[i];
	}
		printf("line 22:s_out:%lf",S_output);
	if (bias_mode==1) S_output += w_bias_val[neuron_num];
	printf("fianl bias:%lf\n",w_bias_val[neuron_num]);
	printf("s_out:%lf",S_output);
	u[neuron_num] = 1 / (1 + exp(-S_output));	
	printf("final:%lf\n",u[neuron_num]);
}


double delta[10] = {0,0,0};

void FeedBckward(double x1, double x2, double target){
   
    delta[neuron_num] = (target-u[neuron_num])*u[neuron_num]*(1-u[neuron_num]);

	for (int i=neuron_num- 1;i>=0;i--) {
		delta[i]=u[i]*(1-u[i])*delta[neuron_num]*w_output_val[i];
	}

	for (int i = 0; i < neuron_num; i++) {
		w_output_val[i]=w_output_val[i]+eta*delta[neuron_num] * u[i];
		w1_input_val[i]=w1_input_val[i]+eta*delta[i]*x1;
		w2_input_val[i]=w2_input_val[i]+eta*delta[i]*x2;
		w_bias_val[i]=w_bias_val[i]+eta*delta[i];
	}

	w_bias_val[neuron_num]+=eta*delta[neuron_num];
}

void Error_back_propagation(double x1, double x2, double target) {
    FeedForward(x1,x2);
	FeedBckward(x1,x2,target);
}


void Show_result(){


	for(int i = 0; i < neuron_num; i++){
		printf("W%d<-%d : %lf\n", i + 3, 0, w_bias_val[i]);
		printf("W%d<-%d : %lf\n", i + 3, 1, w1_input_val[i]);
		printf("W%d<-%d : %lf\n", i + 3, 2, w2_input_val[i]);;
	}

	//위의 중간 layer 로 들어오는 w 값을 출력한 이후에 output 쪽에 연결된 w 값을 출력한다.
	for (int i = 0; i <neuron_num; i++) {
		printf("W%d<-%d : %lf\n", neuron_num + 3, i + 3, w_output_val[i]);
	}
	

};

void ChooseMode(){
    printf("choose mode 1:with bias 2:without bias\n");
    scanf("%d",&bias_mode);
    printf("bias:%d",bias_mode);
}

int main() {

    ChooseMode();
    Error_back_propagation(1.0,1.0,1.0);
    Show_result();
	printf("delta[4]%lf",delta[2]);
	
}
