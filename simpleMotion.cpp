#include "simpleMotion.h"
#include <iostream>

SimpleMotionAction::SimpleMotionAction(const std::string& name, const BT::NodeConfiguration& config) 
: BT::StatefulActionNode(name, config)
{}

BT::PortsList SimpleMotionAction::providedPorts()
{
    return {
        BT::InputPort<std::string>("motion")
    };
}

BT::NodeStatus SimpleMotionAction::onStart()
{
    std::cout << "SimpleMotionAction: " << this->name() << std::endl;

    BT::Optional<std::string> motion = this->getInput<std::string>("motion");
    if(!motion)
    {
        throw BT::RuntimeError("missing required input [motion]:", motion.error());
    }

    std::cout << " target motion: " << motion.value() << std::endl;

    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus SimpleMotionAction::onRunning()
{
    std::cout << " motion finished." << std::endl;

    return BT::NodeStatus::SUCCESS;
}

void SimpleMotionAction::onHalted()
{
    
}