#include "pch.h"
#include "MatrixGraph.h"
#include "MyException.h"

void Print(MatrixGraph graph)
{
	int n = graph.getVertex();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (graph.HasArc(i, j) ? '1' : '0') << " ";
		}
		cout << endl;
	}
}

void inputMatrixGraph(std::vector<MatrixGraph> & arr, const string & fileIn)
{
	ifstream fin;
	fin.open(fileIn, ios::binary);
	if (!fin.is_open())
		throw MyException("���� �� ������", fileIn); 
	else {
		if (fin.peek() == EOF)
			throw MyException("���� ������", fileIn);
		int from;
		int to;
		int n;
		if (fin >> n){ // ��������� ������ �������
			arr.push_back(MatrixGraph(n));
		  while (!fin.eof()) {	
				fin >> from;
				fin >> to;
				arr.back().AddArc(from, to);
			}			
		}
		else {
			throw MyException(" �� �������� ����� ������������ ������ �������", fileIn);
		}

	}
	fin.close();
}

void inputGraphAsMatrix(std::vector<MatrixGraph> & arr, const string & fileIn)
{
	ifstream fin;
	fin.open(fileIn, ios::binary);
	if (!fin.is_open())
		throw MyException("���� �� ������", fileIn);
	else {
		if (fin.peek() == EOF)
			throw MyException("���� ������", fileIn);
		int n;
		if (fin >> n) { // ��������� ������ �������
			MatrixGraph M(n);
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					fin >> M(i,j);
				}
			}
		arr.push_back(M);		
		}
		else {
			throw MyException(" �� �������� ����� ������������ ������ �������", fileIn);
		}
	fin.close();
	}
}
