#ifndef GRAPH
#define GRAPH
#include<vector>
#include<list>
#include <cassert>
template<class node_type, class edge_type>
class Graph{
private:
	std::vector<node_type> nodeList;
	std::vector<std::list<edge_type>> edgeList;
	int nextNodeIndex;
public:
	typedef edge_type EdgeType;
	typedef node_type NodeType;
	Graph() :nextNodeIndex(0){}
	node_type& GetNode(int idx);
	edge_type& GetEdge(int to, int from);
	std::list<edge_type> GetedgeListFrom(int from) const{ return edgeList[from]; }
	int GetNextFreeNodeIndex()const{ return nextNodeIndex; }
	int AddNode(node_type node);
	void AddEdge(edge_type edge);
	void SetEdgeCost(int from, int to, double cost);
	int CountNodes()const{ return nodeList.size(); }
	bool isEmpty()const{ return nodeList.empty(); }
	bool EdgeExists(int from, int to);
	void Clear(){ nextNodeIndex = 0; nodeList.clear(); edgeList.clear(); }

	class ConstEdgeIterator
	{
	private:

		typename std::list<edge_type>::const_iterator  curEdge;
		const Graph<node_type, edge_type>& G;
		const int NodeIndex;

	public:

		ConstEdgeIterator(const Graph<node_type, edge_type>& graph,int node) : G(graph),NodeIndex(node)
		{
			curEdge = G.edgeList[NodeIndex].begin();
		}

		const EdgeType*  begin()
		{
			curEdge = G.edgeList[NodeIndex].begin();

			if (end()) return 0;

			return &(*curEdge);
		}

		const EdgeType*  next()
		{
			++curEdge;
			if (end())
			{
				return NULL;
			}
			else
			{
				return &(*curEdge);
			}
		}

		//return true if we are at the end of the edge list
		bool end()
		{
			return (curEdge == G.edgeList[NodeIndex].end());
		}
	};

	friend class ConstEdgeIterator;
};

template<class node_type, class edge_type>
node_type& Graph<node_type,edge_type>::GetNode(int idx){
	return nodeList[idx];
}

template<class node_type, class edge_type>
edge_type& Graph<node_type, edge_type>::GetEdge(int to, int from){
	for (std::list<edge_type>::iterator it = edgeList[from].begin(); it != edgeList[from].end();it++)
	{
		edge_type currentEdge = *it;
		if (currentEdge.To() == to) return currentEdge;
	}
}

template<class node_type, class edge_type>
int Graph<node_type, edge_type>::AddNode(node_type node){
	if (node.Index() < nodeList.size()){
		nodeList[node.Index()] = node;
		return nextNodeIndex;
	}
	else{
		nodeList.push_back(node);
		edgeList.push_back(std::list<edge_type>());
		return nextNodeIndex++;
	}
}

template<class node_type, class edge_type>
void Graph<node_type, edge_type>::AddEdge(edge_type edge){
	assert((edge.From() < nextNodeIndex) && (edge.To() < nextNodeIndex) && "<Graph::AddEdge>: invalid node index");
	if (!this->EdgeExists(edge.From(),edge.To())){
		edgeList[edge.From()].push_back(edge);
		//In this implementation all graphs are digraph so need to add the opposite connection
		edge_type newEdge = edge;
		newEdge.SetTo(edge.From());
		newEdge.SetFrom(edge.To());
		edgeList[edge.To()].push_back(newEdge);
	}
}

template<class node_type, class edge_type>
void Graph<node_type, edge_type>::SetEdgeCost(int from, int to, double cost){
	for (std::list<edge_type>::iterator it = edgeList[from].begin(); it != edgeList[from].end(); it++){
		edge_type currentEdge = *it;
		if (currentEdge.To() == to){
			currentEdge.SetCost(cost);
			for (std::list<edge_type>::iterator it2 = edgeList[to].begin(); it2 != edgeList[to].end(); it2++){
				edge_type toEdge = *it;
				if (currentEdge.To() == from){
					toEdge.SetCost(cost);
				}
			}
		}
	}
}

template<class node_type, class edge_type>
bool Graph<node_type, edge_type>::EdgeExists(int from, int to){
	for (std::list<edge_type>::iterator it = edgeList[from].begin(); it != edgeList[from].end(); it++){
		edge_type currentEdge = *it;
		if (currentEdge.To() == to){
			return true;
		}
	}
	return false;
}
#endif 
