import matplotlib.pyplot as plt


X_ip = open('PythonEfficient_output','r')
Y_ip = open('files/count.txt','r').read().strip().split('\n')
Y_input = []
for i in Y_ip:
	Y_input.append(int(i))

X_input = []

for index, line in enumerate(X_ip.readlines()):
    if (index + 1) % 2 == 0: 
    	line = line.strip()
    	X_input.append(float(line))

plt.title('Plot of Efficient Python implementation')
plt.grid(True)
plt.plot(Y_input,X_input,'bo')
#plt.axis([800, 1200, 0, 0.07])
plt.ylabel('Time')
plt.xlabel('Input size')
plt.show()

