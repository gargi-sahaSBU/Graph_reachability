import timeit
f = open('files/reach.in.1000','r')
start_time = timeit.default_timer()
data = f.read().strip()
edges_line,s = data.split(')}')
edges_line = edges_line.replace('{(','')
edges_line = edges_line.replace('\r','')
edges_line = edges_line.replace('\n','')
edges_line = edges_line.replace(' ','')
s = s.strip()
s = s.replace('{','').replace('}','')
s = int(s)


edges = []
for i in edges_line.split('),('):
	vertex1,vertex2 = i.split(',')
	edge = (int(vertex1),int(vertex2))
	edges.append(edge)
	#edges is now a list of tuples of edges


r=set()
r.add(s)
	
def reach(set_of_vertices,edges):
	ans = set()
	for v in set_of_vertices:
		for e in edges:
			if e[0] == v:
				ans.add(e[1])
	return ans
	

	#my python knowledge is a little weak as I feel I am unnecesarily computing e[r] -r twice
while len(reach(r,edges).difference(r)) != 0:
	for x in reach(r,edges).difference(r):
		r.add(x)
	
elapsed = timeit.default_timer() - start_time
output = open('PythonClear_output','a')
print >> output,r
print >> output,elapsed
output.close()

f.close()