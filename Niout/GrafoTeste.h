#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

class Edge {
public:
	int initialVertex;
	int finalVertex;
	int weight;
	
	Edge(){}
	Edge(int initialV, int finalV, int w) {
		initialVertex = initialV;
		finalVertex = finalV;
		weight = w;
	}
	void setValues(int initialV, int finalV, int w) {
		initialVertex = initialV;
		finalVertex = finalV;
		weight = w;
	}
	int getInitialVertex() {
		return initialVertex;
	}
	int getFinalVertex() {
		return finalVertex;
	}
	int getWeight() {
		return weight;
	}
};

class Vertex 
{
public:
	int state_id;
	string state_name;
	list<Edge> edgeList;

	Vertex() {
		state_id = 0;
		state_name = "";
	}
	Vertex(int id, string name) {
		state_id = id;
		state_name = name;
	}
	int getId() { return state_id; }
	string getName() { return state_name; }
	void setId(int id) { state_id = id; }
	void setName(string name) { state_name = name; }
	list<Edge> getEdge() { return edgeList; }
	

	bool hasNext() {
		for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
			return true;
		}
		return false;
	}
	void printEdgeList() {
		cout << "[";
		for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
			cout << it->getFinalVertex() << "(" << it->getWeight() << ") --> ";
		}
		cout << "]" << endl;
	}
};

class GrafoTeste
{
public:
	vector<Vertex> vertices;

	GrafoTeste() 
	{
		for (int i = 1; i <= 29; i++) {
			Vertex casa(i, "a");
			vertices.push_back(casa);
		}

		for (int i = 1; i < 20; i++) {
			addEdgeByID(i, i+1, 1);
		}
		addEdgeByID(5, 21, 2);
		addEdgeByID(10, 27, 2);
		addEdgeByID(15, 29, 2);
		addEdgeByID(21, 22, 1);
		addEdgeByID(22, 25, 1);
		for (int i = 27; i > 23; i--) {
			addEdgeByID(i, i - 1, 1);
		}
		addEdgeByID(29, 28, 1);
		addEdgeByID(28, 25, 1);
		addEdgeByID(23, 20, 1);
	}

	void addVertex(Vertex newVertex)
	{
		vertices.push_back(newVertex);
	}
	int getVerticeByID(int index) {
		for (int i = 0; i < vertices.size(); i++) {
			if (vertices.at(i).getId() == index)
				return i;
		}
	}
	void addEdgeByID(int from, int to, int weight) {
		for (int i = 0; i < vertices.size(); i++) {
			if (vertices.at(i).getId() == from) {
				Edge e(from, to, weight);
				vertices.at(i).edgeList.push_back(e);
			}
		}
	}
	void printGraph()
	{
		for (int i = 0; i < vertices.size(); i++) {
			Vertex temp;
			temp = vertices.at(i);
			cout << temp.state_name << " (" << temp.state_id << ") -->";
			temp.printEdgeList();
		}
	}
};

