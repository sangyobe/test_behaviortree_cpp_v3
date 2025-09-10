#include "moveTo.h"
#include <iostream>

MoveToAction::MoveToAction(const std::string& name, const BT::NodeConfiguration& config) 
: BT::StatefulActionNode(name, config)
{}

BT::PortsList MoveToAction::providedPorts()
{
    return {BT::InputPort<std::string>("poi")};
}

BT::NodeStatus MoveToAction::onStart()
{
    std::cout << "MoveToAction: " << this->name() << std::endl;

    BT::Optional<std::string> poi = this->getInput<std::string>("poi");
    if(!poi)
    {
        throw BT::RuntimeError("missing required input [poi]:", poi.error());
    }

    std::cout << " target poi is " << poi.value() << std::endl;
    
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus MoveToAction::onRunning()
{
    std::cout << " target reached." << std::endl;

    return BT::NodeStatus::SUCCESS;
}

void MoveToAction::onHalted()
{
    
}