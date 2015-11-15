############################################################
1. Graph with direction
############################################################
Suppose the Graph with direction( here is a binary tree for simpile purpose, also the direction is omitted ) is below:
       v1
       / \
   123/   \321
     /     \
    v2     v3 

############################################################
2. Test the program
############################################################

23:18 tonyho@ubuntu:Graph $ gcc MatrixGraph.c -o MatrixGraph
23:18 tonyho@ubuntu:Graph $ ./MatrixGraph
Here We go
Please Input the vertex and Arc number of Network(Graph with weight)
Seperate with ,:3,2
VNumver=3, ArcNumber=2
Please Input the vertex value
v1 v2 v3
Vertex name = [v1]
Vertex name = [v2]
Vertex name = [v3]
Please Input the arc head, arc tail, arc weight value
Seperate with space
v1 v2 123
Edge index = 0: Vex[0][1]=[123]
v1 v3 321
Edge index = 1: Vex[0][2]=[321]
	v1	v2	v3	
v1	-1	-1	-1	
v1	123	-1	-1	
v1	321	-1	-1	
23:18 tonyho@ubuntu:Graph $ 

