#include "pch.h"
#include "MatrixGraph.h"
#include "MyException.h"
void inOutPowerVertex(MatrixGraph graph)
{
	int n = graph.getVertex();
	vector <int> InPower;
	vector <int> OutPower;
	for (int i = 0; i < n; i++) {
		InPower.push_back(graph.inPowerVertex(i));
		OutPower.push_back(graph.outPowerVertex(i));
	}
	
	outputInOutPowerVertex(graph, InPower, OutPower);
}

void outputInOutPowerVertex(MatrixGraph graph, std::vector<int> InPower, std::vector<int> OutPower)
{
	int n = graph.getVertex();
	ofstream fout("output.txt", ios::app);
	if (!fout.is_open())
		throw MyException("Файл не найден", "output.txt");
	else {
		fout << "=PowerVertex=\n" << "No |";
		for (int i = 0; i < n; i++) {
			fout << i << " ";
		}
		fout << endl << "In |";
		for (vector<int>::iterator it = InPower.begin(); it != InPower.end(); ++it)
			fout << *it << " ";
		fout << endl << "Out|";
		for (vector<int>::iterator it = OutPower.begin(); it != OutPower.end(); ++it)
			fout << *it << " ";

		fout << "\n====";
		for (int i = 0; i < n * 2; i++) {
			fout << "=";
		}
		fout << endl;
		fout.close();
	}
}