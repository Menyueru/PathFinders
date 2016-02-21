#ifndef EDGE
#define EDGE
class Edge{
protected:
	int from;
	int to;
	double cost;
public:
	Edge(int f, int t, double c) :from(f), to(t), cost(c){}
	Edge(int f, int t) :from(f), to(t), cost(1.0){}

	virtual ~Edge(){}

	int   From()const{ return from; }
	void  SetFrom(int NewIndex){ from = NewIndex; }

	int   To()const{ return to; }
	void  SetTo(int NewIndex){ to = NewIndex; }

	double Cost()const{ return cost; }
	void  SetCost(double NewCost){ cost = NewCost; }

	bool operator==(const Edge& rhs)
	{
		return rhs.from == this->from &&
			rhs.to == this->to   &&
			rhs.cost == this->cost;
	}

	bool operator!=(const Edge& rhs)
	{
		return !(*this == rhs);
	}
};
#endif