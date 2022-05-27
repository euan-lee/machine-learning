# machine-learning

.float vs double->double을 좀더 정확한 계산이 필요할 떄 사용!!

.파일은 공간복잡도에 포함되는가?
파일은 스트림을 통해 데이터를 통하고 이는 운영체제가 해줌(파일과 다리가 놓아졌다고 생각하자),마우스나 키보드와 같은 io장치라고 생각해도 됨

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







