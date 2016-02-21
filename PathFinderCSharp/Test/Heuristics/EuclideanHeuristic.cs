using PathFinder.Heuristics;
using PathFinder.Graph;

namespace Test.Heuristics
{
    public class EuclideanHeuristic : IHeuristic<Vector2D>
    {
        public double Calculate(Graph<Vector2D> graph, int from, int to)
        {
            return graph.GetNode(from).Value.DistanceTo(graph.GetNode(to).Value);
        }
    }
}
