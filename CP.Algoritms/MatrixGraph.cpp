#include "pch.h"
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int n)
{
	graph = new bool*[vertexNumber_ = n];
	for (int i = 0; i < n; i++) {
		bool *row = graph[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			row[j] = false;
		}
	}
}

MatrixGraph::MatrixGraph(const MatrixGraph &other)
{
	vertexNumber_ = other.vertexNumber_;
	int n = other.getVertex();

	graph = new bool*[n];
	for (int i = 0; i < n ; i++) 
		graph[i] = new bool[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = other.graph[i][j];
		}
	}
}

MatrixGraph::~MatrixGraph()
{
	for (int i = 0; i < vertexNumber_; i++) {
		delete graph[i];
	}
	delete graph;
}

void MatrixGraph::AddArc(int from, int to)
{
	if (from < 0 || from >= vertexNumber_ || to < 0 || to >= vertexNumber_)
	  throw "Вершина выходит за размеры матрицы";
	if (graph[from][to] == true)
		return; // удаление кратных рёбер не возможно т.к они не отображаются в матрице

	graph[from][to] = true;
}

bool MatrixGraph::HasArc(int from, int to) const
{
	if (from < 0 || from >= vertexNumber_ || to < 0 || to >= vertexNumber_)
		return false;
	return graph[from][to];
}

void MatrixGraph::Print()
{
	int n = getVertex();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (HasArc(i, j) ? '1' : '0') << " ";
		}
		cout << endl;
	}
}

bool MatrixGraph::isAdjacentVertex(int from, int to)
{
	if (graph[from][to] == true)/* && graph[to][from] == true)*/
		return true;

	return false;
}

int MatrixGraph::inPowerVertex(int NoVertex)
{
	int count = 0;
	for (int i = 0; i < vertexNumber_; i++) {
		if (graph[i][NoVertex] == 1)
			count++;
	}

	return count;
}

int MatrixGraph::outPowerVertex(int NoVertex)
{
	int count = 0;
	for (int j = 0; j < vertexNumber_; j++) {
		if (graph[NoVertex][j] == 1)
			count++;
	}

	return count;
}

void MatrixGraph::deleteCircleVertexes()
{
	int n = vertexNumber_;
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (graph[i][j] == true)
			graph[i][j] = false;		
		j++;
	}
}

void MatrixGraph::deleteMultipleEdge()
{
	for (int i = vertexNumber_-1; i >= 0; i--) {
		for (int j = 0; j < vertexNumber_; j++) {
			if (graph[i][j] == 1 && graph[j][i] == 1)
				graph[i][j] = 0;
	  }
	}
}
