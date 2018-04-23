#include "EulerGraph.h"

EulerGraph::EulerGraph(std::string filename)
{
	std::cout << "Generating the graph for " << filename << std::endl;
	m_filename = filename;	//the filename is now hardcoded in the EulerGraph object
}

void EulerGraph::computeTour(std::ostream & passFout)
{

}