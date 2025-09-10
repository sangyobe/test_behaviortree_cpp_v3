#ifndef __SIMPLE_MOTION_H__
#define __SIMPLE_MOTION_H__

#include <behaviortree_cpp_v3/behavior_tree.h>

class SimpleMotionAction : public BT::StatefulActionNode
{
public:
  SimpleMotionAction(const std::string& name, const BT::NodeConfiguration& config);

  static BT::PortsList providedPorts();

  BT::NodeStatus onStart();
  BT::NodeStatus onRunning();
  void onHalted();
};

#endif // __SIMPLE_MOTION_H__