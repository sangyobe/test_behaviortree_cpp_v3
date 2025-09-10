#ifndef __GRASP_OBJECT_H__
#define __GRASP_OBJECT_H__

#include <behaviortree_cpp_v3/behavior_tree.h>

class GraspObjectAction : public BT::StatefulActionNode
{
public:
  GraspObjectAction(const std::string& name, const BT::NodeConfiguration& config);

  static BT::PortsList providedPorts();

  BT::NodeStatus onStart();
  BT::NodeStatus onRunning();
  void onHalted();
};

#endif // __GRASP_OBJECT_H__