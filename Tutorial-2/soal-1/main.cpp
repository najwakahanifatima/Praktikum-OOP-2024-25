#include "Agent.hpp"
#include "SuperAgent.hpp"

void setAgentID(int id, Agent* sa){
    sa->setID(id);
}

int main() {
    SuperAgent agentX;

    agentX.setID(9999);
    setAgentID(1337, &agentX);

    agentX.print();
    return 0;
}