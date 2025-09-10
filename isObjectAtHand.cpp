#include "isObjectAtHand.h"
#include <iostream>

IsObjectAtHandAction::IsObjectAtHandAction(const std::string& name, const BT::NodeConfiguration& config) 
: BT::SyncActionNode(name, config)
{}

BT::PortsList IsObjectAtHandAction::providedPorts()
{
    return {
        BT::InputPort<std::string>("hand")
    };
}

BT::NodeStatus IsObjectAtHandAction::tick()
{
    std::cout << "IsObjectAtHandAction: " << this->name() << std::endl;

    BT::Optional<std::string> hand = this->getInput<std::string>("hand");
    if(!hand)
    {
        throw BT::RuntimeError("missing required input [hand]:", hand.error());
    }

    std::cout << " is object at " << hand.value() << " hand" << std::endl;

    return BT::NodeStatus::SUCCESS;
}