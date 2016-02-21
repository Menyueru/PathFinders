using PathFinder.Graph;

namespace PathFinder.Heuristics
{
    public interface IHeuristic<TModel> 
    {
        double Calculate(Graph<TModel> graph,int from, int to);
    }
}
