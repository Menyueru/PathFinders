using System;
using System.Collections.Generic;
using System.Linq;

namespace PathFinder.Graph
{
    public class Graph<TModel>
    {
        private IList<Node<TModel>> nodeList;
        private IDictionary<int,IList<Edge>> edgeList;
        private int nextNodeIndex=0;

        public Graph()
        {
            nextNodeIndex = 0;
            nodeList = new List<Node<TModel>>();
            edgeList = new Dictionary<int,IList<Edge>>();
        }

        public Node<TModel> GetNode(int index)
        {
            return nodeList[index];
        }

        public Edge GetEdge(int to, int from)
        {
            foreach(var edge in edgeList[from])
            {
                if (edge.To == to) return edge;
            }
            return null;
        }

        public IList<Edge> GetEdgeListFrom(int from)
        {
            return edgeList[from];
        }

        public int GetNextFreeNodeIndex()
        {
            return nextNodeIndex;
        }

        public int AddNode(Node<TModel> node)
        {
            if (node.Index < nodeList.Count())
            {
                nodeList[node.Index] = node;
                return nextNodeIndex;
            }
            else {
                nodeList.Add(node);
                edgeList.Add(node.Index,new List<Edge>());
                return nextNodeIndex++;
            }
        }

        public void AddEdge(Edge edge)
        {
            if ((edge.From >= nextNodeIndex) && (edge.To >= nextNodeIndex)) throw new IndexOutOfRangeException("Invalid node index in edge");

            if (!EdgeExists(edge.From, edge.To))
            {
                edgeList[edge.From].Add(edge);

                var digraphEdge = new Edge(edge.To, edge.From, edge.Cost);
                edgeList[digraphEdge.From].Add(digraphEdge);
            }
        }

        public void SetEdgeCost(int from, int to, double cost)
        {
            foreach (var edge in edgeList[from])
            {
                if (edge.To == to)
                {
                    edge.Cost = cost;
                    foreach (var edge2 in edgeList[to])
                    {
                        if (edge2.To == from)
                        {
                            edge2.Cost = cost;
                        }
                    }
                }
            }
        }

        public int Count()
        {
            return nodeList.Count();
        }

        public bool isEmpty()
        {
            return !nodeList.Any();
        }

	    public bool EdgeExists(int from, int to)
        {
            foreach (var edge in edgeList[from])
            {
                if (edge.To == to) return true;
            }
            return false;
        }

        public void Clear()
        {
            nextNodeIndex = 0;
            nodeList = new List<Node<TModel>>();
            edgeList = new Dictionary<int,IList<Edge>>();
        }
    }
}
