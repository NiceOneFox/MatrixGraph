#include "pch.h"
#include "MatrixGraph.h"
#include "MyException.h"
void outputMatrixGraph(MatrixGraph graph)
{
	int n = graph.getVertex();
	ofstream fout("output.txt", ios::out);
	if (!fout.is_open())
		throw MyException("Файл не найден", "output.txt");
	else {
		fout << "=Adjacency Matrix=" << endl;
		fout << "No| ";
		for (int i = 0; i < n; i++) { // вывод нумерации вершин
			fout << i << " ";
		}
		fout<< endl << "  "; // вывод верхней границы таблицы
		for (int i = 0; i < (n * 2) + 3; i++) {
			fout << "=";
		}
		fout << endl;
		for (int i = 0; i < n; i++){
		fout << i << " | ";
			for (int j = 0; j < n; j++){
				fout << graph(i, j) << " ";
			}
			fout << "|" << endl;
		}
		fout << "  "; // вывод нижней границы таблицы
		for (int i = 0; i < (n*2)+3; i++) {
			fout <<"=";
		}
		fout << endl;
		fout.close();
	}
}