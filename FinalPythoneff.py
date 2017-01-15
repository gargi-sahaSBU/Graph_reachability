import timeit
class Queue:
	def __init__(self):
		self.items = []
	def isEmpty(self):
		return self.items == []
	def enqueue(self,item):
		self.items.insert(0,item)
	def dequeue(self):
		return self.items.pop()
	def size(self):
		return len(self.items)
	def peekLast(self):
		return self.items[len(self.items)-1]


f = open('files/reach.in.1000','r')

data = f.read().strip()
edges_line,src = data.split(')}')
edges_line = edges_line.replace('{(','')
edges_line = edges_line.replace('\r','')
edges_line = edges_line.replace('\n','')
edges_line = edges_line.replace(' ','')
src = src.strip()
src = src.replace('{','').replace('}','')
src = int(src)
start_time = timeit.default_timer()

e = {}
dom_e = {}

for i in edges_line.split('),('):
	v1,v2 = i.split(',')
	vertex1 = int(v1)
	vertex2 = int(v2)
	if e.has_key(vertex1) == False:
		e[vertex1] = vertex1
		dom_e[vertex1] = [vertex2]
	else:
		dom_e.setdefault(vertex1,[]).append(vertex2)

W = Queue()
W.enqueue(src)

t=set()
r=set()
r=set()
s= set()
s.add(src)

while W.isEmpty() == False :
	x = W.peekLast()
	for y in dom_e[x]:
		if y not in t:
			if y not in t and y not in s:
				W.enqueue(y)
			t.add(y)
	if x in t or x in s:
		W.dequeue()
	r.add(x)



elapsed = timeit.default_timer() - start_time

output = open('PythonEfficient_output','a')
print >> output,r
print >> output,elapsed
output.close()

f.close()