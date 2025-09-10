#include "switchHands.h"
#include <iostream>

SwitchHandsAction::SwitchHandsAction(const std::string& name) 
: BT::StatefulActionNode(name, {})
{}

BT::NodeStatus SwitchHandsAction::onStart()
{
    std::cout << "SwitchHandsAction: " << this->name() << std::endl;

    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus SwitchHandsAction::onRunning()
{
    std::cout << " hand switched." << std::endl;

    return BT::NodeStatus::SUCCESS;
}

void SwitchHandsAction::onHalted()
{
    
}