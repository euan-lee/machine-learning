# machine-learning


겪은 에러:

.float vs double->double을 좀더 정확한 계산이 필요할 떄 사용!!

.부동 소수점 에러:
https://www.youtube.com/watch?v=vOO-oLS0H68

https://www.acmicpc.net/blog/view/3


.선언을 안했는데 데이터가 할당되는 경우가 있음

```c
#include<stdio.h>
int arr[3]={1,1,1,1};
int main(){
arr[4]=1;
printf("%d",arr[4]);

}

```

무조건 PRINTF를 하는것이 아니라 논리적으로 먼저 어느 부분이 틀렸을지 생각하고 들어가기


week11  
.validation data

![image](https://user-images.githubusercontent.com/62791913/170620310-3f0b0a22-cee1-4f2c-b81b-5f7407eb553e.png)

test data

![image](https://user-images.githubusercontent.com/62791913/170620379-9b83fbc2-3d6f-4b50-93d0-260549558181.png)



after function fitting

![image](https://user-images.githubusercontent.com/62791913/170620435-abb4a521-cd44-4467-b495-17770ec835b5.png)



error-epoch graph

![image](https://user-images.githubusercontent.com/62791913/170620536-8aedba06-aecc-4f7c-8bbd-05778591b956.png)




