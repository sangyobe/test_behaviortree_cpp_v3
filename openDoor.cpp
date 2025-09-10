#include "openDoor.h"
#include <iostream>

OpenDoorAction::OpenDoorAction(const std::string& name) 
: BT::StatefulActionNode(name, {})
{}

BT::NodeStatus OpenDoorAction::onStart()
{
    std::cout << "OpenDoorAction: " << this->name() << std::endl;
   
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus OpenDoorAction::onRunning()
{
    std::cout << " door opened." << std::endl;

    return BT::NodeStatus::SUCCESS;
}

void OpenDoorAction::onHalted()
{
    
}