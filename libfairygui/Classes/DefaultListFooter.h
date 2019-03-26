//
//  DefaultListFooter.hpp
//  GFProject
//
//  Created by liumin on 3/25/19.
//

#ifndef DefaultListFooter_hpp
#define DefaultListFooter_hpp

#include "cocos2d.h"
#include "FairyGUIMacros.h"
#include "GComponent.h"

NS_FGUI_BEGIN

class DefaultListFooter : public GComponent
{
public:
    CREATE_FUNC(DefaultListFooter);
    
    bool isReadyToRefresh()
    {
        return _c1->getSelectedIndex() == 1;
    }
    void setRefreshStatus(int value);
protected:
    virtual void onConstruct();
private:
    void onSizeChanged(EventContext*);
    
    GController* _c1;
};


NS_FGUI_END

#endif /* DefaultListFooter_hpp */
