#include "isDoorOpen.h"
#include <iostream>

IsDoorOpenAction::IsDoorOpenAction(const std::string& name) 
: BT::SyncActionNode(name, {})
{}

BT::NodeStatus IsDoorOpenAction::tick()
{
    std::cout << "IsDoorOpenAction: " << this->name() << std::endl;

    return BT::NodeStatus::FAILURE;
}