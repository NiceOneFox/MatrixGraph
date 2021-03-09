#include "pch.h"
#include "MatrixGraph.h"
#include "MyException.h"

void vertexMaxPower(MatrixGraph & graph)
{
	vector<int> NoMaxVertex;
	int max = -1;
	int prevMax = 0;
	int n = graph.getVertex();
	for (int i = 0; i < n; i++) {
		max = graph.inPowerVertex(i) + graph.outPowerVertex(i);

		if (max == prevMax) {
			NoMaxVertex.push_back(i);
		}

		if (max > prevMax){
			NoMaxVertex.clear(); // если новая макс степень очищаем вектор
			prevMax = graph.inPowerVertex(i) + graph.outPowerVertex(i);
			NoMaxVertex.push_back(i);
		}
		
	}
	outputVertexMaxPower(graph, max, NoMaxVertex);
}

void outputVertexMaxPower(MatrixGraph graph, const int max, std::vector<int> NoMaxVertex)
{
	int n = graph.getVertex();
	ofstream fout("output.txt", ios::app);
	if (!fout.is_open())
		throw MyException("файле не найден", "output.txt");
	else {
		fout << "=MaxVertexPower=\n";
		fout << "Power|" << "Vertex\n";
		fout << "|" << setw(4) << max << "| ";
		for (vector<int>::iterator it = NoMaxVertex.begin(); it != NoMaxVertex.end(); ++it)
			fout << *it << " ";
		fout << "|" << "\n====";
		for (int i = 0; i < (n * 2); i++) {
			fout << "=";
		}
		fout << endl;
		fout.close();
	}
}