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
    
    addEventListener(UIEventType::SizeChange, CC_CALLBACK_1(DefaultListFooter::onSizeChanged, this));
}

void DefaultListFooter::onSizeChanged(EventContext*)
{
    if (_c1->getSelectedIndex() == 2 || _c1->getSelectedIndex() == 3)
        return;
    
    if (getHeight() > sourceSize.height)
        _c1->setSelectedIndex(1);
    else
        _c1->setSelectedIndex(0);
}

void DefaultListFooter::setRefreshStatus(int value)
{
    _c1->setSelectedIndex(value);
}

NS_FGUI_END
