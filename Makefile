RightViewOfBinTree: RightViewOfBinTree.o
	g++ -g -o RightViewOfBinTree.exe RightViewOfBinTree.o -pthread    

RightViewOfBinTree.o: RightViewOfBinTree/RightViewOfBinTree.cpp
	g++ -g  -c -pthread RightViewOfBinTree/RightViewOfBinTree.cpp
