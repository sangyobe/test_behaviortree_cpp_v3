#include "throwObject.h"
#include <iostream>

ThrowObjectAction::ThrowObjectAction(const std::string& name, const BT::NodeConfiguration& config) 
: BT::StatefulActionNode(name, config)
{}

BT::PortsList ThrowObjectAction::providedPorts()
{
    return {
        BT::InputPort<std::string>("hand")
    };
}

BT::NodeStatus ThrowObjectAction::onStart()
{
    std::cout << "ThrowObjectAction: " << this->name() << std::endl;

    BT::Optional<std::string> hand = this->getInput<std::string>("hand");
    if(!hand)
    {
        throw BT::RuntimeError("missing required input [hand]:", hand.error());
    }

    std::cout << " throw object with "<< hand.value() << " hand" << std::endl;

    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus ThrowObjectAction::onRunning()
{
    std::cout << " hand switched." << std::endl;

    return BT::NodeStatus::SUCCESS;
}

void ThrowObjectAction::onHalted()
{
    
}