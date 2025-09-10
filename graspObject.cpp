#include "graspObject.h"
#include <iostream>

GraspObjectAction::GraspObjectAction(const std::string& name, const BT::NodeConfiguration& config) 
: BT::StatefulActionNode(name, config)
{}

BT::PortsList GraspObjectAction::providedPorts()
{
    return {
        BT::InputPort<std::string>("hand"),
        BT::InputPort<std::string>("object")
    };
}

BT::NodeStatus GraspObjectAction::onStart()
{
    std::cout << "GraspObjectAction: " << this->name() << std::endl;

    BT::Optional<std::string> hand = this->getInput<std::string>("hand");
    BT::Optional<std::string> object = this->getInput<std::string>("object");
    if(!hand)
    {
        throw BT::RuntimeError("missing required input [hand]:", hand.error());
    }
    if(!object)
    {
        throw BT::RuntimeError("missing required input [object]:", object.error());
    }

    std::cout << " grasp object, " << object.value() << ", with " << hand.value() << " hand" << std::endl;
    
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus GraspObjectAction::onRunning()
{
    std::cout << " object grasped." << std::endl;

    return BT::NodeStatus::SUCCESS;
}

void GraspObjectAction::onHalted()
{
    
}