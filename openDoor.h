#ifndef __OPEN_DOOR_H__
#define __OPEN_DOOR_H__

#include <behaviortree_cpp_v3/behavior_tree.h>

class OpenDoorAction : public BT::StatefulActionNode
{
public:
  OpenDoorAction(const std::string& name);

  BT::NodeStatus onStart();
  BT::NodeStatus onRunning();
  void onHalted();
};

#endif // __OPEN_DOOR_H__