import matplotlib.pyplot as plt
import numpy as np
a=[];
f = open("hello.txt", 'r')
while True:
    line = f.readline()
    if not line: break
    a.append(line)
    print(a)
f.close()
w1=a[0]
w2=a[1]
tetha=a[2]
w1=float(w1)
w2=float(w2)
tetha=float(tetha)
x=[0,1]
x[0]=float(x[0])
x[1]=int(x[1])
y=[0,0]
y[0]=float((-(w1/w2)*x[0]+tetha/w2))
y[1]=(-(w1/w2)*x[1]+tetha/w2)
print(y[0])
print(y[1])

plt.plot(y)
plt.scatter(1,0,c='#000000')
plt.scatter(1,1,c='#000000')
plt.scatter(0,0,c='#000000')
plt.scatter(0,1,c='#000000')
plt.show()
