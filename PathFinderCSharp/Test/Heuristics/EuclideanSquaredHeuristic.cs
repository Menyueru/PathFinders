using PathFinder.Graph;
using PathFinder.Heuristics;

namespace Test.Heuristics
{
    public class EuclideanSquaredHeuristic : IHeuristic<Vector2D>
    {
        public double Calculate(Graph<Vector2D> graph, int from, int to)
        {
            return graph.GetNode(from).Value.DistanceToSquared(graph.GetNode(to).Value);
        }
    }
}
