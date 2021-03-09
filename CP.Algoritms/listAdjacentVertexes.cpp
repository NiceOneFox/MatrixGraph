#include "pch.h"
#include "MatrixGraph.h"
void listAdjacentVertexes(MatrixGraph & graph, adjacentVertexes *adjVert)
{
	int count = 0; // кол-во элементов в списке
	int n = graph.getVertex();
	bool isAdjacent = false;

	for (int i = 0; i < n; i++) {
		isAdjacent = false; // найдена хотя бы одна смежная вершина значит размер списка увелечился
		for (int j = 0; j < n; j++){
			if (graph.isAdjacentVertex(i, j)) {

				isAdjacent = true;
				adjVert[count].from = i;
				adjVert[count].to.push_back(j);
			}
		}
		if (isAdjacent == true) {
			adjVert[count].from = i;
			count++;
		}
	}

	ofstream fout("output.txt", ios::app);
	if (!fout.is_open()) 
		throw "Файл не найден";
	else {
		fout << "=AdjacencyList=" << endl;
		fout << " from" << "   to   " << endl;
		for (int i = 0; i < count; i++) { 
			fout << "|" << setw(4) << right << adjVert[i].from << " | ";
			for (vector<int>::iterator it = adjVert[i].to.begin(); it != adjVert[i].to.end(); ++it)
				fout << *it << " ";
			//fout << "|";
    	fout << endl;
		}
		fout << "=============\n";
		fout.close();
	}
}

