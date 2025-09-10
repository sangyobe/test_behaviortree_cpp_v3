#ifndef __IS_OBJECT_AT_HAND_H__
#define __IS_OBJECT_AT_HAND_H__

#include <behaviortree_cpp_v3/behavior_tree.h>

class IsObjectAtHandAction : public BT::SyncActionNode
{
public:
  IsObjectAtHandAction(const std::string& name, const BT::NodeConfiguration& config);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;
};

#endif // __IS_OBJECT_AT_HAND_H__