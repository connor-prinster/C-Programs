#include "Node.h"

Node::Node(std::string nodeTitle)
{
	this->title = nodeTitle;
	this->titleInt = std::stoi(nodeTitle);
	this->numberOfConnectionsIn = 0;
	this->numberOfConnectionsOut = 0;
}