#ifndef __MOVE_TO_H__
#define __MOVE_TO_H__

#include <behaviortree_cpp_v3/behavior_tree.h>

class MoveToAction : public BT::StatefulActionNode
{
public:
  MoveToAction(const std::string& name, const BT::NodeConfiguration& config);

  static BT::PortsList providedPorts();

  BT::NodeStatus onStart();
  BT::NodeStatus onRunning();
  void onHalted();
};

#endif // __MOVE_TO_H__