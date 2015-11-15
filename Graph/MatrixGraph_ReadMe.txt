############################################################
1. Graph with direction
############################################################
The graph is show in picture ./GraphWithWeightAndDirection.png

############################################################
2. Test the program
############################################################

23:18 tonyho@ubuntu:Graph $ gcc MatrixGraph.c -o MatrixGraph
23:18 tonyho@ubuntu:Graph $ ./MatrixGraph
Here We go
Please Input the vertex and Arc number of Network(Graph with weight)
Seperate with ,:5,5
VNumver=5, ArcNumber=5
Please Input the vertex value
A B C D E
Vertex name = [A]
Vertex name = [B]
Vertex name = [C]
Vertex name = [D]
Vertex name = [E]
Please Input the arc head, arc tail, arc weight value
Seperate with space
A B 5 
Edge index = 0: Vex[0][1]=[5]
A D 3
Edge index = 1: Vex[0][3]=[3]
D E 6
Edge index = 2: Vex[3][4]=[6]
E C 7
Edge index = 3: Vex[4][2]=[7]
B E 8
Edge index = 4: Vex[1][4]=[8]
	A	B	C	D	E	
A	-1	-1	-1	-1	-1	
B	5	-1	-1	-1	-1	
C	-1	-1	-1	-1	7	
D	3	-1	-1	-1	-1	
E	-1	8	-1	6	-1	
23:24 tonyho@ubuntu:Graph $ 

