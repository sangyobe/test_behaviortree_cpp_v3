#ifndef __THROW_OBJECT_H__
#define __THROW_OBJECT_H__

#include <behaviortree_cpp_v3/behavior_tree.h>

class ThrowObjectAction : public BT::StatefulActionNode
{
public:
  ThrowObjectAction(const std::string& name, const BT::NodeConfiguration& config);

  static BT::PortsList providedPorts();

  BT::NodeStatus onStart();
  BT::NodeStatus onRunning();
  void onHalted();
};

#endif // __THROW_OBJECT_H__