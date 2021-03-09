#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

class MatrixGraph
{
public:
	MatrixGraph() {}

	MatrixGraph(int n);

	MatrixGraph(const MatrixGraph &other);

	~MatrixGraph();

	int getVertex() const {	return vertexNumber_; }

   void AddArc(int from, int to);

   bool HasArc(int from, int to) const;

	void Print();

	friend void Print(MatrixGraph graph);

	bool isAdjacentVertex(int from, int to);

	int  inPowerVertex (int NoVertex);

	int  outPowerVertex(int NoVertex);

	void deleteCircleVertexes();

	void deleteMultipleEdge();

	bool& operator()(const int i, const int j) {	return graph[i][j];	}

private:
	int vertexNumber_;
	bool **graph;
};

struct adjacentVertexes
{
	int from;
	vector <int> to;
};

void listAdjacentVertexes(MatrixGraph & graph, adjacentVertexes *adjVert);

void vertexMaxPower(MatrixGraph & graph);
void outputVertexMaxPower(MatrixGraph graph, const int max, std::vector<int> NoMaxVertex);

void inputMatrixGraph  (std::vector<MatrixGraph> & arr, const string & fileIn);
void inputGraphAsMatrix(std::vector<MatrixGraph> & arr, const string & fileIn);

void inOutPowerVertex(MatrixGraph graph);
void outputInOutPowerVertex(MatrixGraph graph, std::vector<int> InPower, std::vector<int> OutPower);

void outputMatrixGraph(MatrixGraph graph);


#endif
