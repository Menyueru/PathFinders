namespace PathFinder.Graph
{
    public class Node<TModel>
    {
        public int Index { get; set; }
        public TModel Value { get; set; }
        public Node()
        {
            this.Index = -1;
        }
        public Node(int index)
        {
            this.Index = index;
        }

        public Node(int index, TModel value)
        {
            this.Index = index;
            this.Value = value;
        }
    }
}
