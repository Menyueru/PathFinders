using PathFinder.Graph;
using PathFinder.Heuristics;
using System;

namespace Test.Heuristics
{
    public class ManhattanHeuristic : IHeuristic<Vector2D>
    {
        public double Calculate(Graph<Vector2D> graph, int from, int to)
        {
            return Math.Abs(graph.GetNode(from).Value.X - graph.GetNode(to).Value.X) + Math.Abs(graph.GetNode(from).Value.Y - graph.GetNode(to).Value.Y);
        }
    }
}
