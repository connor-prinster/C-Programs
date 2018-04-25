#include <sstream>
#include <assert.h>
using namespace std;

class Edge
{  
public:
     int m_toNode;  // Subscript of one endpoint in node array.  Nodes are stored as numbers, but printed as characters.
	 int m_fromNode; // Subscript of other endpoint in node array
	 int m_cycleID;  // Cycle which the edge is a member of, -1 if it is included in no cycle
	 bool m_containedInCycle;    // true if edge is in a cycle
	 bool m_used;

   // Create a string version of Edge
   // Edge endpoints are stored as numbers, but printed as characters.
	 Edge(char originNode, char endNode)
	 {
		 set(originNode, endNode);
	 }
	 string toString()
	 {
		 ostringstream os;  // allows string to act like stream to use stream operations
		 char t = m_toNode + 'A';
		 char f = m_fromNode + 'A';
		 os << "   " << f << "-" << t << "(" << m_cycleID << ")";
		 return os.str();
	 }

	 // if oneNode is an endpoint, return other endpoint
	 int getOtherEndpoint(int oneNode)
	 {
		 if (m_fromNode == oneNode) return m_toNode;
		 assert(m_toNode == oneNode);
		 return m_fromNode;
	 }

	 // Set initial values of an edge from Node f to Node t
	 void set(char f, char t)
	 {
		 m_fromNode = f - 'A';
		 m_toNode = t - 'A';
		 m_cycleID = -1;
		 m_containedInCycle = false;
		 //cout << "creating Edge " << toString()<<endl;
	 }
};