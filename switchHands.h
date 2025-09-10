#ifndef __SWITCH_HANDS_H__
#define __SWITCH_HANDS_H__

#include <behaviortree_cpp_v3/behavior_tree.h>

class SwitchHandsAction : public BT::StatefulActionNode
{
public:
  SwitchHandsAction(const std::string& name);

  BT::NodeStatus onStart();
  BT::NodeStatus onRunning();
  void onHalted();
};

#endif // __SWITCH_HANDS_H__