//
//  DefaultListFooter.cpp
//  GFProject
//
//  Created by liumin on 3/25/19.
//

#include "DefaultListFooter.h"

NS_FGUI_BEGIN

void DefaultListFooter::onConstruct()
{
    _c1 = getController("c1");
    
    _pull = ((GComponent*)getChild("n0"))->getTransition("t0");
    _release = ((GComponent*)getChild("n1"))->getTransition("t0");
    _loading = ((GComponent*)getChild("n2"))->getTransition("t0");
    _over = ((GComponent*)getChild("n3"))->getTransition("t0");
    
    addEventListener(UIEventType::SizeChange, CC_CALLBACK_1(DefaultListFooter::onSizeChanged, this));
}

void DefaultListFooter::onSizeChanged(EventContext*)
{
    if (_c1->getSelectedIndex() == 2 || _c1->getSelectedIndex() == 3)
        return;
    
    if (getHeight() > sourceSize.height)
        this->setRefreshStatus(1);
    else
        this->setRefreshStatus(0);
}

void DefaultListFooter::setRefreshStatus(int value)
{
    _c1->setSelectedIndex(value);
    
    if (value == 0) {
        _pull->play();
    } else if (value == 1) {
        _release->play();
    } else if (value == 2) {
        _loading->play();
    } else if (value == 3) {
        _over->play();
    }
}

NS_FGUI_END
