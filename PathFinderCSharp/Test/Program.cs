using PathFinder;
using PathFinder.Graph;
using System;
using Test.Heuristics;

namespace Test
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var graph = new Graph<Vector2D>();
            graph.AddNode(new Node<Vector2D>(graph.GetNextFreeNodeIndex(), new Vector2D(1, 2)));
            graph.AddNode(new Node<Vector2D>(graph.GetNextFreeNodeIndex(), new Vector2D(0, 0)));
            graph.AddNode(new Node<Vector2D>(graph.GetNextFreeNodeIndex(), new Vector2D(3, 3)));
            graph.AddNode(new Node<Vector2D>(graph.GetNextFreeNodeIndex(), new Vector2D(1, 0)));
            graph.AddNode(new Node<Vector2D>(graph.GetNextFreeNodeIndex(), new Vector2D(5, 1)));

            graph.AddEdge(new Edge(0, 2));
            graph.AddEdge(new Edge(0, 1));
            graph.AddEdge(new Edge(2, 3));
            graph.AddEdge(new Edge(3, 4));
            graph.AddEdge(new Edge(1, 4));
            graph.AddEdge(new Edge(2, 3));

            var search= new AStar<Vector2D>(graph, 0, 4,new EuclideanSquaredHeuristic());
            var path = search.GetPathToTarget();
            foreach (var index in path)
            {
                var nextNode = graph.GetNode(index);

                Console.WriteLine("Moving to: " + nextNode.Index + " in position " + nextNode.Value.X + " " + nextNode.Value.Y);
            }

            Console.ReadKey();
        }
    }
}
