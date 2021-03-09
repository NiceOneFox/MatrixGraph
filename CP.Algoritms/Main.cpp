#include "pch.h"
#include "MatrixGraph.h"
#include "MyException.h"
#include "DurationTime.h"

// #1 список смежных вершин матрицы		 +
// #2 исходиящаю степень вершины       +
// #3 входящая степень вершины         +
// #4 вершины с максимальной степенью  +
// №5 удаление кратных рёбер и циклов в мультиграфе +

int main()
{
	try{
		setlocale(LC_ALL, "Rus");

		vector <MatrixGraph> arr;

		cout << "Введите номер способа считывания графа из файла\n";
		cout << "1: В файле указан размер матрицы и готовая матрица смежности\n";
		cout << "2: В файле указан размер матрицы и пары смежных вершин\n";
		int method = 1;
		cin >> method;
		string fileIn = "input.txt";
		cout << "Введите названия файла где укана информация\n";
		cin >> fileIn;
		switch (method){
		case 1:
			inputGraphAsMatrix(arr, fileIn);
			break;

		case 2:
			inputMatrixGraph(arr, fileIn);
			break;

		default:
			throw "Ошибка! Введите число 1 или 2";
			break;
		}
		
		arr.back().Print();

		arr.back().deleteCircleVertexes(); // удаление циклов в мультиграфе

		arr.back().deleteMultipleEdge(); // удаления кратных рёбер

		outputMatrixGraph(arr.back());

		adjacentVertexes *adjVert = new adjacentVertexes[arr.back().getVertex()]; // cписок смежных вершин
		listAdjacentVertexes(arr.back(), adjVert); // список смежности
		delete[] adjVert;

		inOutPowerVertex(arr.back()); // входящая и исходящая степень вершин

		vertexMaxPower(arr.back()); // максимальная степень вершин

	}
	catch (MyException ex) {
		cerr << ex.getError() << endl;
		system("Pause");
		return -1;
	}
	catch (const char* error) {
		cout << endl << error << endl;
		return -1;
	}

	return 0;
}

