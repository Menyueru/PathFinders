using PathFinder.DataStructures;
using PathFinder.Graph;
using PathFinder.Heuristics;
using System.Collections.Generic;

namespace PathFinder
{
    public class AStar<TModel>
    {
        private Graph<TModel> graph;
        private double[] gCosts;
        private double[] fCosts;
        public Edge[] ShortestPathTree { get; private set; }
        private Edge[] searchEdges;
        private int source, target;

        public AStar(Graph<TModel> graph, int source, int target,IHeuristic<TModel> heuristic)
        {
            this.graph = graph;
            this.ShortestPathTree = new Edge[graph.Count()];
            this.searchEdges = new Edge[graph.Count()];
            this.gCosts = new double[graph.Count()];
            this.fCosts = new double[graph.Count()];
            this.source = source;
            this.target = target;
            this.Search(heuristic);
        }

        private void Search(IHeuristic<TModel> heuristic)
        {
            var queue = new MinIndexedPriorityQueue<double>(fCosts, graph.Count());
            queue.Insert(source);
            while (!queue.IsEmpty())
            {
                int nextClosestNode = queue.Pop();

                ShortestPathTree[nextClosestNode] = searchEdges[nextClosestNode];

                if (nextClosestNode == target) return;

                foreach (var edge in graph.GetEdgeListFrom(nextClosestNode))
                {
                    double HCost = heuristic.Calculate(graph, target, edge.To);

                    double GCost = gCosts[nextClosestNode] + edge.Cost;

                    if (searchEdges[edge.To] == null)
                    {
                        fCosts[edge.To] = GCost + HCost;
                        gCosts[edge.To] = GCost;

                        queue.Insert(edge.To);

                        searchEdges[edge.To] = edge;
                    }
                    else if ((GCost < gCosts[edge.To]) && (ShortestPathTree[edge.To] == null))
                    {
                        fCosts[edge.To] = GCost + HCost;
                        gCosts[edge.To] = GCost;

                        queue.ChangePriority(edge.To);

                        searchEdges[edge.To] = edge;
                    }
                }
            }
        }

        public double GetCostToTarget()
        {
            return gCosts[target];
        }

        public List<int> GetPathToTarget()
        {
            var path = new List<int>();
            if (target < 0) return path;
            int nextIndex = target;
            path.Add(nextIndex);

            while ((nextIndex != source) && (ShortestPathTree[nextIndex] != null))
            {
                nextIndex = ShortestPathTree[nextIndex].From;

                path.Add(nextIndex);
            }
            path.Reverse();
            return path;
        }
    }
}
