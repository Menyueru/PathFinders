#include <queue>
#include <vector>
#include "graph.h" 
#include "Node.h"
#include "Edge.h"
#include "Vector2D.h"
#include "AStar.h"
#include "AStarHeuristics.h"
#include <iostream>

using namespace std;

int main(){
	Graph<NavNode, Edge>  *graph = new Graph<NavNode, Edge>();
	graph->AddNode(NavNode(graph->GetNextFreeNodeIndex(),Vector2D(1,2)));
	graph->AddNode(NavNode(graph->GetNextFreeNodeIndex(), Vector2D(0,0)));
	graph->AddNode(NavNode(graph->GetNextFreeNodeIndex(), Vector2D(3,3)));
	graph->AddNode(NavNode(graph->GetNextFreeNodeIndex(), Vector2D(1,0)));
	graph->AddNode(NavNode(graph->GetNextFreeNodeIndex(), Vector2D(5,1)));

	graph->AddEdge(Edge(0, 2));
	graph->AddEdge(Edge(0, 1));
	graph->AddEdge(Edge(2, 3));
	graph->AddEdge(Edge(3, 4));
	graph->AddEdge(Edge(1, 4));
	graph->AddEdge(Edge(2, 3));

	SearchAStar<Graph<NavNode, Edge>, Heuristic_Euclidean_Squared> Star(*graph, 0, 4);
	list<int> path = Star.GetPathToTarget();
	for (list<int>::iterator it = path.begin(); it != path.end();it++)
	{
		NavNode nextNode= graph->GetNode(*it);

		cout << "Moving to: " << nextNode.Index() <<" in position " << nextNode.Pos().x << " " << nextNode.Pos().y << endl;
	}
	
	cin.get();
	return 0;
}