#ifndef __IS_DOOR_OPEN_H__
#define __IS_DOOR_OPEN_H__

#include <behaviortree_cpp_v3/behavior_tree.h>

class IsDoorOpenAction : public BT::SyncActionNode
{
public:
  IsDoorOpenAction(const std::string& name);

  BT::NodeStatus tick() override;
};

#endif // __IS_DOOR_OPEN_H__