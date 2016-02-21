using PathFinder.Graph;
using PathFinder.Heuristics;


namespace Test.Heuristics
{
    public class NoHeuristic : IHeuristic<Vector2D>
    {
        public double Calculate(Graph<Vector2D> graph, int from, int to)
        {
            return 0;
        }
    }
}
