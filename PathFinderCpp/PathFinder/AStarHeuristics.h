#ifndef ASTAR_HEURISTIC_H
#define ASTAR_HEURISTIC_H
#include <cmath>
#include "Vector2D.h" 
#include "Graph.h"

class Heuristic_Euclid
{
public:

	Heuristic_Euclid(){}

	template <class graph_type>
	static double Calculate(graph_type G, int nd1, int nd2)
	{
		return G.GetNode(nd1).Pos().Distance(G.GetNode(nd2).Pos());
	}
};


class Heuristic_Manhattan
{
public:
	Heuristic_Manhattan(){}

	template <class graph_type>
	static double Calculate(graph_type G, int nd1, int nd2)
	{
		return fabs(G.GetNode(nd2).Pos().x - G.GetNode(nd1).Pos().x) + fabs(G.GetNode(nd2).Pos().y - G.GetNode(nd1).Pos().y);
	}
};

class Heuristic_Euclidean_Squared
{
public:
	Heuristic_Euclidean_Squared(){}
	template <class graph_type>
	static double Calculate(graph_type G, int nd1, int nd2)
	{
		return G.GetNode(nd1).Pos().DistanceSq(G.GetNode(nd2).Pos());
	}
};

class No_Heuristic
{
public:

	template <class graph_type>
	static double Calculate(graph_type G, int nd1, int nd2)
	{
		return 0;
	}
};

#endif