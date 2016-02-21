namespace PathFinder.Graph
{
    public class Edge
    {
        public int From { get; set; }
        public int To { get; set; }
        public double Cost { get; set; }

        public Edge(int from, int to)
        {
            this.From = from;
            this.To = to;
            this.Cost = 1.0;
        }
        public Edge(int from, int to,double cost)
        {
            this.From = from;
            this.To = to;
            this.Cost = cost;
        }

        public override bool Equals(object obj)
        {
            if (obj == null) return false;
            var otherEdge = (Edge)obj;

            return (object)otherEdge!=null && this.From == otherEdge.From && this.To == otherEdge.To && this.Cost == otherEdge.Cost;
        }
        public bool Equals(Edge edge)
        {
            return (object)edge!=null && this.From == edge.From && this.To == edge.To && this.Cost == edge.Cost;
        }

        public override int GetHashCode()
        {
            return (this.From.GetHashCode()*7*3)+(this.To.GetHashCode()*7*2)+(this.Cost.GetHashCode()*7);
        }

        public static bool operator==(Edge a, Edge b)
        {
            if (ReferenceEquals(a, b))
            {
                return true;
            }
            if((object)a==null || (object)b == null)
            {
                return false;
            }
            return a.From == b.From && a.To == b.To && a.Cost == b.Cost;
        }
        public static bool operator !=(Edge a, Edge b)
        {
            return !(a == b);
        }
    }
}
