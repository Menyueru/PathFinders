#ifndef NODE
#define NODE
#include "Vector2D.h"
class Node{
protected:
	int index;
public:
	Node() :index(-1){}
	Node(int i) :index(i){}
	virtual ~Node(){}
	int Index()const{ return index; }
	void SetIndex(int id){ index = id; }
};

class NavNode : public Node
{
protected:
	Vector2D position;
public:
	NavNode(int id, Vector2D pos) :Node(id), position(pos){}

	virtual ~NavNode(){}

	Vector2D Pos()const{ return position; }
	void SetPos(Vector2D NewPosition){ position = NewPosition; }
};
#endif