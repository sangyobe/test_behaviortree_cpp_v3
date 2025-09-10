#include <iostream>
#include <behaviortree_cpp_v3/behavior_tree.h>
#include <behaviortree_cpp_v3/bt_factory.h>
#include "moveTo.h"
#include "graspObject.h"
#include "openDoor.h"
#include "switchHands.h"
#include "throwObject.h"
#include "isDoorOpen.h"
#include "isObjectAtHand.h"
#include "simpleMotion.h"
#include <string>
#include <sstream>

int main()
{
    BT::BehaviorTreeFactory factory;

    factory.registerNodeType<MoveToAction>("MoveTo");
    factory.registerNodeType<GraspObjectAction>("GraspObject");
    factory.registerNodeType<OpenDoorAction>("OpenDoor");
    factory.registerNodeType<SwitchHandsAction>("SwitchHands");
    factory.registerNodeType<ThrowObjectAction>("ThrowObject");
    factory.registerNodeType<SimpleMotionAction>("Motion");
    factory.registerNodeType<IsDoorOpenAction>("IsDoorOpen");
    factory.registerNodeType<IsObjectAtHandAction>("IsObjectAtHand");


    factory.registerBehaviorTreeFromFile("./PonyKA.xml");
    auto tree = factory.createTree("Demo");
    BT::printTreeRecursively(tree.rootNode());
    tree.tickRootWhileRunning();

    return 0;
}