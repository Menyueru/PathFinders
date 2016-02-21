#ifndef A_STAR
#define A_STAR
#include <queue>
#include <vector>
#include "Graph.h" 
#include "Node.h"
#include "Edge.h"
#include "Vector2D.h"
#include "IndexedPriorityQueue.h"

template <class graph_type, class heuristic>

class SearchAStar
	{
	private:

		//create a typedef for the edge type used by the graph
		typedef typename graph_type::EdgeType Edge;

	private:

		const graph_type&             graph;

		//indexed into my node. Contains the 'real' accumulative cost to that node
		std::vector<double>             gCosts;

		//indexed into by node. Contains the cost from adding gCosts[n] to
		//the heuristic cost from n to the target node. This is the vector the
		//iqueue indexes into.
		std::vector<double>             fCosts;

		std::vector<const Edge*>       shortestPathTree;
		std::vector<const Edge*>       searchEdges;

		int                            source;
		int                            target;

		//the A* search algorithm
		void Search();

	public:

		SearchAStar(graph_type& graph, int source, int target) :graph(graph),
			shortestPathTree(graph.CountNodes()),
			searchEdges(graph.CountNodes()),
			gCosts(graph.CountNodes(), 0.0),
			fCosts(graph.CountNodes(), 0.0),
			source(source),
			target(target)
		{
			Search();
		}

		//returns the vector of edges that the algorithm has examined
		std::vector<const Edge*> GetSPT()const{ return shortestPathTree; }

		//returns a vector of node indexes that comprise the shortest path
		//from the source to the target
		std::list<int> GetPathToTarget()const;

		//returns the total cost to the target
		double GetCostToTarget()const{ return gCosts[target]; }
	};

	//Actual AStar Algorithm
	template <class graph_type, class heuristic>
	void SearchAStar<graph_type, heuristic>::Search()
	{
		MinIndexedPriorityQueue<double> queue(fCosts,graph.CountNodes());

		queue.Insert(source);

		while (!queue.IsEmpty())
		{
			int NextClosestNode = queue.Pop();

			shortestPathTree[NextClosestNode] = searchEdges[NextClosestNode];

			if (NextClosestNode == target) return;
			
			graph_type::ConstEdgeIterator ConstEdgeItr(graph, NextClosestNode);

			for (const Edge* pE = ConstEdgeItr.begin(); !ConstEdgeItr.end(); pE = ConstEdgeItr.next())
			{   
				double HCost = heuristic::Calculate(graph, target, pE->To());

				double GCost = gCosts[NextClosestNode] + pE->Cost();

				if (searchEdges[pE->To()] == NULL)
				{
					fCosts[pE->To()] = GCost + HCost;
					gCosts[pE->To()] = GCost;

					queue.Insert(pE->To());

					searchEdges[pE->To()] = pE;
				}
				else if ((GCost < gCosts[pE->To()]) && (shortestPathTree[pE->To()] == NULL))
				{
					fCosts[pE->To()] = GCost + HCost;
					gCosts[pE->To()] = GCost;

					queue.ChangePriority(pE->To());

					searchEdges[pE->To()] = pE;
				}
			}
		}
	}

	template <class graph_type, class heuristic>
	std::list<int> SearchAStar<graph_type, heuristic>::GetPathToTarget()const
	{
		std::list<int> path;

		if (target < 0)  return path;

		int nd = target;

		path.push_front(nd);

		while ((nd != source) && (shortestPathTree[nd] != 0))
		{
			nd = shortestPathTree[nd]->From();

			path.push_front(nd);
		}

		return path;
	}

#endif 
