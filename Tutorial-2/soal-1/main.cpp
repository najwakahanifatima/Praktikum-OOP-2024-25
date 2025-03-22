#include "Agent.hpp"
#include "SuperAgent.hpp"

void setAgentID(int id, Agent* sa){
    sa->setID(id);
}

void setAID(Agent sa){
    sa.setID(1337);
}

int main() {
    SuperAgent agentX;
    
    agentX.setID(9999);
    setAID(agentX);
    // agentX.Agent::setID(1337);
    // setAgentID(1337, &agentX);

    agentX.print();
    return 0;
}